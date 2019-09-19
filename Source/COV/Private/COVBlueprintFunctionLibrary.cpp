// Fill out your copyright notice in the Description page of Project Settings.

#include "COVBlueprintFunctionLibrary.h"
#include "CollisionQueryParams.h"
#include "Engine.h"
#include "Kismet/KismetMathLibrary.h"
#include <GameFramework/InputSettings.h>
#include <MessageLog.h>
#include <UObjectToken.h>
#include <KismetEditorUtilities.h>

DEFINE_LOG_CATEGORY(COVBlueprintFunctionLibrary)
#define LOCTEXT_NAMESPACE "COVBlueprintFunctionLibrary"

static TAutoConsoleVariable<int32> CVarShowBarabolicTrajectoryCalculationDebugs(TEXT("COV.ShowBarabolicTrajectoryCalculationDebugs"),
	0,
	TEXT("Show barabolic trajectory calculation debugs."));

int32 UCOVBlueprintFunctionLibrary::GetNumberOfRowsInFile(const FString& InFileName, const FString& Folder)
{
	int32 rowCount;
	TArray<FString> rows;
	FString filePath = FString(FPaths::GameDir()).Append(Folder).Append(InFileName);
	bool foundSomething = FFileHelper::LoadANSITextFileToStrings(*filePath, NULL, rows);

	if (foundSomething)
	{
		rowCount = rows.Num();
		UE_LOG(COVBlueprintFunctionLibrary, Log, TEXT("Found a number of (%d) rows in the file (%s)."), rowCount, *InFileName);
		return rowCount;
	}

	UE_LOG(COVBlueprintFunctionLibrary, Error, TEXT("Could not read the number of lines in a file (%s). No file found!"), *InFileName);
	FMessageLog("COVBlueprintFunctionLibrary").Error(FText::Format(LOCTEXT("COVBlueprintFunctionLibrary", "Could not read the number of lines in a file ({0}). No file found!."), FText::FromString(InFileName)));

	return -1;
}

FString UCOVBlueprintFunctionLibrary::GetConfigFileLine(const FString& InFileName, const FString& ConfigName)
{
	return GetFileLine(InFileName, FString(TEXT("/Config/")), ConfigName);
}

FString UCOVBlueprintFunctionLibrary::GetFileLine(const FString& InFileName, const FString& Folder, const FString& ConfigName)
{
	TArray<FString> rows;
	FString filePath = FString(FPaths::GameDir()).Append(Folder).Append(InFileName);
	bool foundSomething = FFileHelper::LoadFileToStringArray(rows, *filePath);

	if (foundSomething)
	{
		UE_LOG(COVBlueprintFunctionLibrary, Log, TEXT("Found a file with the name (%s). Processing words to locate the setting for configuration (%s)."), *InFileName, *ConfigName);

		for(auto & row : rows)
		{
			bool containsString = row.Contains(ConfigName, ESearchCase::IgnoreCase, ESearchDir::FromStart);

			if (containsString)
			{
				TArray<FString> parsedLine;
				row.ParseIntoArray(parsedLine, TEXT("="), true);
				int32 parsedArrayLength = parsedLine.Num();
				FString valueFound = parsedLine[parsedArrayLength - 1];
				//	Remove spaces if any
				valueFound.RemoveFromStart(TEXT(" "));

				UE_LOG(COVBlueprintFunctionLibrary, Log, TEXT("Configuration (%s) found with the value of (%s)"), *ConfigName, *valueFound);
				return parsedLine[parsedArrayLength - 1];
			}
		}
		UE_LOG(COVBlueprintFunctionLibrary, Error, TEXT("No line (%s) was found´in the config file (%s)."), *ConfigName, *InFileName);

		return FString(TEXT(""));
	}
	else
	{
		UE_LOG(COVBlueprintFunctionLibrary, Error, TEXT("Did not find a file named (%s)."), *InFileName);
		FMessageLog("COVBlueprintFunctionLibrary").Error(FText::Format(LOCTEXT("COVBlueprintFunctionLibrary", "Could not find a file named ({0})."), FText::FromString(InFileName)));
		return FString(TEXT(""));
	}
}

int32 UCOVBlueprintFunctionLibrary::GetRepositoryCommitCount()
{
	int32 numberOfCommits = (int32)GetNumberOfRowsInFile(FString(TEXT("HEAD")), FString(TEXT("/.git/logs/")));

	if (numberOfCommits == -1)
	{
		UE_LOG(COVBlueprintFunctionLibrary, Error, TEXT("No git repository folder found. Could not find the number of commits."));
		FMessageLog("COVBlueprintFunctionLibrary").Error(FText::FromString("No git repository folder found. Could not find the number of commits."));
		return -1;
	}

	return numberOfCommits;
}

APlayerCameraManager* UCOVBlueprintFunctionLibrary::TryGetPawnCameraManager(const APawn* pawn)
{
	if (!ensureMsgf(IsValid(pawn), TEXT("The pawn wasn't valid anymore.")))
	{
		FMessageLog("COVBlueprintFunctionLibrary").Error(FText::FromString("Could not get pawn camera manager. Pawn wasn't valid."));
		return nullptr;
	}
	AController* temp = pawn->GetController();
	APlayerController* playerController = Cast<APlayerController>(pawn->GetController());

	if (!ensureMsgf(IsValid(playerController), TEXT("The player controller was not valid for the pawn.")))
	{
		FMessageLog("COVBlueprintFunctionLibrary").Error(FText::FromString("Could not get pawn camera manager. The pawn's controller was not valid."))->AddToken(FUObjectToken::Create(pawn));
		return nullptr;
	}


	if (!ensureMsgf(IsValid(playerController->PlayerCameraManager), TEXT("The player camera manager was not valid.")))
	{
		FMessageLog("COVBlueprintFunctionLibrary").Error(FText::FromString("Could not get pawn camera manager. The camera manager was not valid for pawn."))->AddToken(FUObjectToken::Create(pawn));
		return nullptr;
	}

	return playerController->PlayerCameraManager;
}

FString UCOVBlueprintFunctionLibrary::GetNetModePrefix(const UObject* worldContextObject)
{
	FString netModePrefix = GetNetModeName(worldContextObject);
	return netModePrefix.IsEmpty() ? TEXT("") : FString::Printf(TEXT("%s: "), *netModePrefix);
}

bool UCOVBlueprintFunctionLibrary::IsOfType(const UObject* object, TSubclassOf<UObject> type)
{
	return object->IsA(type);
}

FString UCOVBlueprintFunctionLibrary::GetNetModeName(const UObject* worldContextObject)
{
	FString result;

	if (UWorld* world = GEngine->GetWorldFromContextObject(worldContextObject, EGetWorldErrorMode::ReturnNull))
	{
		// Minus one to match the engine.
		int32 client_id = -1;

#if WITH_EDITOR
		if (world->WorldType == EWorldType::PIE)
		{
			client_id = GPlayInEditorID;

			const TIndirectArray<FWorldContext>& contexts = GEngine->GetWorldContexts();

			for (int32 i = 0, icount = contexts.Num(); i < icount; ++i)
			{
				if (contexts[i].World() == world)
				{
					client_id = contexts[i].PIEInstance;
					break;
				}
			}
		}
#endif

		switch (world->GetNetMode())
		{
		case NM_Client:
			result = FString::Printf(TEXT("Client %d"), client_id - 1);
			break;
		case NM_DedicatedServer:
		case NM_ListenServer:
			result = TEXT("Server");
			break;
		case NM_Standalone:
			break;
		}
	}

	return result;
}

TArray<FVector> UCOVBlueprintFunctionLibrary::CalculateBarabolicTrajectory(const FVector& startLocation, const FVector& velocity, const FVector& gravity, const float samplingResolutionCoefficient, const int32 numberOfTrajectoryPoints, const UObject* WorldContextObject)
{
	TArray<FVector> trajectoryPathPoints;

	for (int x = 0; x < numberOfTrajectoryPoints; x++)
	{
		float time = x * samplingResolutionCoefficient;
		FVector tempPoint = startLocation + FVector(velocity * time);
		FVector offset =  (gravity * time * time);
		tempPoint = tempPoint + offset;
		trajectoryPathPoints.Add(tempPoint);

		if (CVarShowBarabolicTrajectoryCalculationDebugs.GetValueOnGameThread() == 1)
		{
			//	Draw the sample points
			UKismetSystemLibrary::DrawDebugPoint(WorldContextObject->GetWorld(), tempPoint, 10.0f, FLinearColor::Red, 10.0f);

			//	Draw lines between points
			if ((x > 0))
			{
				UKismetSystemLibrary::DrawDebugLine(WorldContextObject->GetWorld(), tempPoint, trajectoryPathPoints[x - 1], FLinearColor::Green, 10.0f, 5.0f);
			}
		}
	}

	return trajectoryPathPoints;
}

FRotator UCOVBlueprintFunctionLibrary::OrientRotationToNormalVector(const FRotator& CurrentRotation, const FVector& Normal)
{
	const FQuat RootQuat = CurrentRotation.Quaternion();
	const FVector UpVector = RootQuat.GetUpVector();
	FVector RotationAxis = FVector::CrossProduct(UpVector, Normal);
	RotationAxis.Normalize();

	const float DotProduct = FVector::DotProduct(UpVector, Normal);
	const float RotationAngle = FMath::Acos(DotProduct);

	const FQuat Quat = FQuat(RotationAxis, RotationAngle);

	const FQuat NewQuat = Quat * RootQuat;

	return NewQuat.Rotator();
}

TArray<UClass*> UCOVBlueprintFunctionLibrary::GetAllChildClassesOfType(TSubclassOf<AActor> type)
{
	TArray<UClass*> SubClasses;

	for (TObjectIterator< UClass > ClassIt; ClassIt; ++ClassIt)
	{
		UClass* Class = *ClassIt;

		// Ignore deprecated
		if (Class->HasAnyClassFlags(CLASS_Deprecated | CLASS_NewerVersionExists))
		{
			continue;
		}

#if WITH_EDITOR
		// Ignore skeleton classes (semi-compiled versions that only exist in-editor)
		if (FKismetEditorUtilities::IsClassABlueprintSkeleton(Class))
		{
			continue;
		}
#endif

		// Check this class is a subclass of Base
		if (!Class->IsChildOf(type))
		{
			continue;
		}

		// Add this class
		SubClasses.Add(Class);
	}

	return SubClasses;
}

bool UCOVBlueprintFunctionLibrary::GenericIsArrayEmpty(void* targetArray, const UArrayProperty* arrayProp)
{
	if (targetArray)
	{
		FScriptArrayHelper arrayHelper(arrayProp, targetArray);

		if (arrayHelper.Num() == 0)
		{
			return true;
		}
	}

	return false;
};
