// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ScreenStack.h"
#include <UObjectToken.h>

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
	//	If the next screen in line is an overlay, reveal every screen under it until you hit one that is not an overlay.
	for (int x = (screenStack.Num() - 1); x >= 0; x--)
	{
		auto screen = screenStack[x];

		if (x == screenStack.Num() - 1)
		{
			//	Is the screen hidden by someone else? If it is, don't touch its visibility
			if (screen->bShouldScreenBeShownWhenPossible)
			{
				//	Set first one to always be visible
				SetScreenVisible_Internal(screen);

				if (screen->GetShouldScreenTakeOverMouse())
				{
					screen->TakeOverInputControl();
				}
				else
				{
					screen->ReleaseInputControl();
				}
			}
			else
			{
				screen->ReleaseInputControl();
			}
		}
		else
		{
			//	If the screen above is an overlay, this screen should be visible as well no matter what if the one above is visible
			if (screenStack[x + 1]->GetIsScreenAnOverlay() && screenStack[x + 1]->GetVisibility() != ESlateVisibility::Hidden)
			{
				if (screen->bShouldScreenBeShownWhenPossible)
				{
					SetScreenVisible_Internal(screen);
				}
			}
			else
			{
				screen->SetVisibility(ESlateVisibility::Hidden);
			}
		}
	}
}

void UScreenStack::SetScreenVisible_Internal(UScreen* screen) const
{
	screen->bScreenStackManagerChangesVisibility = true;
	screen->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
}

APlayerController* UScreenStack::GetOwnerPlayerController() const
{
	AController* controller = Cast<AController>(GetOwner());

	if (!ensureMsgf(IsValid(controller), TEXT("Owner of this component was not an AController! This component should be a component of AController.")))
	{
		FMessageLog("PIE").Error(FText::FromString("Owner ("))->AddToken(FUObjectToken::Create(GetOwner()))->AddToken(FTextToken::Create(FText::FromString(") of COVScreenmanager component does not inherit from APlayerController. Screen manager components can only be used as components for player controllers.")));
	}

	return Cast<APlayerController>(controller);
}

UObject* UScreenStack::PushScreenByClass(const TSubclassOf<UScreen> widgetClass)
{
	if (!ensure(widgetClass))
	{
		return nullptr;
	}

	TArray<UScreen*> foundScreens = FindScreensOfType(widgetClass);

	bool bCanHaveMultipleInstances = Cast<UScreen>(widgetClass->GetDefaultObject())->GetAllowMultipleInstances();

	//	If multiple screen can exist at the same time, allow creation
	if ((foundScreens.Num() == 0) || ((foundScreens.Num() == 0) && bCanHaveMultipleInstances))
	{
		UScreen* screen = CreateWidget<UScreen>(GetOwnerPlayerController(), widgetClass);
		FString widgetClassName = GetNameSafe(screen);

		if (!IsValid(screen))
		{
			UE_LOG(ScreenStack, Warning, TEXT("Screen (%s) could not be added to stack. Creation failed."), *widgetClassName);
			FMessageLog("COVScreenManager").Error(FText::Format(NSLOCTEXT("ScreenManager", "ScreenManager", "Screen ({0}) could not be added to stack. Creation failed."), FText::FromString(widgetClassName)));

			return nullptr;
		}

		screenStack.Add(screen);
		//screen->AddToViewport(0);

		UE_LOG(ScreenStack, Log, TEXT("Screen (%s) added to stack with the index (%d). Calling OnScreenPushed..."), *widgetClassName, screenStack.Num() - 1);
		
		UpdateScreenStackVisibilities_Internal();

		OnScreenPushed.Broadcast(screen);

		return screen;
	}
	else
	{
		UE_LOG(ScreenStack, Log, TEXT("No new screens of type (%s) allowed."), *GetNameSafe(widgetClass->StaticClass()));

		//	There should only be one screen of this type. Push it to the top
		if (ensureMsgf(foundScreens.Num() == 1, TEXT("More than one screen of this type exists in the stack.")))
		{
			UE_LOG(ScreenStack, Log, TEXT("Pushing the existing screen of type (%s) to the top."), *GetNameSafe(widgetClass->StaticClass()));

			screenStack.Remove(foundScreens[0]);
			screenStack.Add(foundScreens[0]);
		}
	}

	UpdateScreenStackVisibilities_Internal();

	return nullptr;
}

void UScreenStack::LatentAddToViewport(UScreen* screen) const
{
	screen->AddToViewport(0);
}

bool UScreenStack::PopTopScreen()
{
	if (screenStack.Num() == 0)
	{
		UE_LOG(ScreenStack, Log, TEXT("Can't pop a screen. Screen stack is empty!"));

		return false;
	}

	int32 numberOfScreens = screenStack.Num();
	UScreen* topMostScreen = screenStack[numberOfScreens - 1];
	FString widgetClassName = GetNameSafe(topMostScreen);

	if (!topMostScreen->GetIsScreenLocked())
	{
		PopScreen(topMostScreen);

		return true;
	}
	else
	{
		UE_LOG(ScreenStack, Log, TEXT("Screen (%s) could not be popped from the stack. The screen was locked."), *widgetClassName);

		return false;
	}

	return false;
}

UScreen* UScreenStack::GetTopMostScreen()
{
	return nullptr;
}

bool UScreenStack::PopScreen(UScreen* screen)
{
	FString widgetClassName = GetNameSafe(screen);

	if (HasScreen(screen))
	{
		//	If screen is locked, don't pop it
		if (screen->GetIsScreenLocked())
		{
			UE_LOG(ScreenStack, Log, TEXT("Screen (%s) could not be popped from the stack. The screen was locked."), *GetNameSafe(screen));

			return false;
		}

		screenStack.RemoveSingleSwap(screen, true);
		UpdateScreenStackVisibilities_Internal();

		UE_LOG(ScreenStack, Log, TEXT("Screen (%s) popped from stack. Broadcasting OnScreenRemoval..."), *widgetClassName);
		OnScreenRemoval.Broadcast(screen);
		screen->RemoveFromParent();

		return true;
	}

	return false;
}

TArray<UScreen*> UScreenStack::FindScreensOfType(TSubclassOf<UScreen> screenType)
{
	TArray<UScreen*> foundScreens;

	if (screenStack.Num() > 0)
	{
		for (auto screen : screenStack)
		{
			if (screen->IsA(screenType))
			{
				foundScreens.Add(screen);
			}
		}
	}

	return foundScreens;
}

TArray<UScreen*> UScreenStack::GetScreensOfType(TSubclassOf<UScreen> screenType)
{
	return FindScreensOfType(screenType);
}

bool UScreenStack::HasScreen(UScreen* screen)
{
	if (screenStack.Num() > 0)
	{
		for (auto screenx : screenStack)
		{
			if (screenx == screen)
			{
				return true;
			}
		}
	}

	return false;
}

void UScreenStack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

UScreen::UScreen(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
	bIsFocusable = true;
}

void UScreen::ReleaseInputControl()
{
	GetOwningPlayer()->bShowMouseCursor = false;
	GetOwningPlayer()->SetInputMode(FInputModeGameOnly());
}

void UScreen::TakeOverInputControl()
{
	GetOwningPlayer()->bShowMouseCursor = true;
	SetUserFocus(GetOwningPlayer());

	FInputModeUIOnly input_mode;

	input_mode.SetWidgetToFocus(TakeWidget());
	input_mode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	GetOwningPlayer()->SetInputMode(input_mode);
}

FReply UScreen::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	FKey key = InKeyEvent.GetKey();

	if (key == KeyToCloseScreenWith)
	{
		UE_LOG(ScreenStack, Log, TEXT("Screen escape key (%s) pressed. Popping screen (%s) from stack."), *KeyToCloseScreenWith.ToString(), *GetNameSafe(this));
		UScreenStack* screenManager = Cast<UScreenStack>(GetOwningPlayer()->GetComponentByClass(UScreenStack::StaticClass()));

		if (IsValid(screenManager))
		{
			//	Pop the screen!
			screenManager->PopScreen(this);
		}
		else
		{
			UE_LOG(ScreenStack, Error, TEXT("No screen stack component found from the owning player (%s) of this widget (%s). Could not escape currently displayed screen.."), *GetNameSafe(this));
			FMessageLog("COVScreen").Error(FText::FromString("No screen stack component found from the owning player of this widget. Could not escape currently displayed screen."))->AddToken(FUObjectToken::Create(this));
		}
	}

	FReply result(FReply::Handled());

	return result;
}

void UScreen::SetVisibility(ESlateVisibility visibility)
{
	if (bScreenStackManagerChangesVisibility)
	{
		bScreenStackManagerChangesVisibility = false;
		Super::SetVisibility(visibility);

		return;
	}

	bShouldScreenBeShownWhenPossible = ((visibility != ESlateVisibility::Hidden) && (visibility != ESlateVisibility::Collapsed));

	Super::SetVisibility(visibility);
}