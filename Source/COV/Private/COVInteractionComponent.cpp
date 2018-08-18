// Fill out your copyright notice in the Description page of Project Settings.

#include "COVInteractionComponent.h"
#include "COVFocusComponent.h"
#include <GameFramework/Actor.h>
#include "COVBlueprintFunctionLibrary.h"

DEFINE_LOG_CATEGORY(COVInteractionComponent)

// Sets default values for this component's properties
UCOVInteractionComponent::UCOVInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UCOVInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

AActor* UCOVInteractionComponent::TryGetInteractedActor() const
{
	//	In order to find an actor to interact with, we want to use the focus manager component if it is present
	AActor* owner = GetOwner();
	UCOVFocusComponent* focusComponent = Cast<UCOVFocusComponent>(owner->GetComponentByClass(UCOVFocusComponent::StaticClass()));
	if (IsValid(focusComponent))
	{
		return focusComponent->GetCachedFocusedActor();
	}

	COV_LOG(COVInteractionComponent, Warning, TEXT("No Focus Component found on owner of this component."));
	return nullptr;
}

// Called every frame
void UCOVInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

