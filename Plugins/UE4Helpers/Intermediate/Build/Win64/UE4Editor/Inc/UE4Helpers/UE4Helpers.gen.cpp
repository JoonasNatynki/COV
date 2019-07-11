// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UE4Helpers/Public/UE4Helpers.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUE4Helpers() {}
// Cross Module References
	UE4HELPERS_API UClass* Z_Construct_UClass_UE4CodeHelpers_NoRegister();
	UE4HELPERS_API UClass* Z_Construct_UClass_UE4CodeHelpers();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_UE4Helpers();
	UE4HELPERS_API UFunction* Z_Construct_UFunction_UE4CodeHelpers_CastCrossHairLineTrace();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	UE4HELPERS_API UFunction* Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine();
	UE4HELPERS_API UFunction* Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile();
	UE4HELPERS_API UFunction* Z_Construct_UFunction_UE4CodeHelpers_GetRepositoryCommitCount();
	UE4HELPERS_API UFunction* Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile();
	UE4HELPERS_API UFunction* Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
	void UE4CodeHelpers::StaticRegisterNativesUE4CodeHelpers()
	{
		UClass* Class = UE4CodeHelpers::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CastCrossHairLineTrace", &UE4CodeHelpers::execCastCrossHairLineTrace },
			{ "GetConfigFileLine", &UE4CodeHelpers::execGetConfigFileLine },
			{ "GetNumberOfRowsInFile", &UE4CodeHelpers::execGetNumberOfRowsInFile },
			{ "GetRepositoryCommitCount", &UE4CodeHelpers::execGetRepositoryCommitCount },
			{ "GetVariableValueFromFile", &UE4CodeHelpers::execGetVariableValueFromFile },
			{ "SimpleTraceByChannel", &UE4CodeHelpers::execSimpleTraceByChannel },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UE4CodeHelpers_CastCrossHairLineTrace_Statics
	{
		struct E4CodeHelpers_eventCastCrossHairLineTrace_Parms
		{
			AActor* character;
			float rayDistance;
			FHitResult ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_rayDistance;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_character;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UE4CodeHelpers_CastCrossHairLineTrace_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(E4CodeHelpers_eventCastCrossHairLineTrace_Parms, ReturnValue), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UE4CodeHelpers_CastCrossHairLineTrace_Statics::NewProp_rayDistance = { "rayDistance", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(E4CodeHelpers_eventCastCrossHairLineTrace_Parms, rayDistance), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UE4CodeHelpers_CastCrossHairLineTrace_Statics::NewProp_character = { "character", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(E4CodeHelpers_eventCastCrossHairLineTrace_Parms, character), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UE4CodeHelpers_CastCrossHairLineTrace_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UE4CodeHelpers_CastCrossHairLineTrace_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UE4CodeHelpers_CastCrossHairLineTrace_Statics::NewProp_rayDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UE4CodeHelpers_CastCrossHairLineTrace_Statics::NewProp_character,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UE4CodeHelpers_CastCrossHairLineTrace_Statics::Function_MetaDataParams[] = {
		{ "Category", "UE4CodeHelpers" },
		{ "ModuleRelativePath", "Public/UE4Helpers.h" },
		{ "ToolTip", "A simplified line tracer for getting a hit on your cross hairs" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UE4CodeHelpers_CastCrossHairLineTrace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UE4CodeHelpers, nullptr, "CastCrossHairLineTrace", sizeof(E4CodeHelpers_eventCastCrossHairLineTrace_Parms), Z_Construct_UFunction_UE4CodeHelpers_CastCrossHairLineTrace_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_CastCrossHairLineTrace_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UE4CodeHelpers_CastCrossHairLineTrace_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_CastCrossHairLineTrace_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UE4CodeHelpers_CastCrossHairLineTrace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UE4CodeHelpers_CastCrossHairLineTrace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics
	{
		struct E4CodeHelpers_eventGetConfigFileLine_Parms
		{
			FString InFileName;
			FString ConfigName;
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConfigName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ConfigName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InFileName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InFileName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(E4CodeHelpers_eventGetConfigFileLine_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics::NewProp_ConfigName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics::NewProp_ConfigName = { "ConfigName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(E4CodeHelpers_eventGetConfigFileLine_Parms, ConfigName), METADATA_PARAMS(Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics::NewProp_ConfigName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics::NewProp_ConfigName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics::NewProp_InFileName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics::NewProp_InFileName = { "InFileName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(E4CodeHelpers_eventGetConfigFileLine_Parms, InFileName), METADATA_PARAMS(Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics::NewProp_InFileName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics::NewProp_InFileName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics::NewProp_ConfigName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics::NewProp_InFileName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics::Function_MetaDataParams[] = {
		{ "Category", "UE4CodeHelpers" },
		{ "ModuleRelativePath", "Public/UE4Helpers.h" },
		{ "ToolTip", "Will read a file's variable's value in the config folder" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UE4CodeHelpers, nullptr, "GetConfigFileLine", sizeof(E4CodeHelpers_eventGetConfigFileLine_Parms), Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics
	{
		struct E4CodeHelpers_eventGetNumberOfRowsInFile_Parms
		{
			FString InFileName;
			FString Folder;
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Folder_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Folder;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InFileName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InFileName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(E4CodeHelpers_eventGetNumberOfRowsInFile_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics::NewProp_Folder_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics::NewProp_Folder = { "Folder", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(E4CodeHelpers_eventGetNumberOfRowsInFile_Parms, Folder), METADATA_PARAMS(Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics::NewProp_Folder_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics::NewProp_Folder_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics::NewProp_InFileName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics::NewProp_InFileName = { "InFileName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(E4CodeHelpers_eventGetNumberOfRowsInFile_Parms, InFileName), METADATA_PARAMS(Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics::NewProp_InFileName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics::NewProp_InFileName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics::NewProp_Folder,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics::NewProp_InFileName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics::Function_MetaDataParams[] = {
		{ "Category", "UE4CodeHelpers" },
		{ "ModuleRelativePath", "Public/UE4Helpers.h" },
		{ "ToolTip", "Will return the number of lines in a file. No file found = -1" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UE4CodeHelpers, nullptr, "GetNumberOfRowsInFile", sizeof(E4CodeHelpers_eventGetNumberOfRowsInFile_Parms), Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UE4CodeHelpers_GetRepositoryCommitCount_Statics
	{
		struct E4CodeHelpers_eventGetRepositoryCommitCount_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UE4CodeHelpers_GetRepositoryCommitCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(E4CodeHelpers_eventGetRepositoryCommitCount_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UE4CodeHelpers_GetRepositoryCommitCount_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UE4CodeHelpers_GetRepositoryCommitCount_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UE4CodeHelpers_GetRepositoryCommitCount_Statics::Function_MetaDataParams[] = {
		{ "Category", "UE4CodeHelpers" },
		{ "ModuleRelativePath", "Public/UE4Helpers.h" },
		{ "ToolTip", "Will return the number of commits in a the repository. No repository found = -1" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UE4CodeHelpers_GetRepositoryCommitCount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UE4CodeHelpers, nullptr, "GetRepositoryCommitCount", sizeof(E4CodeHelpers_eventGetRepositoryCommitCount_Parms), Z_Construct_UFunction_UE4CodeHelpers_GetRepositoryCommitCount_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_GetRepositoryCommitCount_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UE4CodeHelpers_GetRepositoryCommitCount_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_GetRepositoryCommitCount_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UE4CodeHelpers_GetRepositoryCommitCount()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UE4CodeHelpers_GetRepositoryCommitCount_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics
	{
		struct E4CodeHelpers_eventGetVariableValueFromFile_Parms
		{
			FString InFileName;
			FString Folder;
			FString ConfigName;
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConfigName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ConfigName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Folder_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Folder;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InFileName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InFileName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(E4CodeHelpers_eventGetVariableValueFromFile_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::NewProp_ConfigName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::NewProp_ConfigName = { "ConfigName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(E4CodeHelpers_eventGetVariableValueFromFile_Parms, ConfigName), METADATA_PARAMS(Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::NewProp_ConfigName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::NewProp_ConfigName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::NewProp_Folder_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::NewProp_Folder = { "Folder", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(E4CodeHelpers_eventGetVariableValueFromFile_Parms, Folder), METADATA_PARAMS(Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::NewProp_Folder_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::NewProp_Folder_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::NewProp_InFileName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::NewProp_InFileName = { "InFileName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(E4CodeHelpers_eventGetVariableValueFromFile_Parms, InFileName), METADATA_PARAMS(Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::NewProp_InFileName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::NewProp_InFileName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::NewProp_ConfigName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::NewProp_Folder,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::NewProp_InFileName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::Function_MetaDataParams[] = {
		{ "Category", "UE4CodeHelpers" },
		{ "ModuleRelativePath", "Public/UE4Helpers.h" },
		{ "ToolTip", "Will read a file in a specific folder with the variable name" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UE4CodeHelpers, nullptr, "GetVariableValueFromFile", sizeof(E4CodeHelpers_eventGetVariableValueFromFile_Parms), Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics
	{
		struct E4CodeHelpers_eventSimpleTraceByChannel_Parms
		{
			UObject* WorldContextObject;
			FVector startPos;
			FVector endPos;
			TEnumAsByte<ECollisionChannel> channel;
			FName TraceTag;
			FHitResult ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TraceTag_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_TraceTag;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_channel_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_channel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_endPos_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_endPos;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_startPos_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_startPos;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(E4CodeHelpers_eventSimpleTraceByChannel_Parms, ReturnValue), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_TraceTag_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_TraceTag = { "TraceTag", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(E4CodeHelpers_eventSimpleTraceByChannel_Parms, TraceTag), METADATA_PARAMS(Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_TraceTag_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_TraceTag_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_channel_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_channel = { "channel", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(E4CodeHelpers_eventSimpleTraceByChannel_Parms, channel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_channel_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_channel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_endPos_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_endPos = { "endPos", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(E4CodeHelpers_eventSimpleTraceByChannel_Parms, endPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_endPos_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_endPos_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_startPos_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_startPos = { "startPos", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(E4CodeHelpers_eventSimpleTraceByChannel_Parms, startPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_startPos_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_startPos_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(E4CodeHelpers_eventSimpleTraceByChannel_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_TraceTag,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_channel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_endPos,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_startPos,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::Function_MetaDataParams[] = {
		{ "Category", "UE4CodeHelpers" },
		{ "ModuleRelativePath", "Public/UE4Helpers.h" },
		{ "ToolTip", "Simplified line trace function with a baked in Trace Parameter initialization" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UE4CodeHelpers, nullptr, "SimpleTraceByChannel", sizeof(E4CodeHelpers_eventSimpleTraceByChannel_Parms), Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UE4CodeHelpers_NoRegister()
	{
		return UE4CodeHelpers::StaticClass();
	}
	struct Z_Construct_UClass_UE4CodeHelpers_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UE4CodeHelpers_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_UE4Helpers,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UE4CodeHelpers_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UE4CodeHelpers_CastCrossHairLineTrace, "CastCrossHairLineTrace" }, // 3244152144
		{ &Z_Construct_UFunction_UE4CodeHelpers_GetConfigFileLine, "GetConfigFileLine" }, // 3133433100
		{ &Z_Construct_UFunction_UE4CodeHelpers_GetNumberOfRowsInFile, "GetNumberOfRowsInFile" }, // 4023186151
		{ &Z_Construct_UFunction_UE4CodeHelpers_GetRepositoryCommitCount, "GetRepositoryCommitCount" }, // 968699407
		{ &Z_Construct_UFunction_UE4CodeHelpers_GetVariableValueFromFile, "GetVariableValueFromFile" }, // 3712736780
		{ &Z_Construct_UFunction_UE4CodeHelpers_SimpleTraceByChannel, "SimpleTraceByChannel" }, // 3047050365
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UE4CodeHelpers_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "UE4Helpers.h" },
		{ "ModuleRelativePath", "Public/UE4Helpers.h" },
		{ "ToolTip", "Blueprint function library class" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UE4CodeHelpers_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UE4CodeHelpers>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UE4CodeHelpers_Statics::ClassParams = {
		&UE4CodeHelpers::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UE4CodeHelpers_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UE4CodeHelpers_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UE4CodeHelpers()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UE4CodeHelpers_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UE4CodeHelpers, 1485787255);
	template<> UE4HELPERS_API UClass* StaticClass<UE4CodeHelpers>()
	{
		return UE4CodeHelpers::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UE4CodeHelpers(Z_Construct_UClass_UE4CodeHelpers, &UE4CodeHelpers::StaticClass, TEXT("/Script/UE4Helpers"), TEXT("UE4CodeHelpers"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UE4CodeHelpers);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
