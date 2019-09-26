// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ScreenStackEditor/Public/ScreenStackEditorNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeScreenStackEditorNode() {}
// Cross Module References
	SCREENSTACKEDITOR_API UClass* Z_Construct_UClass_UK2Node_PushWidgetByClass_NoRegister();
	SCREENSTACKEDITOR_API UClass* Z_Construct_UClass_UK2Node_PushWidgetByClass();
	BLUEPRINTGRAPH_API UClass* Z_Construct_UClass_UK2Node_ConstructObjectFromClass();
	UPackage* Z_Construct_UPackage__Script_ScreenStackEditor();
// End Cross Module References
	void UK2Node_PushWidgetByClass::StaticRegisterNativesUK2Node_PushWidgetByClass()
	{
	}
	UClass* Z_Construct_UClass_UK2Node_PushWidgetByClass_NoRegister()
	{
		return UK2Node_PushWidgetByClass::StaticClass();
	}
	struct Z_Construct_UClass_UK2Node_PushWidgetByClass_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UK2Node_PushWidgetByClass_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UK2Node_ConstructObjectFromClass,
		(UObject* (*)())Z_Construct_UPackage__Script_ScreenStackEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UK2Node_PushWidgetByClass_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ScreenStackEditorNode.h" },
		{ "ModuleRelativePath", "Public/ScreenStackEditorNode.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UK2Node_PushWidgetByClass_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UK2Node_PushWidgetByClass>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UK2Node_PushWidgetByClass_Statics::ClassParams = {
		&UK2Node_PushWidgetByClass::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UK2Node_PushWidgetByClass_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UK2Node_PushWidgetByClass_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UK2Node_PushWidgetByClass()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UK2Node_PushWidgetByClass_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UK2Node_PushWidgetByClass, 2144988754);
	template<> SCREENSTACKEDITOR_API UClass* StaticClass<UK2Node_PushWidgetByClass>()
	{
		return UK2Node_PushWidgetByClass::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UK2Node_PushWidgetByClass(Z_Construct_UClass_UK2Node_PushWidgetByClass, &UK2Node_PushWidgetByClass::StaticClass, TEXT("/Script/ScreenStackEditor"), TEXT("UK2Node_PushWidgetByClass"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UK2Node_PushWidgetByClass);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
