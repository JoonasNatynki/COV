// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "COVEditor/Public/BPNode_MyNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBPNode_MyNode() {}
// Cross Module References
	COVEDITOR_API UClass* Z_Construct_UClass_UBPNode_CreateItemData_NoRegister();
	COVEDITOR_API UClass* Z_Construct_UClass_UBPNode_CreateItemData();
	BLUEPRINTGRAPH_API UClass* Z_Construct_UClass_UK2Node_ConstructObjectFromClass();
	UPackage* Z_Construct_UPackage__Script_COVEditor();
// End Cross Module References
	void UBPNode_CreateItemData::StaticRegisterNativesUBPNode_CreateItemData()
	{
	}
	UClass* Z_Construct_UClass_UBPNode_CreateItemData_NoRegister()
	{
		return UBPNode_CreateItemData::StaticClass();
	}
	struct Z_Construct_UClass_UBPNode_CreateItemData_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBPNode_CreateItemData_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UK2Node_ConstructObjectFromClass,
		(UObject* (*)())Z_Construct_UPackage__Script_COVEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBPNode_CreateItemData_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "BPNode_MyNode.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/BPNode_MyNode.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBPNode_CreateItemData_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBPNode_CreateItemData>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UBPNode_CreateItemData_Statics::ClassParams = {
		&UBPNode_CreateItemData::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UBPNode_CreateItemData_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UBPNode_CreateItemData_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UBPNode_CreateItemData()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UBPNode_CreateItemData_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UBPNode_CreateItemData, 2472818053);
	template<> COVEDITOR_API UClass* StaticClass<UBPNode_CreateItemData>()
	{
		return UBPNode_CreateItemData::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBPNode_CreateItemData(Z_Construct_UClass_UBPNode_CreateItemData, &UBPNode_CreateItemData::StaticClass, TEXT("/Script/COVEditor"), TEXT("UBPNode_CreateItemData"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBPNode_CreateItemData);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
