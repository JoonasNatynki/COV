// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "COVEditorRuntime/Public/COVEditorRuntime.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCOVEditorRuntime() {}
// Cross Module References
	COVEDITORRUNTIME_API UClass* Z_Construct_UClass_UCOVEditorRuntimeLibrary_NoRegister();
	COVEDITORRUNTIME_API UClass* Z_Construct_UClass_UCOVEditorRuntimeLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_COVEditorRuntime();
	COVEDITORRUNTIME_API UFunction* Z_Construct_UFunction_UCOVEditorRuntimeLibrary_Create();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
// End Cross Module References
	void UCOVEditorRuntimeLibrary::StaticRegisterNativesUCOVEditorRuntimeLibrary()
	{
		UClass* Class = UCOVEditorRuntimeLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Create", &UCOVEditorRuntimeLibrary::execCreate },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCOVEditorRuntimeLibrary_Create_Statics
	{
		struct COVEditorRuntimeLibrary_eventCreate_Parms
		{
			UObject* WorldContextObject;
			TSubclassOf<UObject>  WidgetType;
			APlayerController* OwningPlayer;
			UObject* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OwningPlayer;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_WidgetType;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCOVEditorRuntimeLibrary_Create_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(COVEditorRuntimeLibrary_eventCreate_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCOVEditorRuntimeLibrary_Create_Statics::NewProp_OwningPlayer = { "OwningPlayer", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(COVEditorRuntimeLibrary_eventCreate_Parms, OwningPlayer), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UCOVEditorRuntimeLibrary_Create_Statics::NewProp_WidgetType = { "WidgetType", nullptr, (EPropertyFlags)0x0014000000000080, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(COVEditorRuntimeLibrary_eventCreate_Parms, WidgetType), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCOVEditorRuntimeLibrary_Create_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(COVEditorRuntimeLibrary_eventCreate_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCOVEditorRuntimeLibrary_Create_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCOVEditorRuntimeLibrary_Create_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCOVEditorRuntimeLibrary_Create_Statics::NewProp_OwningPlayer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCOVEditorRuntimeLibrary_Create_Statics::NewProp_WidgetType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCOVEditorRuntimeLibrary_Create_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCOVEditorRuntimeLibrary_Create_Statics::Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Widget" },
		{ "DisplayName", "Push a screen by class to the stack" },
		{ "ModuleRelativePath", "Public/COVEditorRuntime.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCOVEditorRuntimeLibrary_Create_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCOVEditorRuntimeLibrary, nullptr, "Create", nullptr, nullptr, sizeof(COVEditorRuntimeLibrary_eventCreate_Parms), Z_Construct_UFunction_UCOVEditorRuntimeLibrary_Create_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UCOVEditorRuntimeLibrary_Create_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022409, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCOVEditorRuntimeLibrary_Create_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UCOVEditorRuntimeLibrary_Create_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCOVEditorRuntimeLibrary_Create()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCOVEditorRuntimeLibrary_Create_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UCOVEditorRuntimeLibrary_NoRegister()
	{
		return UCOVEditorRuntimeLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UCOVEditorRuntimeLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCOVEditorRuntimeLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_COVEditorRuntime,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCOVEditorRuntimeLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCOVEditorRuntimeLibrary_Create, "Create" }, // 453090076
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCOVEditorRuntimeLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "//\x09""Blueprint function library class\n" },
		{ "IncludePath", "COVEditorRuntime.h" },
		{ "ModuleRelativePath", "Public/COVEditorRuntime.h" },
		{ "ToolTip", "Blueprint function library class" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCOVEditorRuntimeLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCOVEditorRuntimeLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCOVEditorRuntimeLibrary_Statics::ClassParams = {
		&UCOVEditorRuntimeLibrary::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UCOVEditorRuntimeLibrary_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UCOVEditorRuntimeLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCOVEditorRuntimeLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCOVEditorRuntimeLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCOVEditorRuntimeLibrary, 4135378883);
	template<> COVEDITORRUNTIME_API UClass* StaticClass<UCOVEditorRuntimeLibrary>()
	{
		return UCOVEditorRuntimeLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCOVEditorRuntimeLibrary(Z_Construct_UClass_UCOVEditorRuntimeLibrary, &UCOVEditorRuntimeLibrary::StaticClass, TEXT("/Script/COVEditorRuntime"), TEXT("UCOVEditorRuntimeLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCOVEditorRuntimeLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
