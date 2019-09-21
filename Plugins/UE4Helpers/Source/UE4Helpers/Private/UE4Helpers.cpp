// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UE4Helpers.h"
#include "Engine.h"
#include <Engine/EngineBaseTypes.h>
#include <Engine/EngineTypes.h>
#include <Camera/PlayerCameraManager.h>
#include <MessageLog.h>
#include <UObjectToken.h>
#include <IAssetRegistry.h>
#include <Engine/AssetManager.h>
#include <KismetEditorUtilities.h>

void FUE4HelpersModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FUE4HelpersModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

UE4CodeHelpers::UE4CodeHelpers(const FObjectInitializer& ObjInit) : Super(ObjInit)
{

}

static TAutoConsoleVariable<int32> CVarShowBarabolicTrajectoryCalculationDebugLine(TEXT("UE4CodeHelpers.ShowBarabolicTrajectoryCalculationDebugs"),
	0,
	TEXT("Show barabolic trajectory calculation debugs."));

#define LOCTEXT_NAMESPACE "UE4CodeHelpers"

FString UE4CodeHelpers::GetNetModePrefix(const UObject* WorldContextObject)
{
	FString netModePrefix = GetNetModeName(WorldContextObject);
	return netModePrefix.IsEmpty() ? TEXT("") : FString::Printf(TEXT("%s: "), *netModePrefix);
}

bool UE4CodeHelpers::IsOfType(const UObject* object, TSubclassOf<UObject> type)
{
	return object->IsA(type);
}

TArray<FVector> UE4CodeHelpers::CalculateBarabolicTrajectory(const FVector& startLocation, const FVector& velocity, const FVector& gravity, const float samplingResolutionCoefficient, const int32 numberOfTrajectoryPoints, const UObject* WorldContextObject)
{
	TArray<FVector> trajectoryPathPoints;

	for (int x = 0; x < numberOfTrajectoryPoints; x++)
	{
		float time = x * samplingResolutionCoefficient;
		FVector tempPoint = startLocation + FVector(velocity * time);
		FVector offset = (gravity * time * time);
		tempPoint = tempPoint + offset;
		trajectoryPathPoints.Add(tempPoint);

		if (CVarShowBarabolicTrajectoryCalculationDebugLine.GetValueOnGameThread() == 1)
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

FString UE4CodeHelpers::GetFileLine(const FString& InFileName, const FString& Folder, const FString& ConfigName)
{
	TArray<FString> rows;
	FString filePath = FString(FPaths::ProjectDir()).Append(Folder).Append(InFileName);
	bool foundSomething = FFileHelper::LoadFileToStringArray(rows, *filePath);

	if (foundSomething)
	{
		UE_LOG(LogTemp, Log, TEXT("Found a file with the name (%s). Processing words to locate the setting for configuration (%s)."), *InFileName, *ConfigName);

		for (auto & row : rows)
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

				UE_LOG(LogTemp, Log, TEXT("Configuration (%s) found with the value of (%s)"), *ConfigName, *valueFound);
				return parsedLine[parsedArrayLength - 1];
			}
		}
		UE_LOG(LogTemp, Error, TEXT("No line (%s) was found´in the config file (%s)."), *ConfigName, *InFileName);

		return FString(TEXT(""));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Did not find a file named (%s)."), *InFileName);
		FMessageLog("PIE").Error(FText::Format(LOCTEXT("COVBlueprintFunctionLibrary", "Could not find a file named ({0})."), FText::FromString(InFileName)));
		return FString(TEXT(""));
	}
}

FString UE4CodeHelpers::GetConfigFileLine(const FString& InFileName, const FString& ConfigName)
{
	return GetFileLine(InFileName, FString(TEXT("/Config/")), ConfigName);
}

int32 UE4CodeHelpers::GetNumberOfRowsInFile(const FString& InFileName, const FString& Folder)
{
	int32 rowCount;
	TArray<FString> rows;
	FString filePath = FString(FPaths::ProjectDir()).Append(Folder).Append(InFileName);
	bool foundSomething = FFileHelper::LoadANSITextFileToStrings(*filePath, NULL, rows);

	if (foundSomething)
	{
		rowCount = rows.Num();
		UE_LOG(LogTemp, Log, TEXT("Found a number of (%d) rows in the file (%s)."), rowCount, *InFileName);
		return rowCount;
	}

	UE_LOG(LogTemp, Error, TEXT("Could not read the number of lines in a file (%s). No file found!"), *InFileName);
	FMessageLog("PIE").Error(FText::Format(LOCTEXT("UE4CodeHelpers", "Could not read the number of lines in a file ({0}). No file found!."), FText::FromString(InFileName)));

	return -1;
}

int32 UE4CodeHelpers::GetRepositoryCommitCount()
{
	int32 numberOfCommits = (int32)GetNumberOfRowsInFile(FString(TEXT("HEAD")), FString(TEXT("/.git/logs/")));

	if (numberOfCommits == -1)
	{
		UE_LOG(LogTemp, Error, TEXT("No git repository folder found. Could not find the number of commits."));
		FMessageLog("PIE").Error(FText::FromString("No git repository folder found. Could not find the number of commits."));
		return -1;
	}

	return numberOfCommits;
}

APlayerCameraManager* UE4CodeHelpers::TryGetPawnCameraManager(const APawn* pawn)
{
	if (!ensureMsgf(IsValid(pawn), TEXT("The pawn wasn't valid anymore.")))
	{
		FMessageLog("PIE").Error(FText::FromString("Could not get pawn camera manager. Pawn wasn't valid."));
		return nullptr;
	}
	AController* temp = pawn->GetController();
	APlayerController* playerController = Cast<APlayerController>(pawn->GetController());

	if (!IsValid(playerController))
	{
		//FMessageLog("PIE").Error(FText::FromString("Could not get pawn camera manager. The pawn's controller was not valid."))->AddToken(FUObjectToken::Create(pawn));
		return nullptr;
	}


	if (!ensureMsgf(IsValid(playerController->PlayerCameraManager), TEXT("The player camera manager was not valid.")))
	{
		FMessageLog("PIE").Error(FText::FromString("Could not get pawn camera manager. The camera manager was not valid for pawn."))->AddToken(FUObjectToken::Create(pawn));
		return nullptr;
	}

	return playerController->PlayerCameraManager;
}

FString UE4CodeHelpers::GetNetModeName(const UObject* worldContextObject)
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

FRotator UE4CodeHelpers::OrientRotationToNormalVector(const FRotator& CurrentRotation, const FVector& Normal)
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

TArray<UClass*> UE4CodeHelpers::GetAllAssetsOfType(TSubclassOf<AActor> type, const FString& pathToSearchFor, const FAsyncChildClassLoadSignature& delegate)
{
	// Load asset registry module
	FAssetRegistryModule& AssetRegistryModule_ = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(FName("AssetRegistry"));
	IAssetRegistry& AssetRegistry = AssetRegistryModule_.Get();

	//	Get streamable manager for the asynchronous loading phase
	FStreamableManager& streamable = UAssetManager::GetStreamableManager();

	// Scan specific path
	TArray<FString> PathsToScan;
	PathsToScan.Add(pathToSearchFor);
	AssetRegistry.ScanPathsSynchronous(PathsToScan);

	// Get all assets in the path, does not load them
	TArray<FAssetData> assetsInThePath;
	AssetRegistry.GetAssetsByPath(FName(*pathToSearchFor), assetsInThePath, /*bRecursive=*/true);

	// Ensure all assets are loaded and store their class
	TArray<UClass*> ClassesOfType;

	for (const FAssetData& Asset : assetsInThePath)
	{
		//	If asset is not loaded, load it asynchronously
		if (!Asset.IsAssetLoaded())
		{
			FSoftObjectPath softPathOfAsset = Asset.ToSoftObjectPath();

			TSharedPtr<FStreamableHandle> handle;
			handle = streamable.RequestAsyncLoad(softPathOfAsset, [delegate, Asset, type]()
			{
				// Skip non blueprint assets
				const UBlueprint* BlueprintObj = Cast<UBlueprint>(Asset.FastGetAsset(false));
				if (!BlueprintObj)
					return;

				// Check whether blueprint class has parent class we're looking for
				UClass* BlueprintClass = BlueprintObj->GeneratedClass;
				if (!BlueprintClass || !BlueprintClass->IsChildOf(type))
					return;

				delegate.ExecuteIfBound(BlueprintClass);
			}, 0, false, false);
		}
		else
		{
			// Skip non blueprint assets
			const UBlueprint* BlueprintObj = Cast<UBlueprint>(Asset.FastGetAsset(false));
			if (!BlueprintObj)
				continue;

			// Check whether blueprint class has parent class we're looking for
			UClass* BlueprintClass = BlueprintObj->GeneratedClass;
			if (!BlueprintClass || !BlueprintClass->IsChildOf(type))
				continue;

			// Store class
			ClassesOfType.Add(BlueprintClass);
		}

		//	DEPRECATED CODE FOR ALL ASSETS NOT MADE IN BLUEPRINTS
		/*
		//	If asset is not loaded, load it asynchronously
		if (!Asset.IsAssetLoaded())
		{
			FSoftObjectPath softPath = Asset.ToSoftObjectPath();
			TSharedPtr<FStreamableHandle> handle;

			handle = streamable.RequestAsyncLoad(softPath, [delegate, Asset, type]()
			{
				UObject* object = Asset.FastGetAsset(false);
				UClass* classObject = object->GetClass();

				if (!IsValid(classObject) || !classObject->IsChildOf(type))
					return;

				delegate.ExecuteIfBound(classObject);
			}, 0, false, false);
		}
		else
		{
			UObject* object = Asset.FastGetAsset(false);
			UClass* classObject = object->GetClass();

			if (!IsValid(classObject) || !classObject->IsChildOf(type))
				continue;

			// Store class
			ClassesOfType.Add(classObject);
		}
		*/
	}

	return ClassesOfType;
}

TArray<UClass*> UE4CodeHelpers::GetAllLoadedChildClassesOfType(TSubclassOf<AActor> type)
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

bool UE4CodeHelpers::GenericIsArrayEmpty(void* targetArray, const UArrayProperty* arrayProp)
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
}

IMPLEMENT_MODULE(FUE4HelpersModule, UE4Helpers)