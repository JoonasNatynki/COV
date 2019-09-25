// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include <UserWidget.h>
#include <InputCoreTypes.h>
#include <Kismet/BlueprintFunctionLibrary.h>
#include "GISBlueprintFunctionLibrary.generated.h"

class FScreenStackRuntimeModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};



template< class T >
T* CreateScreen(APlayerController* OwningPlayer, UClass* UserWidgetClass)
{
	if (!UserWidgetClass->IsChildOf(UScreen::StaticClass()))
	{
		return nullptr;
	}

	// Assign the outer to the game instance if it exists, otherwise use the player controller's world
	UWorld* World = OwningPlayer->GetWorld();
	StaticCast<UObject*>(World);
	UScreen* NewWidget = CreateWidget<UScreen>(UserWidgetClass, OwningPlayer);
	return Cast<T>(NewWidget);
}


class SCREENSTACKRUNTIME_API UGISBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", FriendlyName = "Push screen by class", BlueprintInternalUseOnly = "true"), Category = "Screen stack")
		static bool PushScreenByClass(UObject* WorldContextObject, TSubclassOf<UScreen> screenType, UScreenStack* screenStack)
	{
		CreateScreen(screenStack->GetOwner(), screenType);
		return false;
	};
};