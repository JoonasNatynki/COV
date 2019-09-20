// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
struct FHitResult;
class UObject;
struct FVector;
#ifdef UE4HELPERS_UE4Helpers_generated_h
#error "UE4Helpers.generated.h already included, missing '#pragma once' in UE4Helpers.h"
#endif
#define UE4HELPERS_UE4Helpers_generated_h

#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_110_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetRepositoryCommitCount) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=UE4CodeHelpers::GetRepositoryCommitCount(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNumberOfRowsInFile) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InFileName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Folder); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=UE4CodeHelpers::GetNumberOfRowsInFile(Z_Param_InFileName,Z_Param_Folder); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetConfigFileLine) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InFileName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ConfigName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UE4CodeHelpers::GetConfigFileLine(Z_Param_InFileName,Z_Param_ConfigName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVariableValueFromFile) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InFileName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Folder); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ConfigName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UE4CodeHelpers::GetVariableValueFromFile(Z_Param_InFileName,Z_Param_Folder,Z_Param_ConfigName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCastCrossHairLineTrace) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_character); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rayDistance); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FHitResult*)Z_Param__Result=UE4CodeHelpers::CastCrossHairLineTrace(Z_Param_character,Z_Param_rayDistance); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimpleTraceByChannel) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_startPos); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_endPos); \
		P_GET_PROPERTY_REF(UByteProperty,Z_Param_Out_channel); \
		P_GET_PROPERTY_REF(UNameProperty,Z_Param_Out_TraceTag); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FHitResult*)Z_Param__Result=UE4CodeHelpers::SimpleTraceByChannel(Z_Param_WorldContextObject,Z_Param_Out_startPos,Z_Param_Out_endPos,(TEnumAsByte<ECollisionChannel>&)(Z_Param_Out_channel),Z_Param_Out_TraceTag); \
		P_NATIVE_END; \
	}


#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_110_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetRepositoryCommitCount) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=UE4CodeHelpers::GetRepositoryCommitCount(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNumberOfRowsInFile) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InFileName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Folder); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=UE4CodeHelpers::GetNumberOfRowsInFile(Z_Param_InFileName,Z_Param_Folder); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetConfigFileLine) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InFileName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ConfigName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UE4CodeHelpers::GetConfigFileLine(Z_Param_InFileName,Z_Param_ConfigName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVariableValueFromFile) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InFileName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Folder); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ConfigName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UE4CodeHelpers::GetVariableValueFromFile(Z_Param_InFileName,Z_Param_Folder,Z_Param_ConfigName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCastCrossHairLineTrace) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_character); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_rayDistance); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FHitResult*)Z_Param__Result=UE4CodeHelpers::CastCrossHairLineTrace(Z_Param_character,Z_Param_rayDistance); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSimpleTraceByChannel) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_startPos); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_endPos); \
		P_GET_PROPERTY_REF(UByteProperty,Z_Param_Out_channel); \
		P_GET_PROPERTY_REF(UNameProperty,Z_Param_Out_TraceTag); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FHitResult*)Z_Param__Result=UE4CodeHelpers::SimpleTraceByChannel(Z_Param_WorldContextObject,Z_Param_Out_startPos,Z_Param_Out_endPos,(TEnumAsByte<ECollisionChannel>&)(Z_Param_Out_channel),Z_Param_Out_TraceTag); \
		P_NATIVE_END; \
	}


#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_110_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUE4CodeHelpers(); \
	friend struct Z_Construct_UClass_UE4CodeHelpers_Statics; \
public: \
	DECLARE_CLASS(UE4CodeHelpers, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UE4Helpers"), NO_API) \
	DECLARE_SERIALIZER(UE4CodeHelpers)


#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_110_INCLASS \
private: \
	static void StaticRegisterNativesUE4CodeHelpers(); \
	friend struct Z_Construct_UClass_UE4CodeHelpers_Statics; \
public: \
	DECLARE_CLASS(UE4CodeHelpers, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UE4Helpers"), NO_API) \
	DECLARE_SERIALIZER(UE4CodeHelpers)


#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_110_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UE4CodeHelpers(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UE4CodeHelpers) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UE4CodeHelpers); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UE4CodeHelpers); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UE4CodeHelpers(UE4CodeHelpers&&); \
	NO_API UE4CodeHelpers(const UE4CodeHelpers&); \
public:


#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_110_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UE4CodeHelpers(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UE4CodeHelpers(UE4CodeHelpers&&); \
	NO_API UE4CodeHelpers(const UE4CodeHelpers&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UE4CodeHelpers); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UE4CodeHelpers); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UE4CodeHelpers)


#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_110_PRIVATE_PROPERTY_OFFSET
#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_107_PROLOG
#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_110_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_110_PRIVATE_PROPERTY_OFFSET \
	COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_110_RPC_WRAPPERS \
	COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_110_INCLASS \
	COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_110_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_110_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_110_PRIVATE_PROPERTY_OFFSET \
	COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_110_RPC_WRAPPERS_NO_PURE_DECLS \
	COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_110_INCLASS_NO_PURE_DECLS \
	COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_110_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UE4HELPERS_API UClass* StaticClass<class UE4CodeHelpers>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
