// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Source/Public/ScreenStack.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeScreenStack() {}
// Cross Module References
	SCREENSTACK_API UFunction* Z_Construct_UDelegateFunction_ScreenStack_OnScreenPushedTostack__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_ScreenStack();
	SCREENSTACK_API UClass* Z_Construct_UClass_UScreen_NoRegister();
	SCREENSTACK_API UFunction* Z_Construct_UDelegateFunction_ScreenStack_OnScreenRemovedFromStack__DelegateSignature();
	SCREENSTACK_API UClass* Z_Construct_UClass_UScreen();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	SCREENSTACK_API UFunction* Z_Construct_UFunction_UScreen_GetAllowMultipleInstances();
	SCREENSTACK_API UFunction* Z_Construct_UFunction_UScreen_GetHasScreenLock();
	SCREENSTACK_API UFunction* Z_Construct_UFunction_UScreen_GetIsScreenAnOverlay();
	SCREENSTACK_API UFunction* Z_Construct_UFunction_UScreen_GetIsScreenLocked();
	SCREENSTACK_API UFunction* Z_Construct_UFunction_UScreen_GetShouldScreenTakeOverMouse();
	SCREENSTACK_API UFunction* Z_Construct_UFunction_UScreen_LockScreen();
	SCREENSTACK_API UFunction* Z_Construct_UFunction_UScreen_ReleaseLock();
	INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
	SCREENSTACK_API UClass* Z_Construct_UClass_UScreenStack_NoRegister();
	SCREENSTACK_API UClass* Z_Construct_UClass_UScreenStack();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	SCREENSTACK_API UFunction* Z_Construct_UFunction_UScreenStack_FindScreenByType();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	SCREENSTACK_API UFunction* Z_Construct_UFunction_UScreenStack_GetOwnerPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
	SCREENSTACK_API UFunction* Z_Construct_UFunction_UScreenStack_GetScreenByType();
	SCREENSTACK_API UFunction* Z_Construct_UFunction_UScreenStack_GetTopMostScreen();
	SCREENSTACK_API UFunction* Z_Construct_UFunction_UScreenStack_HasScreen();
	SCREENSTACK_API UFunction* Z_Construct_UFunction_UScreenStack_PopScreen();
	SCREENSTACK_API UFunction* Z_Construct_UFunction_UScreenStack_PopTopScreen();
	SCREENSTACK_API UFunction* Z_Construct_UFunction_UScreenStack_PushScreenByClass();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_ScreenStack_OnScreenPushedTostack__DelegateSignature_Statics
	{
		struct _Script_ScreenStack_eventOnScreenPushedTostack_Parms
		{
			UScreen* PushedScreen;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PushedScreen_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PushedScreen;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ScreenStack_OnScreenPushedTostack__DelegateSignature_Statics::NewProp_PushedScreen_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ScreenStack_OnScreenPushedTostack__DelegateSignature_Statics::NewProp_PushedScreen = { "PushedScreen", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_ScreenStack_eventOnScreenPushedTostack_Parms, PushedScreen), Z_Construct_UClass_UScreen_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_ScreenStack_OnScreenPushedTostack__DelegateSignature_Statics::NewProp_PushedScreen_MetaData, ARRAY_COUNT(Z_Construct_UDelegateFunction_ScreenStack_OnScreenPushedTostack__DelegateSignature_Statics::NewProp_PushedScreen_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ScreenStack_OnScreenPushedTostack__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ScreenStack_OnScreenPushedTostack__DelegateSignature_Statics::NewProp_PushedScreen,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ScreenStack_OnScreenPushedTostack__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ScreenStack_OnScreenPushedTostack__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ScreenStack, nullptr, "OnScreenPushedTostack__DelegateSignature", nullptr, nullptr, sizeof(_Script_ScreenStack_eventOnScreenPushedTostack_Parms), Z_Construct_UDelegateFunction_ScreenStack_OnScreenPushedTostack__DelegateSignature_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UDelegateFunction_ScreenStack_OnScreenPushedTostack__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_ScreenStack_OnScreenPushedTostack__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_ScreenStack_OnScreenPushedTostack__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_ScreenStack_OnScreenPushedTostack__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_ScreenStack_OnScreenPushedTostack__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_ScreenStack_OnScreenRemovedFromStack__DelegateSignature_Statics
	{
		struct _Script_ScreenStack_eventOnScreenRemovedFromStack_Parms
		{
			UScreen* RemovedScreen;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RemovedScreen_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RemovedScreen;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ScreenStack_OnScreenRemovedFromStack__DelegateSignature_Statics::NewProp_RemovedScreen_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ScreenStack_OnScreenRemovedFromStack__DelegateSignature_Statics::NewProp_RemovedScreen = { "RemovedScreen", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_ScreenStack_eventOnScreenRemovedFromStack_Parms, RemovedScreen), Z_Construct_UClass_UScreen_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_ScreenStack_OnScreenRemovedFromStack__DelegateSignature_Statics::NewProp_RemovedScreen_MetaData, ARRAY_COUNT(Z_Construct_UDelegateFunction_ScreenStack_OnScreenRemovedFromStack__DelegateSignature_Statics::NewProp_RemovedScreen_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ScreenStack_OnScreenRemovedFromStack__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ScreenStack_OnScreenRemovedFromStack__DelegateSignature_Statics::NewProp_RemovedScreen,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ScreenStack_OnScreenRemovedFromStack__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ScreenStack_OnScreenRemovedFromStack__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ScreenStack, nullptr, "OnScreenRemovedFromStack__DelegateSignature", nullptr, nullptr, sizeof(_Script_ScreenStack_eventOnScreenRemovedFromStack_Parms), Z_Construct_UDelegateFunction_ScreenStack_OnScreenRemovedFromStack__DelegateSignature_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UDelegateFunction_ScreenStack_OnScreenRemovedFromStack__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_ScreenStack_OnScreenRemovedFromStack__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_ScreenStack_OnScreenRemovedFromStack__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_ScreenStack_OnScreenRemovedFromStack__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_ScreenStack_OnScreenRemovedFromStack__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	void UScreen::StaticRegisterNativesUScreen()
	{
		UClass* Class = UScreen::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAllowMultipleInstances", &UScreen::execGetAllowMultipleInstances },
			{ "GetHasScreenLock", &UScreen::execGetHasScreenLock },
			{ "GetIsScreenAnOverlay", &UScreen::execGetIsScreenAnOverlay },
			{ "GetIsScreenLocked", &UScreen::execGetIsScreenLocked },
			{ "GetShouldScreenTakeOverMouse", &UScreen::execGetShouldScreenTakeOverMouse },
			{ "LockScreen", &UScreen::execLockScreen },
			{ "ReleaseLock", &UScreen::execReleaseLock },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UScreen_GetAllowMultipleInstances_Statics
	{
		struct Screen_eventGetAllowMultipleInstances_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UScreen_GetAllowMultipleInstances_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Screen_eventGetAllowMultipleInstances_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UScreen_GetAllowMultipleInstances_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Screen_eventGetAllowMultipleInstances_Parms), &Z_Construct_UFunction_UScreen_GetAllowMultipleInstances_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScreen_GetAllowMultipleInstances_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScreen_GetAllowMultipleInstances_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScreen_GetAllowMultipleInstances_Statics::Function_MetaDataParams[] = {
		{ "Category", "Screen" },
		{ "Comment", "//\x09""Can more than one screen exist at the same time in the stack?\n" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
		{ "ToolTip", "Can more than one screen exist at the same time in the stack?" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UScreen_GetAllowMultipleInstances_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScreen, nullptr, "GetAllowMultipleInstances", nullptr, nullptr, sizeof(Screen_eventGetAllowMultipleInstances_Parms), Z_Construct_UFunction_UScreen_GetAllowMultipleInstances_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UScreen_GetAllowMultipleInstances_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UScreen_GetAllowMultipleInstances_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UScreen_GetAllowMultipleInstances_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UScreen_GetAllowMultipleInstances()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UScreen_GetAllowMultipleInstances_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScreen_GetHasScreenLock_Statics
	{
		struct Screen_eventGetHasScreenLock_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UScreen_GetHasScreenLock_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Screen_eventGetHasScreenLock_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UScreen_GetHasScreenLock_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Screen_eventGetHasScreenLock_Parms), &Z_Construct_UFunction_UScreen_GetHasScreenLock_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScreen_GetHasScreenLock_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScreen_GetHasScreenLock_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScreen_GetHasScreenLock_Statics::Function_MetaDataParams[] = {
		{ "Category", "Screen" },
		{ "Comment", "//\x09Is the screen locked in place and can't be removed from stack?\n" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
		{ "ToolTip", "Is the screen locked in place and can't be removed from stack?" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UScreen_GetHasScreenLock_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScreen, nullptr, "GetHasScreenLock", nullptr, nullptr, sizeof(Screen_eventGetHasScreenLock_Parms), Z_Construct_UFunction_UScreen_GetHasScreenLock_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UScreen_GetHasScreenLock_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UScreen_GetHasScreenLock_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UScreen_GetHasScreenLock_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UScreen_GetHasScreenLock()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UScreen_GetHasScreenLock_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScreen_GetIsScreenAnOverlay_Statics
	{
		struct Screen_eventGetIsScreenAnOverlay_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UScreen_GetIsScreenAnOverlay_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Screen_eventGetIsScreenAnOverlay_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UScreen_GetIsScreenAnOverlay_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Screen_eventGetIsScreenAnOverlay_Parms), &Z_Construct_UFunction_UScreen_GetIsScreenAnOverlay_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScreen_GetIsScreenAnOverlay_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScreen_GetIsScreenAnOverlay_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScreen_GetIsScreenAnOverlay_Statics::Function_MetaDataParams[] = {
		{ "Category", "Screen" },
		{ "Comment", "//\x09Is the screen an overlay?\n" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
		{ "ToolTip", "Is the screen an overlay?" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UScreen_GetIsScreenAnOverlay_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScreen, nullptr, "GetIsScreenAnOverlay", nullptr, nullptr, sizeof(Screen_eventGetIsScreenAnOverlay_Parms), Z_Construct_UFunction_UScreen_GetIsScreenAnOverlay_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UScreen_GetIsScreenAnOverlay_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UScreen_GetIsScreenAnOverlay_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UScreen_GetIsScreenAnOverlay_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UScreen_GetIsScreenAnOverlay()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UScreen_GetIsScreenAnOverlay_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScreen_GetIsScreenLocked_Statics
	{
		struct Screen_eventGetIsScreenLocked_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UScreen_GetIsScreenLocked_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Screen_eventGetIsScreenLocked_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UScreen_GetIsScreenLocked_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Screen_eventGetIsScreenLocked_Parms), &Z_Construct_UFunction_UScreen_GetIsScreenLocked_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScreen_GetIsScreenLocked_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScreen_GetIsScreenLocked_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScreen_GetIsScreenLocked_Statics::Function_MetaDataParams[] = {
		{ "Category", "Screen" },
		{ "Comment", "//\x09Is the screen locked in place and can't be removed from stack?\n" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
		{ "ToolTip", "Is the screen locked in place and can't be removed from stack?" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UScreen_GetIsScreenLocked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScreen, nullptr, "GetIsScreenLocked", nullptr, nullptr, sizeof(Screen_eventGetIsScreenLocked_Parms), Z_Construct_UFunction_UScreen_GetIsScreenLocked_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UScreen_GetIsScreenLocked_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UScreen_GetIsScreenLocked_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UScreen_GetIsScreenLocked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UScreen_GetIsScreenLocked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UScreen_GetIsScreenLocked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScreen_GetShouldScreenTakeOverMouse_Statics
	{
		struct Screen_eventGetShouldScreenTakeOverMouse_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UScreen_GetShouldScreenTakeOverMouse_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Screen_eventGetShouldScreenTakeOverMouse_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UScreen_GetShouldScreenTakeOverMouse_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Screen_eventGetShouldScreenTakeOverMouse_Parms), &Z_Construct_UFunction_UScreen_GetShouldScreenTakeOverMouse_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScreen_GetShouldScreenTakeOverMouse_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScreen_GetShouldScreenTakeOverMouse_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScreen_GetShouldScreenTakeOverMouse_Statics::Function_MetaDataParams[] = {
		{ "Category", "Screen" },
		{ "Comment", "//\x09Should this screen capture the mouse cursor?\n" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
		{ "ToolTip", "Should this screen capture the mouse cursor?" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UScreen_GetShouldScreenTakeOverMouse_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScreen, nullptr, "GetShouldScreenTakeOverMouse", nullptr, nullptr, sizeof(Screen_eventGetShouldScreenTakeOverMouse_Parms), Z_Construct_UFunction_UScreen_GetShouldScreenTakeOverMouse_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UScreen_GetShouldScreenTakeOverMouse_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UScreen_GetShouldScreenTakeOverMouse_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UScreen_GetShouldScreenTakeOverMouse_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UScreen_GetShouldScreenTakeOverMouse()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UScreen_GetShouldScreenTakeOverMouse_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScreen_LockScreen_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScreen_LockScreen_Statics::Function_MetaDataParams[] = {
		{ "Category", "Screen" },
		{ "Comment", "// Locks the screen so that it can't be removed from the stack.\n" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
		{ "ToolTip", "Locks the screen so that it can't be removed from the stack." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UScreen_LockScreen_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScreen, nullptr, "LockScreen", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UScreen_LockScreen_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UScreen_LockScreen_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UScreen_LockScreen()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UScreen_LockScreen_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScreen_ReleaseLock_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScreen_ReleaseLock_Statics::Function_MetaDataParams[] = {
		{ "Category", "Screen" },
		{ "Comment", "// Release lock for this window so that it can be removed from the stack.\n" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
		{ "ToolTip", "Release lock for this window so that it can be removed from the stack." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UScreen_ReleaseLock_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScreen, nullptr, "ReleaseLock", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UScreen_ReleaseLock_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UScreen_ReleaseLock_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UScreen_ReleaseLock()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UScreen_ReleaseLock_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UScreen_NoRegister()
	{
		return UScreen::StaticClass();
	}
	struct Z_Construct_UClass_UScreen_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_KeyToCloseScreenWith_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_KeyToCloseScreenWith;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bTakeOverInput_MetaData[];
#endif
		static void NewProp_bTakeOverInput_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bTakeOverInput;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAllowMultipleInstances_MetaData[];
#endif
		static void NewProp_bAllowMultipleInstances_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAllowMultipleInstances;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bScreenIsAnOverlay_MetaData[];
#endif
		static void NewProp_bScreenIsAnOverlay_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bScreenIsAnOverlay;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bScreenIsLocked_MetaData[];
#endif
		static void NewProp_bScreenIsLocked_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bScreenIsLocked;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UScreen_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_ScreenStack,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UScreen_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UScreen_GetAllowMultipleInstances, "GetAllowMultipleInstances" }, // 1323290666
		{ &Z_Construct_UFunction_UScreen_GetHasScreenLock, "GetHasScreenLock" }, // 3583772158
		{ &Z_Construct_UFunction_UScreen_GetIsScreenAnOverlay, "GetIsScreenAnOverlay" }, // 3658402401
		{ &Z_Construct_UFunction_UScreen_GetIsScreenLocked, "GetIsScreenLocked" }, // 1485001281
		{ &Z_Construct_UFunction_UScreen_GetShouldScreenTakeOverMouse, "GetShouldScreenTakeOverMouse" }, // 2503224152
		{ &Z_Construct_UFunction_UScreen_LockScreen, "LockScreen" }, // 252668287
		{ &Z_Construct_UFunction_UScreen_ReleaseLock, "ReleaseLock" }, // 1564186784
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScreen_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ScreenStack.h" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScreen_Statics::NewProp_KeyToCloseScreenWith_MetaData[] = {
		{ "Category", "Screen" },
		{ "Comment", "//\x09""Bind a key to automatically close the screen with\n" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
		{ "ToolTip", "Bind a key to automatically close the screen with" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UScreen_Statics::NewProp_KeyToCloseScreenWith = { "KeyToCloseScreenWith", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UScreen, KeyToCloseScreenWith), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(Z_Construct_UClass_UScreen_Statics::NewProp_KeyToCloseScreenWith_MetaData, ARRAY_COUNT(Z_Construct_UClass_UScreen_Statics::NewProp_KeyToCloseScreenWith_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScreen_Statics::NewProp_bTakeOverInput_MetaData[] = {
		{ "Category", "Screen" },
		{ "Comment", "//\x09If this screen should take over mouse and keyboard input\n" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
		{ "ToolTip", "If this screen should take over mouse and keyboard input" },
	};
#endif
	void Z_Construct_UClass_UScreen_Statics::NewProp_bTakeOverInput_SetBit(void* Obj)
	{
		((UScreen*)Obj)->bTakeOverInput = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UScreen_Statics::NewProp_bTakeOverInput = { "bTakeOverInput", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UScreen), &Z_Construct_UClass_UScreen_Statics::NewProp_bTakeOverInput_SetBit, METADATA_PARAMS(Z_Construct_UClass_UScreen_Statics::NewProp_bTakeOverInput_MetaData, ARRAY_COUNT(Z_Construct_UClass_UScreen_Statics::NewProp_bTakeOverInput_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScreen_Statics::NewProp_bAllowMultipleInstances_MetaData[] = {
		{ "Category", "Screen" },
		{ "Comment", "//\x09If there can exist more than one of these screen or just one. If only one instance is allowed and the same screen is being pushed back into the stack, the stack will simply move that screen to the top and display it instead.\n" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
		{ "ToolTip", "If there can exist more than one of these screen or just one. If only one instance is allowed and the same screen is being pushed back into the stack, the stack will simply move that screen to the top and display it instead." },
	};
#endif
	void Z_Construct_UClass_UScreen_Statics::NewProp_bAllowMultipleInstances_SetBit(void* Obj)
	{
		((UScreen*)Obj)->bAllowMultipleInstances = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UScreen_Statics::NewProp_bAllowMultipleInstances = { "bAllowMultipleInstances", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UScreen), &Z_Construct_UClass_UScreen_Statics::NewProp_bAllowMultipleInstances_SetBit, METADATA_PARAMS(Z_Construct_UClass_UScreen_Statics::NewProp_bAllowMultipleInstances_MetaData, ARRAY_COUNT(Z_Construct_UClass_UScreen_Statics::NewProp_bAllowMultipleInstances_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScreen_Statics::NewProp_bScreenIsAnOverlay_MetaData[] = {
		{ "Category", "Screen" },
		{ "Comment", "//\x09If the screen is an overlay. Screen under it will be visible until a screen that is not an overlay.\n" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
		{ "ToolTip", "If the screen is an overlay. Screen under it will be visible until a screen that is not an overlay." },
	};
#endif
	void Z_Construct_UClass_UScreen_Statics::NewProp_bScreenIsAnOverlay_SetBit(void* Obj)
	{
		((UScreen*)Obj)->bScreenIsAnOverlay = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UScreen_Statics::NewProp_bScreenIsAnOverlay = { "bScreenIsAnOverlay", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UScreen), &Z_Construct_UClass_UScreen_Statics::NewProp_bScreenIsAnOverlay_SetBit, METADATA_PARAMS(Z_Construct_UClass_UScreen_Statics::NewProp_bScreenIsAnOverlay_MetaData, ARRAY_COUNT(Z_Construct_UClass_UScreen_Statics::NewProp_bScreenIsAnOverlay_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScreen_Statics::NewProp_bScreenIsLocked_MetaData[] = {
		{ "Category", "Screen" },
		{ "Comment", "//\x09Is this screen being forced to stay in stack? Screen can not be removed, only hidden.\n" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
		{ "ToolTip", "Is this screen being forced to stay in stack? Screen can not be removed, only hidden." },
	};
#endif
	void Z_Construct_UClass_UScreen_Statics::NewProp_bScreenIsLocked_SetBit(void* Obj)
	{
		((UScreen*)Obj)->bScreenIsLocked = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UScreen_Statics::NewProp_bScreenIsLocked = { "bScreenIsLocked", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UScreen), &Z_Construct_UClass_UScreen_Statics::NewProp_bScreenIsLocked_SetBit, METADATA_PARAMS(Z_Construct_UClass_UScreen_Statics::NewProp_bScreenIsLocked_MetaData, ARRAY_COUNT(Z_Construct_UClass_UScreen_Statics::NewProp_bScreenIsLocked_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UScreen_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScreen_Statics::NewProp_KeyToCloseScreenWith,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScreen_Statics::NewProp_bTakeOverInput,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScreen_Statics::NewProp_bAllowMultipleInstances,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScreen_Statics::NewProp_bScreenIsAnOverlay,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScreen_Statics::NewProp_bScreenIsLocked,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UScreen_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UScreen>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UScreen_Statics::ClassParams = {
		&UScreen::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UScreen_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_UScreen_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UScreen_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UScreen_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UScreen()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UScreen_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UScreen, 1834457770);
	template<> SCREENSTACK_API UClass* StaticClass<UScreen>()
	{
		return UScreen::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UScreen(Z_Construct_UClass_UScreen, &UScreen::StaticClass, TEXT("/Script/ScreenStack"), TEXT("UScreen"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UScreen);
	void UScreenStack::StaticRegisterNativesUScreenStack()
	{
		UClass* Class = UScreenStack::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FindScreenByType", &UScreenStack::execFindScreenByType },
			{ "GetOwnerPlayerController", &UScreenStack::execGetOwnerPlayerController },
			{ "GetScreenByType", &UScreenStack::execGetScreenByType },
			{ "GetTopMostScreen", &UScreenStack::execGetTopMostScreen },
			{ "HasScreen", &UScreenStack::execHasScreen },
			{ "PopScreen", &UScreenStack::execPopScreen },
			{ "PopTopScreen", &UScreenStack::execPopTopScreen },
			{ "PushScreenByClass", &UScreenStack::execPushScreenByClass },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UScreenStack_FindScreenByType_Statics
	{
		struct ScreenStack_eventFindScreenByType_Parms
		{
			TSubclassOf<UScreen>  screenType;
			UScreen* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_screenType;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScreenStack_FindScreenByType_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UScreenStack_FindScreenByType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ScreenStack_eventFindScreenByType_Parms, ReturnValue), Z_Construct_UClass_UScreen_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UScreenStack_FindScreenByType_Statics::NewProp_ReturnValue_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_FindScreenByType_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UScreenStack_FindScreenByType_Statics::NewProp_screenType = { "screenType", nullptr, (EPropertyFlags)0x0014000000000080, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ScreenStack_eventFindScreenByType_Parms, screenType), Z_Construct_UClass_UScreen_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScreenStack_FindScreenByType_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScreenStack_FindScreenByType_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScreenStack_FindScreenByType_Statics::NewProp_screenType,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScreenStack_FindScreenByType_Statics::Function_MetaDataParams[] = {
		{ "Category", "Screen" },
		{ "Comment", "//\x09""Find a screen of the type in the stack, if any.\n" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
		{ "ToolTip", "Find a screen of the type in the stack, if any." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UScreenStack_FindScreenByType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScreenStack, nullptr, "FindScreenByType", nullptr, nullptr, sizeof(ScreenStack_eventFindScreenByType_Parms), Z_Construct_UFunction_UScreenStack_FindScreenByType_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_FindScreenByType_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UScreenStack_FindScreenByType_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_FindScreenByType_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UScreenStack_FindScreenByType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UScreenStack_FindScreenByType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScreenStack_GetOwnerPlayerController_Statics
	{
		struct ScreenStack_eventGetOwnerPlayerController_Parms
		{
			APlayerController* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UScreenStack_GetOwnerPlayerController_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ScreenStack_eventGetOwnerPlayerController_Parms, ReturnValue), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScreenStack_GetOwnerPlayerController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScreenStack_GetOwnerPlayerController_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScreenStack_GetOwnerPlayerController_Statics::Function_MetaDataParams[] = {
		{ "Category", "Screen" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UScreenStack_GetOwnerPlayerController_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScreenStack, nullptr, "GetOwnerPlayerController", nullptr, nullptr, sizeof(ScreenStack_eventGetOwnerPlayerController_Parms), Z_Construct_UFunction_UScreenStack_GetOwnerPlayerController_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_GetOwnerPlayerController_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UScreenStack_GetOwnerPlayerController_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_GetOwnerPlayerController_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UScreenStack_GetOwnerPlayerController()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UScreenStack_GetOwnerPlayerController_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScreenStack_GetScreenByType_Statics
	{
		struct ScreenStack_eventGetScreenByType_Parms
		{
			TSubclassOf<UScreen>  screenType;
			UScreen* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_screenType;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScreenStack_GetScreenByType_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UScreenStack_GetScreenByType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ScreenStack_eventGetScreenByType_Parms, ReturnValue), Z_Construct_UClass_UScreen_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UScreenStack_GetScreenByType_Statics::NewProp_ReturnValue_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_GetScreenByType_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UScreenStack_GetScreenByType_Statics::NewProp_screenType = { "screenType", nullptr, (EPropertyFlags)0x0014000000000080, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ScreenStack_eventGetScreenByType_Parms, screenType), Z_Construct_UClass_UScreen_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScreenStack_GetScreenByType_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScreenStack_GetScreenByType_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScreenStack_GetScreenByType_Statics::NewProp_screenType,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScreenStack_GetScreenByType_Statics::Function_MetaDataParams[] = {
		{ "Category", "Screen" },
		{ "Comment", "//\x09""Find a screen of the type in the stack, if any.\n" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
		{ "ToolTip", "Find a screen of the type in the stack, if any." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UScreenStack_GetScreenByType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScreenStack, nullptr, "GetScreenByType", nullptr, nullptr, sizeof(ScreenStack_eventGetScreenByType_Parms), Z_Construct_UFunction_UScreenStack_GetScreenByType_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_GetScreenByType_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UScreenStack_GetScreenByType_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_GetScreenByType_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UScreenStack_GetScreenByType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UScreenStack_GetScreenByType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScreenStack_GetTopMostScreen_Statics
	{
		struct ScreenStack_eventGetTopMostScreen_Parms
		{
			UScreen* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScreenStack_GetTopMostScreen_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UScreenStack_GetTopMostScreen_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ScreenStack_eventGetTopMostScreen_Parms, ReturnValue), Z_Construct_UClass_UScreen_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UScreenStack_GetTopMostScreen_Statics::NewProp_ReturnValue_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_GetTopMostScreen_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScreenStack_GetTopMostScreen_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScreenStack_GetTopMostScreen_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScreenStack_GetTopMostScreen_Statics::Function_MetaDataParams[] = {
		{ "Category", "Screen" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UScreenStack_GetTopMostScreen_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScreenStack, nullptr, "GetTopMostScreen", nullptr, nullptr, sizeof(ScreenStack_eventGetTopMostScreen_Parms), Z_Construct_UFunction_UScreenStack_GetTopMostScreen_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_GetTopMostScreen_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UScreenStack_GetTopMostScreen_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_GetTopMostScreen_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UScreenStack_GetTopMostScreen()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UScreenStack_GetTopMostScreen_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScreenStack_HasScreen_Statics
	{
		struct ScreenStack_eventHasScreen_Parms
		{
			UScreen* screen;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_screen_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_screen;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UScreenStack_HasScreen_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ScreenStack_eventHasScreen_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UScreenStack_HasScreen_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ScreenStack_eventHasScreen_Parms), &Z_Construct_UFunction_UScreenStack_HasScreen_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScreenStack_HasScreen_Statics::NewProp_screen_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UScreenStack_HasScreen_Statics::NewProp_screen = { "screen", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ScreenStack_eventHasScreen_Parms, screen), Z_Construct_UClass_UScreen_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UScreenStack_HasScreen_Statics::NewProp_screen_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_HasScreen_Statics::NewProp_screen_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScreenStack_HasScreen_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScreenStack_HasScreen_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScreenStack_HasScreen_Statics::NewProp_screen,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScreenStack_HasScreen_Statics::Function_MetaDataParams[] = {
		{ "Category", "Screen" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UScreenStack_HasScreen_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScreenStack, nullptr, "HasScreen", nullptr, nullptr, sizeof(ScreenStack_eventHasScreen_Parms), Z_Construct_UFunction_UScreenStack_HasScreen_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_HasScreen_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UScreenStack_HasScreen_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_HasScreen_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UScreenStack_HasScreen()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UScreenStack_HasScreen_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScreenStack_PopScreen_Statics
	{
		struct ScreenStack_eventPopScreen_Parms
		{
			UScreen* screen;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_screen_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_screen;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UScreenStack_PopScreen_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ScreenStack_eventPopScreen_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UScreenStack_PopScreen_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ScreenStack_eventPopScreen_Parms), &Z_Construct_UFunction_UScreenStack_PopScreen_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScreenStack_PopScreen_Statics::NewProp_screen_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UScreenStack_PopScreen_Statics::NewProp_screen = { "screen", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ScreenStack_eventPopScreen_Parms, screen), Z_Construct_UClass_UScreen_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UScreenStack_PopScreen_Statics::NewProp_screen_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_PopScreen_Statics::NewProp_screen_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScreenStack_PopScreen_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScreenStack_PopScreen_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScreenStack_PopScreen_Statics::NewProp_screen,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScreenStack_PopScreen_Statics::Function_MetaDataParams[] = {
		{ "Category", "Screen" },
		{ "Comment", "//\x09Remove a screen from the stack\n" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
		{ "ToolTip", "Remove a screen from the stack" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UScreenStack_PopScreen_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScreenStack, nullptr, "PopScreen", nullptr, nullptr, sizeof(ScreenStack_eventPopScreen_Parms), Z_Construct_UFunction_UScreenStack_PopScreen_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_PopScreen_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UScreenStack_PopScreen_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_PopScreen_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UScreenStack_PopScreen()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UScreenStack_PopScreen_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScreenStack_PopTopScreen_Statics
	{
		struct ScreenStack_eventPopTopScreen_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UScreenStack_PopTopScreen_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ScreenStack_eventPopTopScreen_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UScreenStack_PopTopScreen_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ScreenStack_eventPopTopScreen_Parms), &Z_Construct_UFunction_UScreenStack_PopTopScreen_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScreenStack_PopTopScreen_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScreenStack_PopTopScreen_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScreenStack_PopTopScreen_Statics::Function_MetaDataParams[] = {
		{ "Category", "Screen" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UScreenStack_PopTopScreen_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScreenStack, nullptr, "PopTopScreen", nullptr, nullptr, sizeof(ScreenStack_eventPopTopScreen_Parms), Z_Construct_UFunction_UScreenStack_PopTopScreen_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_PopTopScreen_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UScreenStack_PopTopScreen_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_PopTopScreen_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UScreenStack_PopTopScreen()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UScreenStack_PopTopScreen_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScreenStack_PushScreenByClass_Statics
	{
		struct ScreenStack_eventPushScreenByClass_Parms
		{
			TSubclassOf<UScreen>  widgetClass;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_widgetClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UScreenStack_PushScreenByClass_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ScreenStack_eventPushScreenByClass_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UScreenStack_PushScreenByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ScreenStack_eventPushScreenByClass_Parms), &Z_Construct_UFunction_UScreenStack_PushScreenByClass_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UScreenStack_PushScreenByClass_Statics::NewProp_widgetClass = { "widgetClass", nullptr, (EPropertyFlags)0x0014000000000080, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ScreenStack_eventPushScreenByClass_Parms, widgetClass), Z_Construct_UClass_UScreen_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScreenStack_PushScreenByClass_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScreenStack_PushScreenByClass_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScreenStack_PushScreenByClass_Statics::NewProp_widgetClass,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScreenStack_PushScreenByClass_Statics::Function_MetaDataParams[] = {
		{ "Category", "Screen" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UScreenStack_PushScreenByClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScreenStack, nullptr, "PushScreenByClass", nullptr, nullptr, sizeof(ScreenStack_eventPushScreenByClass_Parms), Z_Construct_UFunction_UScreenStack_PushScreenByClass_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_PushScreenByClass_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UScreenStack_PushScreenByClass_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UScreenStack_PushScreenByClass_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UScreenStack_PushScreenByClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UScreenStack_PushScreenByClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UScreenStack_NoRegister()
	{
		return UScreenStack::StaticClass();
	}
	struct Z_Construct_UClass_UScreenStack_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnScreenPushed_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnScreenPushed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnScreenRemoval_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnScreenRemoval;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_screenStack_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_screenStack;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_screenStack_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UScreenStack_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_ScreenStack,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UScreenStack_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UScreenStack_FindScreenByType, "FindScreenByType" }, // 4124729413
		{ &Z_Construct_UFunction_UScreenStack_GetOwnerPlayerController, "GetOwnerPlayerController" }, // 2371983917
		{ &Z_Construct_UFunction_UScreenStack_GetScreenByType, "GetScreenByType" }, // 3312677021
		{ &Z_Construct_UFunction_UScreenStack_GetTopMostScreen, "GetTopMostScreen" }, // 3056870626
		{ &Z_Construct_UFunction_UScreenStack_HasScreen, "HasScreen" }, // 4268991722
		{ &Z_Construct_UFunction_UScreenStack_PopScreen, "PopScreen" }, // 3698343274
		{ &Z_Construct_UFunction_UScreenStack_PopTopScreen, "PopTopScreen" }, // 2132949222
		{ &Z_Construct_UFunction_UScreenStack_PushScreenByClass, "PushScreenByClass" }, // 864802419
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScreenStack_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "ScreenStack.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScreenStack_Statics::NewProp_OnScreenPushed_MetaData[] = {
		{ "Category", "Screen" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UScreenStack_Statics::NewProp_OnScreenPushed = { "OnScreenPushed", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UScreenStack, OnScreenPushed), Z_Construct_UDelegateFunction_ScreenStack_OnScreenPushedTostack__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UScreenStack_Statics::NewProp_OnScreenPushed_MetaData, ARRAY_COUNT(Z_Construct_UClass_UScreenStack_Statics::NewProp_OnScreenPushed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScreenStack_Statics::NewProp_OnScreenRemoval_MetaData[] = {
		{ "Category", "Screen" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UScreenStack_Statics::NewProp_OnScreenRemoval = { "OnScreenRemoval", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UScreenStack, OnScreenRemoval), Z_Construct_UDelegateFunction_ScreenStack_OnScreenRemovedFromStack__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UScreenStack_Statics::NewProp_OnScreenRemoval_MetaData, ARRAY_COUNT(Z_Construct_UClass_UScreenStack_Statics::NewProp_OnScreenRemoval_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScreenStack_Statics::NewProp_screenStack_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ScreenStack.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UScreenStack_Statics::NewProp_screenStack = { "screenStack", nullptr, (EPropertyFlags)0x0010008000000008, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UScreenStack, screenStack), METADATA_PARAMS(Z_Construct_UClass_UScreenStack_Statics::NewProp_screenStack_MetaData, ARRAY_COUNT(Z_Construct_UClass_UScreenStack_Statics::NewProp_screenStack_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UScreenStack_Statics::NewProp_screenStack_Inner = { "screenStack", nullptr, (EPropertyFlags)0x0000000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UScreen_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UScreenStack_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScreenStack_Statics::NewProp_OnScreenPushed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScreenStack_Statics::NewProp_OnScreenRemoval,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScreenStack_Statics::NewProp_screenStack,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScreenStack_Statics::NewProp_screenStack_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UScreenStack_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UScreenStack>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UScreenStack_Statics::ClassParams = {
		&UScreenStack::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UScreenStack_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_UScreenStack_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UScreenStack_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UScreenStack_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UScreenStack()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UScreenStack_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UScreenStack, 4267055972);
	template<> SCREENSTACK_API UClass* StaticClass<UScreenStack>()
	{
		return UScreenStack::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UScreenStack(Z_Construct_UClass_UScreenStack, &UScreenStack::StaticClass, TEXT("/Script/ScreenStack"), TEXT("UScreenStack"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UScreenStack);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
