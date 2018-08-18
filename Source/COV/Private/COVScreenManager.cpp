// Fill out your copyright notice in the Description page of Project Settings.

#include "COVScreenManager.h"
#include "COVScreen.h"
#include "COVBlueprintFunctionLibrary.h"
#include <Kismet/KismetSystemLibrary.h>
#include <GameFramework/PlayerController.h>
#include "COVPlayerController.h"

DEFINE_LOG_CATEGORY(COVScreenManager)

// Sets default values for this component's properties
UCOVScreenManager::UCOVScreenManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UCOVScreenManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

APlayerController* UCOVScreenManager::GetOwnerPlayerController() const
{
	AController* controller = Cast<AController>(GetOwner());

	ensureMsgf(IsValid(controller), TEXT("Owner of this component was not an AController! This component should be a component of AController."));
	
	return Cast<APlayerController>(controller);
}

bool UCOVScreenManager::PushScreenByClass(TSubclassOf<UCOVScreen> widgetClass)
{
	UCOVScreen* screen = CreateWidget<UCOVScreen>(GetOwnerPlayerController(), widgetClass);

	if (IsValid(screen))
	{
		screenStack.Add(screen);
		screen->AddToViewport(0);
		COV_LOG(COVScreenManager, Log, TEXT("Screen added to stack with the index (%d)."), screenStack.Num() - 1);

		return true;
	}

	COV_LOG(COVScreenManager, Warning, TEXT("Screen could not be added to stack!added to stack! Creation failed."));
	
	return false;
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

	if (!topMostScreen->GetIsScreenLocked())
	{
		UCOVScreen* poppedScreen = screenStack.Pop(true);

		if (topMostScreen != poppedScreen)
		{
			ensureMsgf(topMostScreen == poppedScreen, TEXT("Popped screen was not the top most screen!"));
			screenStack.Add(poppedScreen);
			
			return false;
		}

		poppedScreen->RemoveFromParent();
		COV_LOG(COVScreenManager, Log, TEXT("Screen popped from stack!"));
		OnScreenRemoval.Broadcast(poppedScreen);
	}
	
	return true;
}

// Called every frame
void UCOVScreenManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}