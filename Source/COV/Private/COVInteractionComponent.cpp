// Fill out your copyright notice in the Description page of Project Settings.

#include "COVInteractionComponent.h"
#include "COVFocusComponent.h"
#include <GameFramework/Actor.h>
#include <MessageLog.h>
#include <UObjectToken.h>
#include "UE4Helpers.h"

DEFINE_LOG_CATEGORY(COVInteractionComponent)
#define LOCTEXT_NAMESPACE "Interaction"

// Sets default values for this component's properties
UCOVInteractionComponent::UCOVInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UCOVInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	//	Get and cache the owner focus component, if present
	OwnerFocusComponent = TryGetOwnerFocusComponent();
}

UCOVFocusComponent* UCOVInteractionComponent::TryGetOwnerFocusComponent() const
{
	//	In order to find an actor to interact with, we want to use the focus manager component if it is present
	AActor* owner = GetOwner();

	if (IsValid(owner))
	{
		UCOVFocusComponent* focusComponent = Cast<UCOVFocusComponent>(owner->GetComponentByClass(UCOVFocusComponent::StaticClass()));
		return focusComponent;
	}

	return nullptr;
}

AActor* UCOVInteractionComponent::TryGetInteractedActor() const
{
	if (OwnerFocusComponent.IsValid())
	{
		return OwnerFocusComponent->GetFocusedActor();
	}

	COV_LOG(COVInteractionComponent, Warning, TEXT("No Focus Component found on owner of this component."));
	FMessageLog("COVBlueprintFunctionLibrary").Warning(FText::Format(LOCTEXT("Interaction", "No focus component found on owner ({0})."), FText::FromString(GetNameSafe(GetOwner()))))->AddToken(FUObjectToken::Create(GetOwner()));

	return nullptr;
}

// Called every frame
void UCOVInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

