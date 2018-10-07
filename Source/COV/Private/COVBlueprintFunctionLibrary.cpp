// Fill out your copyright notice in the Description page of Project Settings.

#include "COVBlueprintFunctionLibrary.h"
#include "CollisionQueryParams.h"
#include "Engine.h"
#include "Kismet/KismetMathLibrary.h"
#include <GameFramework/InputSettings.h>

DEFINE_LOG_CATEGORY(COVBlueprintFunctionLibrary)

FHitResult UCOVBlueprintFunctionLibrary::SimpleTraceByChannel(UObject* inObj, FVector startPos, FVector endPos, ECollisionChannel channel, FName TraceTag)
{
	//const FName TraceTag("COVTraces");
	//inObj->GetWorld()->DebugDrawTraceTag = TraceTag;

	//	LINETRACE	################################
	FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("Joonas")), false);
	RV_TraceParams.bTraceComplex = true;
	RV_TraceParams.bTraceAsyncScene = true;
	RV_TraceParams.bReturnPhysicalMaterial = false;
	RV_TraceParams.AddIgnoredActor(Cast<AActor>(inObj));
	RV_TraceParams.TraceTag = TraceTag;

	//Re-initialize hit info
	FHitResult RV_Hit(ForceInit);

	//call GetWorld() from within an actor extending class
	bool blockingHit = inObj->GetWorld()->LineTraceSingleByChannel(
		RV_Hit,        //result
		startPos,    //start
		endPos, //end
		channel, //collision channel
		RV_TraceParams
	);
	//	############################################
	return RV_Hit;
}

FHitResult UCOVBlueprintFunctionLibrary::CastCrossHairLineTrace(AActor* character, float rayDistance)
{
	//COV_LOG(COVBlueprintFunctionLibrary, Warning, TEXT("You should clean this function up a little"));

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

	RV_Hit = UCOVBlueprintFunctionLibrary::SimpleTraceByChannel
	(
		character,
		playerViewWorldLocation + (controllerForwardVector),
		playerViewWorldLocation + (controllerForwardVector * rayDistance),
		ECollisionChannel::ECC_Camera,
		FName("AimTrace")
	);

	return RV_Hit;
}

int32 UCOVBlueprintFunctionLibrary::GetNumberOfRowsInFile(FString FileName, FString folder)
{
	COV_LOG(COVBlueprintFunctionLibrary, Log, TEXT("Reading the number of lines in a file (%s)."), *FileName);

	int32 rowCount;
	TArray<FString> rows;
	FString filePath = FString(FPaths::GameDir()).Append(folder).Append(FileName);
	bool foundSomething = FFileHelper::LoadANSITextFileToStrings(*filePath, NULL, rows);

	if (foundSomething)
	{
		rowCount = rows.Num();
		COV_LOG(COVBlueprintFunctionLibrary, Log, TEXT("Found a number of (%d) rows in the file (%s)."), rowCount, *FileName);
		return rowCount;
	}
	return -1;
}

FString UCOVBlueprintFunctionLibrary::ReadConfigFileLine(FString fileName, FString configName)
{
	return ReadFileLine(fileName, FString(TEXT("/Config/")), configName);
}

FString UCOVBlueprintFunctionLibrary::ReadFileLine(FString fileName, FString folder, FString configName)
{
	TArray<FString> rows;
	FString filePath = FString(FPaths::GameDir()).Append(folder).Append(fileName);
	bool foundSomething = FFileHelper::LoadFileToStringArray(rows, *filePath);

	if (foundSomething)
	{
		COV_LOG(COVBlueprintFunctionLibrary, Log, TEXT("Found a file with the name (%s). Processing words to locate the setting for configuration (%s)."), *fileName, *configName);

		for(auto & row : rows)
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

				COV_LOG(COVBlueprintFunctionLibrary, Log, TEXT("Configuration (%s) found with the value of (%s)"), *configName, *valueFound);
				return parsedLine[parsedArrayLength - 1];
			}
		}
		COV_LOG(COVBlueprintFunctionLibrary, Warning, TEXT("No line (%s) was found´in the config file (%s)."), *configName, *fileName);

		return FString(TEXT(""));
	}
	else
	{
		COV_LOG(COVBlueprintFunctionLibrary, Warning, TEXT("Did not find a file named (%s)."), *fileName);
		return FString(TEXT(""));
	}
}

FString UCOVBlueprintFunctionLibrary::GetGameVersionAsString()
{
	float numberOfCommits = (float)GetNumberOfRowsInFile(FString(TEXT("HEAD")), FString(TEXT("/.git/logs/")));
	FString versionType = ReadConfigFileLine(FString(TEXT("COVGameInfo.ini")), FString(TEXT("VersionNumber")));

	return FString::SanitizeFloat(numberOfCommits / 1000.0f).Append(TEXT(" ")).Append(versionType);
}