// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ScreenStack.h"

#define LOCTEXT_NAMESPACE "FScreenStackModule"

void FScreenStackModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FScreenStackModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FScreenStackModule, ScreenStack)


DEFINE_LOG_CATEGORY(ScreenStack)


UScreenStack::UScreenStack()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

void UScreenStack::BeginPlay()
{
	Super::BeginPlay();

	GetOwnerPlayerController();
}

void UScreenStack::UpdateScreenStackVisibilities_Internal()
{

}

void UScreenStack::SetScreenVisible_Internal(UScreen* screen) const
{

}

APlayerController* UScreenStack::GetOwnerPlayerController() const
{
	return nullptr;
}

bool UScreenStack::PushScreenByClass(TSubclassOf<UScreen> widgetClass)
{
	return false;
}

bool UScreenStack::PopTopScreen()
{
	return false;
}

UScreen* UScreenStack::GetTopMostScreen()
{
	return nullptr;
}

bool UScreenStack::PopScreen(UScreen* screen)
{
	return false;
}

UScreen* UScreenStack::FindScreenByType(TSubclassOf<UScreen> screenType)
{
	return nullptr;
}

UScreen* UScreenStack::GetScreenByType(TSubclassOf<UScreen> screenType)
{
	return nullptr;
}

bool UScreenStack::HasScreen(UScreen* screen)
{
	return false;
}

void UScreenStack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

}

UScreen::UScreen(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
	bIsFocusable = true;
}

void UScreen::ReleaseInputControl()
{

}

void UScreen::TakeOverInputControl()
{

}

FReply UScreen::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	return 	FReply::Handled();
}

void UScreen::SetVisibility(ESlateVisibility visibility)
{

}
