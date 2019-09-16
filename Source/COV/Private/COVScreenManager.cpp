// Fill out your copyright notice in the Description page of Project Settings.

#include "COVScreenManager.h"
#include "COVScreen.h"
#include "COVBlueprintFunctionLibrary.h"
#include <Kismet/KismetSystemLibrary.h>
#include <GameFramework/PlayerController.h>
#include "COVPlayerController.h"
#include <UObjectToken.h>

DEFINE_LOG_CATEGORY(COVScreenManager)

#define LOCTEXT_NAMESPACE "COVScreenManager"

// Sets default values for this component's properties
UCOVScreenManager::UCOVScreenManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UCOVScreenManager::BeginPlay()
{
	Super::BeginPlay();

	GetOwnerPlayerController();	
}

void UCOVScreenManager::UpdateScreenStackVisibilities_Internal()
{
	//	If the next screen in line is an overlay, reveal every screen under it until you hit one that is not an overlay.
	for (int x = (screenStack.Num() - 1); x >= 0; x--)
	{
		auto screen = screenStack[x];

		//	Set first one to always be visible
		if (x == screenStack.Num() - 1)
		{
			screen->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
			if (screen->GetShouldScreenTakeOverMouse())
			{
				GetOwnerPlayerController()->bShowMouseCursor = true;
				screen->SetUserFocus(GetOwnerPlayerController());

				FInputModeUIOnly input_mode;

				input_mode.SetWidgetToFocus(screen->TakeWidget());

				input_mode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
				
				GetOwnerPlayerController()->SetInputMode(input_mode);
			}
			else
			{
				GetOwnerPlayerController()->bShowMouseCursor = false;
				GetOwnerPlayerController()->SetInputMode(FInputModeGameOnly());
			}
		}
		else
		{
			//	If the screen above is an overlay, this screen should be visible as well no matter what if the one above is visible
			if (screenStack[x + 1]->GetIsScreenAnOverlay() && screenStack[x + 1]->GetVisibility() != ESlateVisibility::Hidden)
			{
				screen->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
			}
			else
			{
				screen->SetVisibility(ESlateVisibility::Hidden);
			}
		}
	}
}

APlayerController* UCOVScreenManager::GetOwnerPlayerController() const
{
	AController* controller = Cast<AController>(GetOwner());

	if (!ensureMsgf(IsValid(controller), TEXT("Owner of this component was not an AController! This component should be a component of AController.")))
	{
		FMessageLog("PIE").Error(FText::FromString("Owner ("))->AddToken(FUObjectToken::Create(GetOwner()))->AddToken(FTextToken::Create(FText::FromString(") of COVScreenmanager component does not inherit from APlayerController. Screen manager components can only be used as components for player controllers.")));
	}
	
	return Cast<APlayerController>(controller);
}

bool UCOVScreenManager::PushScreenByClass(TSubclassOf<UCOVScreen> widgetClass)
{	
	UCOVScreen* foundScreen = FindScreenOfType(widgetClass);

	bool bCanHaveMultipleInstances = Cast<UCOVScreen>(widgetClass->GetDefaultObject())->GetAllowMultipleInstances();

	//	If multiple screen can exist at the same time, allow creation
	if ((bCanHaveMultipleInstances) || (!bCanHaveMultipleInstances && !foundScreen))
	{
		UCOVScreen* screen = CreateWidget<UCOVScreen>(GetOwnerPlayerController(), widgetClass);
		FString widgetClassName = GetNameSafe(screen);

		if (!IsValid(screen))
		{
			COV_LOG(COVScreenManager, Warning, TEXT("Screen (%s) could not be added to stack. Creation failed."), *widgetClassName);
			FMessageLog("COVScreenManager").Error(FText::Format(NSLOCTEXT("ScreenManager", "ScreenManager", "Screen ({0}) could not be added to stack. Creation failed."), FText::FromString(widgetClassName)));

			return false;
		}

		screenStack.Add(screen);
		screen->AddToViewport(0);
		COV_LOG(COVScreenManager, Log, TEXT("Screen (%s) added to stack with the index (%d). Calling OnScreenPushed..."), *widgetClassName, screenStack.Num() - 1);
		OnScreenPushed.Broadcast(screen);
	}
	else
	{
		COV_LOG(COVScreenManager, Warning, TEXT("No new screens of type (%s) allowed. Pushing the screen to the top instead."), *GetNameSafe(widgetClass->StaticClass()));
		screenStack.Remove(foundScreen);
		screenStack.Add(foundScreen);
	}

	UpdateScreenStackVisibilities_Internal();

	return true;
}

bool UCOVScreenManager::PopTopScreen()
{
	if (screenStack.Num() == 0)
	{
		COV_LOG(COVScreenManager, Log, TEXT("Can't pop a screen. Screen stack is empty!"));
		
		return false;
	}

	int32 numberOfScreens = screenStack.Num();
	UCOVScreen* topMostScreen = screenStack[numberOfScreens - 1];
	FString widgetClassName = GetNameSafe(topMostScreen);

	if (!topMostScreen->GetIsScreenLocked())
	{
		PopScreen(topMostScreen);

		return true;
	}
	else
	{
		COV_LOG(COVScreenManager, Warning, TEXT("Screen (%s) could not be popped from the stack. The screen was locked."), *widgetClassName);
		
		return false;
	}
	
	return false;
}

bool UCOVScreenManager::PopScreen(UCOVScreen* screen)
{
	FString widgetClassName = GetNameSafe(screen);

	if (HasScreen(screen))
	{
		screenStack.RemoveSingleSwap(screen, true);
		UpdateScreenStackVisibilities_Internal();

		COV_LOG(COVScreenManager, Log, TEXT("Screen (%s) popped from stack. Broadcasting OnScreenRemoval..."), *widgetClassName);
		OnScreenRemoval.Broadcast(screen);
		screen->RemoveFromParent();
	}

	return true;
}

UCOVScreen* UCOVScreenManager::FindScreenOfType(TSubclassOf<UCOVScreen> screenType)
{
	UCOVScreen* foundScreen = nullptr;

	if (screenStack.Num() > 0)
	{
		for (auto screen : screenStack)
		{
			if (screen->IsA(screenType))
			{
				foundScreen = screen;
			}
		}
	}

	return foundScreen;
}

bool UCOVScreenManager::HasScreen(UCOVScreen* screen)
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

// Called every frame
void UCOVScreenManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}