// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UScreen;
class APlayerController;
#ifdef SCREENSTACK_ScreenStack_generated_h
#error "ScreenStack.generated.h already included, missing '#pragma once' in ScreenStack.h"
#endif
#define SCREENSTACK_ScreenStack_generated_h

#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_110_DELEGATE \
struct _Script_ScreenStack_eventOnScreenPushedTostack_Parms \
{ \
	UScreen* PushedScreen; \
}; \
static inline void FOnScreenPushedTostack_DelegateWrapper(const FMulticastScriptDelegate& OnScreenPushedTostack, UScreen* PushedScreen) \
{ \
	_Script_ScreenStack_eventOnScreenPushedTostack_Parms Parms; \
	Parms.PushedScreen=PushedScreen; \
	OnScreenPushedTostack.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_109_DELEGATE \
struct _Script_ScreenStack_eventOnScreenRemovedFromStack_Parms \
{ \
	UScreen* RemovedScreen; \
}; \
static inline void FOnScreenRemovedFromStack_DelegateWrapper(const FMulticastScriptDelegate& OnScreenRemovedFromStack, UScreen* RemovedScreen) \
{ \
	_Script_ScreenStack_eventOnScreenRemovedFromStack_Parms Parms; \
	Parms.RemovedScreen=RemovedScreen; \
	OnScreenRemovedFromStack.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_29_DELEGATE \
struct _Script_ScreenStack_eventOnBeginDestroy_Parms \
{ \
	UScreen* screen; \
}; \
static inline void FOnBeginDestroy_DelegateWrapper(const FMulticastScriptDelegate& OnBeginDestroy, UScreen* screen) \
{ \
	_Script_ScreenStack_eventOnBeginDestroy_Parms Parms; \
	Parms.screen=screen; \
	OnBeginDestroy.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_34_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetAllowMultipleInstances) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetAllowMultipleInstances(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsScreenAnOverlay) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetIsScreenAnOverlay(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsScreenLocked) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetIsScreenLocked(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReleaseLock) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ReleaseLock(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLockScreen) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LockScreen(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetShouldScreenTakeOverMouse) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetShouldScreenTakeOverMouse(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetHasScreenLock) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetHasScreenLock(); \
		P_NATIVE_END; \
	}


#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetAllowMultipleInstances) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetAllowMultipleInstances(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsScreenAnOverlay) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetIsScreenAnOverlay(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsScreenLocked) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetIsScreenLocked(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReleaseLock) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ReleaseLock(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLockScreen) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LockScreen(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetShouldScreenTakeOverMouse) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetShouldScreenTakeOverMouse(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetHasScreenLock) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetHasScreenLock(); \
		P_NATIVE_END; \
	}


#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_34_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUScreen(); \
	friend struct Z_Construct_UClass_UScreen_Statics; \
public: \
	DECLARE_CLASS(UScreen, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ScreenStack"), NO_API) \
	DECLARE_SERIALIZER(UScreen)


#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_34_INCLASS \
private: \
	static void StaticRegisterNativesUScreen(); \
	friend struct Z_Construct_UClass_UScreen_Statics; \
public: \
	DECLARE_CLASS(UScreen, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ScreenStack"), NO_API) \
	DECLARE_SERIALIZER(UScreen)


#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_34_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UScreen(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UScreen) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UScreen); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UScreen); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UScreen(UScreen&&); \
	NO_API UScreen(const UScreen&); \
public:


#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_34_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UScreen(UScreen&&); \
	NO_API UScreen(const UScreen&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UScreen); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UScreen); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UScreen)


#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_34_PRIVATE_PROPERTY_OFFSET
#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_31_PROLOG
#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_34_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_34_PRIVATE_PROPERTY_OFFSET \
	COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_34_RPC_WRAPPERS \
	COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_34_INCLASS \
	COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_34_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_34_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_34_PRIVATE_PROPERTY_OFFSET \
	COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
	COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_34_INCLASS_NO_PURE_DECLS \
	COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_34_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SCREENSTACK_API UClass* StaticClass<class UScreen>();

#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_115_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execRemoveScreenFromStackOnRemoveFromParent) \
	{ \
		P_GET_OBJECT(UScreen,Z_Param_screen); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RemoveScreenFromStackOnRemoveFromParent(Z_Param_screen); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHasScreen) \
	{ \
		P_GET_OBJECT(UScreen,Z_Param_screen); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->HasScreen(Z_Param_screen); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetScreensOfType) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_screenType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UScreen*>*)Z_Param__Result=P_THIS->GetScreensOfType(Z_Param_screenType); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindScreensOfType) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_screenType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UScreen*>*)Z_Param__Result=P_THIS->FindScreensOfType(Z_Param_screenType); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPopScreen) \
	{ \
		P_GET_OBJECT(UScreen,Z_Param_screen); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->PopScreen(Z_Param_screen); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTopMostScreen) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UScreen**)Z_Param__Result=P_THIS->GetTopMostScreen(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPopTopScreen) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->PopTopScreen(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetOwnerPlayerController) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(APlayerController**)Z_Param__Result=P_THIS->GetOwnerPlayerController(); \
		P_NATIVE_END; \
	}


#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_115_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execRemoveScreenFromStackOnRemoveFromParent) \
	{ \
		P_GET_OBJECT(UScreen,Z_Param_screen); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RemoveScreenFromStackOnRemoveFromParent(Z_Param_screen); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHasScreen) \
	{ \
		P_GET_OBJECT(UScreen,Z_Param_screen); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->HasScreen(Z_Param_screen); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetScreensOfType) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_screenType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UScreen*>*)Z_Param__Result=P_THIS->GetScreensOfType(Z_Param_screenType); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindScreensOfType) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_screenType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<UScreen*>*)Z_Param__Result=P_THIS->FindScreensOfType(Z_Param_screenType); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPopScreen) \
	{ \
		P_GET_OBJECT(UScreen,Z_Param_screen); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->PopScreen(Z_Param_screen); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTopMostScreen) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UScreen**)Z_Param__Result=P_THIS->GetTopMostScreen(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPopTopScreen) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->PopTopScreen(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetOwnerPlayerController) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(APlayerController**)Z_Param__Result=P_THIS->GetOwnerPlayerController(); \
		P_NATIVE_END; \
	}


#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_115_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUScreenStack(); \
	friend struct Z_Construct_UClass_UScreenStack_Statics; \
public: \
	DECLARE_CLASS(UScreenStack, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ScreenStack"), NO_API) \
	DECLARE_SERIALIZER(UScreenStack)


#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_115_INCLASS \
private: \
	static void StaticRegisterNativesUScreenStack(); \
	friend struct Z_Construct_UClass_UScreenStack_Statics; \
public: \
	DECLARE_CLASS(UScreenStack, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ScreenStack"), NO_API) \
	DECLARE_SERIALIZER(UScreenStack)


#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_115_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UScreenStack(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UScreenStack) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UScreenStack); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UScreenStack); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UScreenStack(UScreenStack&&); \
	NO_API UScreenStack(const UScreenStack&); \
public:


#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_115_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UScreenStack(UScreenStack&&); \
	NO_API UScreenStack(const UScreenStack&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UScreenStack); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UScreenStack); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UScreenStack)


#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_115_PRIVATE_PROPERTY_OFFSET
#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_112_PROLOG
#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_115_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_115_PRIVATE_PROPERTY_OFFSET \
	COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_115_RPC_WRAPPERS \
	COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_115_INCLASS \
	COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_115_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_115_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_115_PRIVATE_PROPERTY_OFFSET \
	COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_115_RPC_WRAPPERS_NO_PURE_DECLS \
	COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_115_INCLASS_NO_PURE_DECLS \
	COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h_115_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SCREENSTACK_API UClass* StaticClass<class UScreenStack>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID COV_Plugins_ScreenStack_Source_ScreenStack_Public_ScreenStack_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
