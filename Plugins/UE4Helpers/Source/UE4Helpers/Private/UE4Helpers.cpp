// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UE4Helpers.h"

#define LOCTEXT_NAMESPACE "FUE4HelpersModule"

void FUE4HelpersModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FUE4HelpersModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

DEFINE_LOG_CATEGORY(LogUE4CodeHelpers)

FHitResult UE4CodeHelpers::SimpleTraceByChannel(UObject* WorldContextObject, const FVector& startPos, const FVector& endPos, const ECollisionChannel& channel, const FName& TraceTag)
{
	FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(false);
	RV_TraceParams.bTraceComplex = true;
	//RV_TraceParams.bTraceAsyncScene = true;
	RV_TraceParams.bReturnPhysicalMaterial = false;
	RV_TraceParams.AddIgnoredActor(Cast<AActor>(WorldContextObject));
	RV_TraceParams.TraceTag = TraceTag;

	//Re-initialize hit info
	FHitResult RV_Hit(ForceInit);

	//call GetWorld() from within an actor extending class
	bool blockingHit = WorldContextObject->GetWorld()->LineTraceSingleByChannel
	(
		RV_Hit,
		startPos,
		endPos,
		channel,
		RV_TraceParams
	);
	return RV_Hit;
}

FHitResult UE4CodeHelpers::CastCrossHairLineTrace(AActor* character, float rayDistance)
{
	FHitResult RV_Hit(ForceInit);
	APawn* pawn = Cast<APawn>(character);
	AController* controller = pawn->GetController();
	APlayerController* playerController = Cast<APlayerController>(controller);

	if (!IsValid(playerController))
		return RV_Hit;

	AActor* playerCameraManagerActor = Cast<AActor>(playerController->PlayerCameraManager);
	//	Ray starting point
	FVector playerViewWorldLocation = playerCameraManagerActor->GetActorLocation();
	//	end point target direction
	controller = Cast<APawn>(character)->GetController();

	if (!IsValid(controller))
		return RV_Hit;

	FVector controllerForwardVector = Cast<AActor>(controller)->GetActorForwardVector();

	RV_Hit = UE4CodeHelpers::SimpleTraceByChannel
	(
		character,
		playerViewWorldLocation + (controllerForwardVector),
		playerViewWorldLocation + (controllerForwardVector * rayDistance),
		ECollisionChannel::ECC_Camera,
		FName("AimTrace")
	);

	return RV_Hit;
}

int32 UE4CodeHelpers::GetNumberOfRowsInFile(const FString& FileName, const FString& folder)
{
	int32 rowCount;
	TArray<FString> rows;
	FString filePath = FString(FPaths::GameDir()).Append(folder).Append(FileName);
	bool foundSomething = FFileHelper::LoadANSITextFileToStrings(*filePath, NULL, rows);

	if (foundSomething)
	{
		rowCount = rows.Num();
		UE_ELOG(LogUE4CodeHelpers, Log, TEXT("Found a number of (%d) rows in the file (%s)."), rowCount, *FileName);
		return rowCount;
	}

	UE_ELOG(LogUE4CodeHelpers, Error, TEXT("Could not read the number of lines in a file (%s). No file found!"), *FileName);

	return -1;
}

FString UE4CodeHelpers::GetConfigFileLine(const FString& fileName, const FString& configName)
{
	return GetVariableValueFromFile(fileName, FString(TEXT("/Config/")), configName);
}

FString UE4CodeHelpers::GetVariableValueFromFile(const FString& fileName, const FString& folder, const FString& configName)
{
	TArray<FString> rows;
	FString filePath = FString(FPaths::GameDir()).Append(folder).Append(fileName);
	bool foundSomething = FFileHelper::LoadFileToStringArray(rows, *filePath);

	if (foundSomething)
	{
		UE_ELOG(LogUE4CodeHelpers, Log, TEXT("Found a file with the name (%s). Processing file to locate the value for variable (%s)."), *fileName, *configName);

		for (auto & row : rows)
		{
			bool containsString = row.Contains(configName, ESearchCase::IgnoreCase, ESearchDir::FromStart);

			if (containsString)
			{
				TArray<FString> parsedLine;
				row.ParseIntoArray(parsedLine, TEXT("="), true);
				int32 parsedArrayLength = parsedLine.Num();
				FString valueFound = parsedLine[parsedArrayLength - 1];
				//	Remove spaces if any
				valueFound.RemoveFromStart(TEXT(" "));

				UE_ELOG(LogUE4CodeHelpers, Log, TEXT("Configuration (%s) found with the value of (%s)"), *configName, *valueFound);
				return parsedLine[parsedArrayLength - 1];
			}
		}

		UE_ELOG(LogUE4CodeHelpers, Warning, TEXT("No line (%s) was found´in the config file (%s)."), *configName, *fileName);

		return FString(TEXT(""));
	}
	else
	{
		UE_ELOG(LogUE4CodeHelpers, Warning, TEXT("Did not find a file named (%s)."), *fileName);
		return FString(TEXT(""));
	}
}

int32 UE4CodeHelpers::GetRepositoryCommitCount()
{
	int32 numberOfCommits = (int32)GetNumberOfRowsInFile(FString(TEXT("HEAD")), FString(TEXT("/.git/logs/")));

	if (numberOfCommits == -1)
	{
		UE_ELOG(LogUE4CodeHelpers, Error, TEXT("Could not find the number of commits. No git repository folder found!"));
		return -1;
	}

	return numberOfCommits;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUE4HelpersModule, UE4Helpers)