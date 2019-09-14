// Fill out your copyright notice in the Description page of Project Settings.

#include "COVFocusComponent.h"
#include "COVBlueprintFunctionLibrary.h"
#include <DrawDebugHelpers.h>
#include <Kismet/KismetSystemLibrary.h>
#include "FocusableComponent.h"

// Sets default values for this component's properties
UCOVFocusComponent::UCOVFocusComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickGroup = ETickingGroup::TG_PostUpdateWork;
}

// Called when the game starts
void UCOVFocusComponent::BeginPlay()
{
	Super::BeginPlay();
}

TWeakObjectPtr<AActor> UCOVFocusComponent::UpdateFocusedActor_Internal()
{
	TWeakObjectPtr<AActor> focusedActor;
	//	Just simply get the actor pointed at
	FHitResult RV_Hit = UCOVBlueprintFunctionLibrary::CastCrossHairLineTrace(GetOwner(), _focusingMaxDistance);
	_focusWorldLocation = RV_Hit.ImpactPoint;

	if (!_focusWorldLocation.IsZero())
	{
		TArray<AActor*> actorsOverlapping;
		TArray<AActor*> actorsToIgnore;
		actorsToIgnore.Add(GetOwner());
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
		UKismetSystemLibrary::SphereOverlapActors(GetOwner(), _focusWorldLocation, _focusingMaxArea, ObjectTypes, nullptr, actorsToIgnore, actorsOverlapping);

		//	Now go through all the overlapping actors and figure out the best candidate that the player might actually intend on focusing
		if (actorsOverlapping.Num() > 0)
		{
			TWeakObjectPtr<AActor> bestCandidate = FindClosestFocusedActor_Internal(actorsOverlapping);
			focusedActor = bestCandidate;
		}
	}

	return focusedActor;
}

AActor* UCOVFocusComponent::GetFocusedActor()
{
	UpdateFocusedActor();
	return _cachedFocusedActor;
}

AActor* UCOVFocusComponent::GetCachedFocusedActor() const
{
	return _cachedFocusedActor;
}

void UCOVFocusComponent::UpdateFocusedActor()
{
	//	If cached actor was not found, try to find a new actor to focus at
	TWeakObjectPtr<AActor> newFocusActor = UpdateFocusedActor_Internal();
	
	bool bFocusActorHasChanged = _cachedFocusedActor != newFocusActor ? true : false;

	if (bFocusActorHasChanged)
	{
		_cachedFocusedActor = newFocusActor.Get();
		COV_LOG(LogTemp, Log, TEXT("Focus actor changed to (%s)."), *GetNameSafe(_cachedFocusedActor));
		OnFocusedActorChanged.Broadcast(newFocusActor.Get());
	}
}

const void UCOVFocusComponent::DrawDebugs(float deltaTime) const
{
	DrawDebugSphere(GetWorld(), UCOVBlueprintFunctionLibrary::CastCrossHairLineTrace(GetOwner(), _focusingMaxDistance).ImpactPoint, 5.0f, 4, FColor::Magenta, false, -1.0f, 0, 2.0f);

	DrawDebugSphere(GetWorld(), UCOVBlueprintFunctionLibrary::CastCrossHairLineTrace(GetOwner(), _focusingMaxDistance).ImpactPoint, _focusingMaxArea, 16, FColor::Cyan, false, -1.0f, 0, 2.0f);
}

const TWeakObjectPtr<AActor> UCOVFocusComponent::FindClosestFocusedActor_Internal(TArray<AActor*> overlappingActors) const
{
	TWeakObjectPtr<AActor> candidate;
	float bestDistance = 99999.0f;

	for (auto& actor : overlappingActors)
	{
		//	Whether or not to only focus on actors with the FocusableComponent and if they are focusable or not
		if (bFocusOnlyOnFocusables)
		{
			UFocusableComponent* focusableComponent = Cast<UFocusableComponent>(actor->GetComponentByClass(UFocusableComponent::StaticClass()));

			if (!IsValid(focusableComponent) || !focusableComponent->IsFocusable())
			{
				continue;
			}
		}

		float thisDistance = (_focusWorldLocation - actor->GetActorLocation()).Size();
		if (thisDistance < bestDistance)
		{
			candidate = actor;
			bestDistance = thisDistance;
		}
	}

	return candidate;
}

// Called every frame
void UCOVFocusComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateFocusedActor();

	bool bDebugShowFocusPoint = CVarShowFocusDebugs.GetValueOnGameThread() == 1 ? true:false;

	if ((bDebugShowFocusPoint || bShowDebug) && !_focusWorldLocation.IsZero())
	{
		DrawDebugs(DeltaTime);
	}
}

