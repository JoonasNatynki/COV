// Fill out your copyright notice in the Description page of Project Settings.

#include "COVFocusComponent.h"
#include "COVBlueprintFunctionLibrary.h"

// Sets default values for this component's properties
UCOVFocusComponent::UCOVFocusComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCOVFocusComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

TWeakObjectPtr<AActor> UCOVFocusComponent::UpdateFocusedActor_Internal() const
{
	//	Just simply get the actor pointed at
	FHitResult RV_Hit= UCOVBlueprintFunctionLibrary::CastCrossHairLineTrace(GetOwner(), _focusingMaxDistance);
	return RV_Hit.Actor;
}

AActor* UCOVFocusComponent::GetFocusedActor()
{
	UpdateFocusedActor();
	return _cachedFocusedActor;
}

void UCOVFocusComponent::UpdateFocusedActor()
{
	//	If cached actor was not found, try to find a new actor to focus at
	TWeakObjectPtr<AActor> newFocusActor = UpdateFocusedActor_Internal();
	
	if (_cachedFocusedActor != newFocusActor)
	{
		_cachedFocusedActor = newFocusActor.Get();
		OnFocusedActorChanged.Broadcast(newFocusActor.Get());
	}
}

// Called every frame
void UCOVFocusComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

