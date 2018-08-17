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

	//	TDDO: make the z-order based on its position in the screen stack
	screen->AddToViewport(0);

	return true;
}

// Called every frame
void UCOVScreenManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}