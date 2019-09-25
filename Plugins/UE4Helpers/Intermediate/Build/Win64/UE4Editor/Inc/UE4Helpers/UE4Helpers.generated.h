// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class AActor;
struct FRotator;
struct FVector;
class APawn;
class APlayerCameraManager;
struct FHitResult;
#ifdef UE4HELPERS_UE4Helpers_generated_h
#error "UE4Helpers.generated.h already included, missing '#pragma once' in UE4Helpers.h"
#endif
#define UE4HELPERS_UE4Helpers_generated_h

#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_105_DELEGATE \
struct _Script_UE4Helpers_eventAsyncChildClassLoadSignature_Parms \
{ \
	const UClass* AsyncLoadedClassType; \
}; \
static inline void FAsyncChildClassLoadSignature_DelegateWrapper(const FScriptDelegate& AsyncChildClassLoadSignature, const UClass* AsyncLoadedClassType) \
{ \
	_Script_UE4Helpers_eventAsyncChildClassLoadSignature_Parms Parms; \
	Parms.AsyncLoadedClassType=AsyncLoadedClassType; \
	AsyncChildClassLoadSignature.ProcessDelegate<UObject>(&Parms); \
}


#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_111_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetAllAssetsOfType) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_type); \
		P_GET_PROPERTY(UStrProperty,Z_Param_pathToSearchFor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UClass*>*)Z_Param__Result=UE4CodeHelpers::GetAllAssetsOfType(Z_Param_type,Z_Param_pathToSearchFor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOrientRotationToNormalVector) \
	{ \
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_CurrentRotation); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Normal); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FRotator*)Z_Param__Result=UE4CodeHelpers::OrientRotationToNormalVector(Z_Param_Out_CurrentRotation,Z_Param_Out_Normal); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCalculateBarabolicTrajectory) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_startLocation); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_velocity); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_gravity); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_timeToSimulate); \
		P_GET_PROPERTY(UIntProperty,Z_Param_numberOfTrajectoryPoints); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FVector>*)Z_Param__Result=UE4CodeHelpers::CalculateBarabolicTrajectory(Z_Param_WorldContextObject,Z_Param_Out_startLocation,Z_Param_Out_velocity,Z_Param_Out_gravity,Z_Param_timeToSimulate,Z_Param_numberOfTrajectoryPoints); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsOfType) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_object); \
		P_GET_OBJECT(UClass,Z_Param_type); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UE4CodeHelpers::IsOfType(Z_Param_object,Z_Param_type); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTryGetPawnCameraManager) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_pawn); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(APlayerCameraManager**)Z_Param__Result=UE4CodeHelpers::TryGetPawnCameraManager(Z_Param_pawn); \
		P_NATIVE_END; \
	} \
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
	DECLARE_FUNCTION(execGetFileLine) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InFileName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Folder); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ConfigName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UE4CodeHelpers::GetFileLine(Z_Param_InFileName,Z_Param_Folder,Z_Param_ConfigName); \
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
		P_GET_PROPERTY(UByteProperty,Z_Param_channel); \
		P_GET_PROPERTY_REF(UNameProperty,Z_Param_Out_TraceTag); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FHitResult*)Z_Param__Result=UE4CodeHelpers::SimpleTraceByChannel(Z_Param_WorldContextObject,Z_Param_Out_startPos,Z_Param_Out_endPos,ECollisionChannel(Z_Param_channel),Z_Param_Out_TraceTag); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNetModePrefix) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UE4CodeHelpers::GetNetModePrefix(Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	}


#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_111_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetAllAssetsOfType) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_type); \
		P_GET_PROPERTY(UStrProperty,Z_Param_pathToSearchFor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UClass*>*)Z_Param__Result=UE4CodeHelpers::GetAllAssetsOfType(Z_Param_type,Z_Param_pathToSearchFor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOrientRotationToNormalVector) \
	{ \
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_CurrentRotation); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Normal); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FRotator*)Z_Param__Result=UE4CodeHelpers::OrientRotationToNormalVector(Z_Param_Out_CurrentRotation,Z_Param_Out_Normal); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCalculateBarabolicTrajectory) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_startLocation); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_velocity); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_gravity); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_timeToSimulate); \
		P_GET_PROPERTY(UIntProperty,Z_Param_numberOfTrajectoryPoints); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FVector>*)Z_Param__Result=UE4CodeHelpers::CalculateBarabolicTrajectory(Z_Param_WorldContextObject,Z_Param_Out_startLocation,Z_Param_Out_velocity,Z_Param_Out_gravity,Z_Param_timeToSimulate,Z_Param_numberOfTrajectoryPoints); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsOfType) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_object); \
		P_GET_OBJECT(UClass,Z_Param_type); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UE4CodeHelpers::IsOfType(Z_Param_object,Z_Param_type); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTryGetPawnCameraManager) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_pawn); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(APlayerCameraManager**)Z_Param__Result=UE4CodeHelpers::TryGetPawnCameraManager(Z_Param_pawn); \
		P_NATIVE_END; \
	} \
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
	DECLARE_FUNCTION(execGetFileLine) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InFileName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Folder); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ConfigName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UE4CodeHelpers::GetFileLine(Z_Param_InFileName,Z_Param_Folder,Z_Param_ConfigName); \
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
		P_GET_PROPERTY(UByteProperty,Z_Param_channel); \
		P_GET_PROPERTY_REF(UNameProperty,Z_Param_Out_TraceTag); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FHitResult*)Z_Param__Result=UE4CodeHelpers::SimpleTraceByChannel(Z_Param_WorldContextObject,Z_Param_Out_startPos,Z_Param_Out_endPos,ECollisionChannel(Z_Param_channel),Z_Param_Out_TraceTag); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNetModePrefix) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UE4CodeHelpers::GetNetModePrefix(Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	}


#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_111_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUE4CodeHelpers(); \
	friend struct Z_Construct_UClass_UE4CodeHelpers_Statics; \
public: \
	DECLARE_CLASS(UE4CodeHelpers, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UE4Helpers"), NO_API) \
	DECLARE_SERIALIZER(UE4CodeHelpers)


#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_111_INCLASS \
private: \
	static void StaticRegisterNativesUE4CodeHelpers(); \
	friend struct Z_Construct_UClass_UE4CodeHelpers_Statics; \
public: \
	DECLARE_CLASS(UE4CodeHelpers, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UE4Helpers"), NO_API) \
	DECLARE_SERIALIZER(UE4CodeHelpers)


#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_111_STANDARD_CONSTRUCTORS \
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


#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_111_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UE4CodeHelpers(UE4CodeHelpers&&); \
	NO_API UE4CodeHelpers(const UE4CodeHelpers&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UE4CodeHelpers); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UE4CodeHelpers); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UE4CodeHelpers)


#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_111_PRIVATE_PROPERTY_OFFSET
#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_108_PROLOG
#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_111_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_111_PRIVATE_PROPERTY_OFFSET \
	COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_111_RPC_WRAPPERS \
	COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_111_INCLASS \
	COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_111_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_111_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_111_PRIVATE_PROPERTY_OFFSET \
	COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_111_RPC_WRAPPERS_NO_PURE_DECLS \
	COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_111_INCLASS_NO_PURE_DECLS \
	COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h_111_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UE4HELPERS_API UClass* StaticClass<class UE4CodeHelpers>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID COV_Plugins_UE4Helpers_Source_UE4Helpers_Public_UE4Helpers_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
