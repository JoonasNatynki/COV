// Fill out your copyright notice in the Description page of Project Settings.

#include "COVBlueprintFunctionLibrary.h"
#include "CollisionQueryParams.h"
#include "Engine.h"
#include "Kismet/KismetMathLibrary.h"
#include <GameFramework/InputSettings.h>

DEFINE_LOG_CATEGORY(COVBlueprintFunctionLibrary)

int32 UCOVBlueprintFunctionLibrary::GetNumberOfRowsInFile(FString FileName, FString folder)
{
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

	COV_LOG(COVBlueprintFunctionLibrary, Error, TEXT("Could not read the number of lines in a file (%s). No file found!"), *FileName);

	return -1;
}

FString UCOVBlueprintFunctionLibrary::GetConfigFileLine(FString fileName, FString configName)
{
	return GetFileLine(fileName, FString(TEXT("/Config/")), configName);
}

FString UCOVBlueprintFunctionLibrary::GetFileLine(FString fileName, FString folder, FString configName)
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
		COV_LOG(COVBlueprintFunctionLibrary, Error, TEXT("No line (%s) was found´in the config file (%s)."), *configName, *fileName);

		return FString(TEXT(""));
	}
	else
	{
		COV_LOG(COVBlueprintFunctionLibrary, Error, TEXT("Did not find a file named (%s)."), *fileName);
		return FString(TEXT(""));
	}
}

int32 UCOVBlueprintFunctionLibrary::GetRepositoryCommitCount()
{
	int32 numberOfCommits = (int32)GetNumberOfRowsInFile(FString(TEXT("HEAD")), FString(TEXT("/.git/logs/")));

	if (numberOfCommits == -1)
	{
		COV_LOG(COVBlueprintFunctionLibrary, Error, TEXT("Could not find the number of commits. No git repository folder found!"));
		return -1;
	}

	return numberOfCommits;
}