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
// End Cross Module References
	void UCOVEditorRuntimeLibrary::StaticRegisterNativesUCOVEditorRuntimeLibrary()
	{
	}
	UClass* Z_Construct_UClass_UCOVEditorRuntimeLibrary_NoRegister()
	{
		return UCOVEditorRuntimeLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UCOVEditorRuntimeLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
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
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
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
	IMPLEMENT_CLASS(UCOVEditorRuntimeLibrary, 3338094286);
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
