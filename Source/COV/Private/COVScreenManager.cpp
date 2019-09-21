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
	UCOVScreen* foundScreen = FindScreenByType(widgetClass);

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
		COV_LOG(COVScreenManager, Log, TEXT("No new screens of type (%s) allowed. Pushing the screen to the top instead."), *GetNameSafe(widgetClass->StaticClass()));
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
		COV_LOG(COVScreenManager, Log, TEXT("Screen (%s) could not be popped from the stack. The screen was locked."), *widgetClassName);
		
		return false;
	}
	
	return false;
}

bool UCOVScreenManager::PopScreen(UCOVScreen* screen)
{
	FString widgetClassName = GetNameSafe(screen);

	if (HasScreen(screen))
	{
		//	If screen is locked, don't pop it
		if (screen->GetIsScreenLocked())
		{
			COV_LOG(COVScreenManager, Log, TEXT("Screen (%s) could not be popped from the stack. The screen was locked."), *GetNameSafe(screen));

			return false;
		}

		screenStack.RemoveSingleSwap(screen, true);
		UpdateScreenStackVisibilities_Internal();

		COV_LOG(COVScreenManager, Log, TEXT("Screen (%s) popped from stack. Broadcasting OnScreenRemoval..."), *widgetClassName);
		OnScreenRemoval.Broadcast(screen);
		screen->RemoveFromParent();

		return true;
	}

	return false;
}

UCOVScreen* UCOVScreenManager::FindScreenByType(TSubclassOf<UCOVScreen> screenType)
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

UCOVScreen* UCOVScreenManager::GetScreenByType(TSubclassOf<UCOVScreen> screenType)
{
	return FindScreenByType(screenType);
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

void UCOVScreenManager::SetScreenVisible_Internal(UCOVScreen* screen) const
{
	screen->bScreenStackManagerChangesVisibility = true;
	screen->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
}

// Called every frame
void UCOVScreenManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}