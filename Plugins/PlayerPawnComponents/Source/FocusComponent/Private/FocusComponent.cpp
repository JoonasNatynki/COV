// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "FocusComponent.h"
#include <DrawDebugHelpers.h>
#include <Kismet/KismetSystemLibrary.h>
#include "FocusableComponent.h"
#include <Engine/EngineTypes.h>
#include <MessageLog.h>
#include <GameFramework/Controller.h>
#include <GameFramework/Pawn.h>
#include <UObjectToken.h>

#define LOCTEXT_NAMESPACE "FFocusComponentModule"

void FFocusComponentModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FFocusComponentModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

// Fill out your copyright notice in the Description page of Project Settings.



static TAutoConsoleVariable<int32> CVarShowFocusDebugs(TEXT("COV.DebugFocusPoint"),
	0,
	TEXT("Show the point of focus in the world."));

DEFINE_LOG_CATEGORY(LogFocus)

// Sets default values for this component's properties
UFocusComponent::UFocusComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickGroup = ETickingGroup::TG_PostUpdateWork;
}

// Called when the game starts
void UFocusComponent::BeginPlay()
{
	Super::BeginPlay();
}

APlayerCameraManager* UFocusComponent::TryGetPawnCameraManager(const APawn* pawn) const
{
	if (!ensureMsgf(IsValid(pawn), TEXT("The pawn wasn't valid anymore.")))
	{
		FMessageLog("PIE").Error(FText::FromString("Could not get pawn camera manager. Pawn wasn't valid."));
		return nullptr;
	}
	AController* temp = pawn->GetController();
	APlayerController* playerController = Cast<APlayerController>(pawn->GetController());

	if (!IsValid(playerController))
	{
		//FMessageLog("PIE").Error(FText::FromString("Could not get pawn camera manager. The pawn's controller was not valid."))->AddToken(FUObjectToken::Create(pawn));
		return nullptr;
	}


	if (!ensureMsgf(IsValid(playerController->PlayerCameraManager), TEXT("The player camera manager was not valid.")))
	{
		FMessageLog("PIE").Error(FText::FromString("Could not get pawn camera manager. The camera manager was not valid for pawn."))->AddToken(FUObjectToken::Create(pawn));
		return nullptr;
	}

	return playerController->PlayerCameraManager;
}

TWeakObjectPtr<AActor> UFocusComponent::UpdateFocusedActor_Internal()
{
	TWeakObjectPtr<AActor> focusedActor;
	FHitResult RV_Hit = CastCrossHairLineTrace(GetOwner(), FocusingMaxDistance);
	FocusWorldLocation = RV_Hit.ImpactPoint;
	TArray<AActor*> actorsOverlapping;

	FVector startLoc;
	FVector endLoc;

	APawn* ownerPawn = Cast<APawn>(GetOwner());

	if (ownerPawn)
	{
		AActor* ownerCameraManagerActor = Cast<AActor>(TryGetPawnCameraManager(ownerPawn));
		if (ownerCameraManagerActor)
		{
			startLoc = ownerCameraManagerActor->GetActorLocation();
			endLoc = startLoc + (ownerCameraManagerActor->GetActorForwardVector() * FocusingMaxDistance);
		}
	}

	TArray<FHitResult> hits;
	TArray<AActor*> actorsToIgnore;
	actorsToIgnore.Add(GetOwner());

	EDrawDebugTrace::Type debugTrace = (bShowDebug) ? (EDrawDebugTrace::ForDuration) : (EDrawDebugTrace::None);

	UKismetSystemLibrary::SphereTraceMulti(this, startLoc, endLoc, FocusingMaxArea, UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel1), false, actorsToIgnore, debugTrace, hits, true, FLinearColor::Green, FLinearColor::Red, GetWorld()->GetDeltaSeconds());

	if (hits.Num() > 0)
	{
		for (auto& hit : hits)
		{
			AActor* hitActor = hit.Actor.Get();

			if (IsValid(hitActor))
			{
				actorsOverlapping.Add(hitActor);
			}
		}
	}

	//	Now go through all the overlapping actors and figure out the best candidate that the player might actually intend on focusing
	if (actorsOverlapping.Num() > 0)
	{
		TWeakObjectPtr<AActor> bestCandidate = FindClosestFocusedActor_Internal(actorsOverlapping);
		focusedActor = bestCandidate;
	}

	return focusedActor;
}

AActor* UFocusComponent::GetFocusedActor()
{
	UpdateFocusedActor();
	return CachedFocusedActor;
}

AActor* UFocusComponent::GetCachedFocusedActor() const
{
	return CachedFocusedActor;
}

void UFocusComponent::UpdateFocusedActor()
{
	//	If cached actor was not found, try to find a new actor to focus at
	TWeakObjectPtr<AActor> newFocusActor = UpdateFocusedActor_Internal();
	
	bool bFocusActorHasChanged = (CachedFocusedActor != newFocusActor) ? (true) : (false);

	if (bFocusActorHasChanged)
	{
		CachedFocusedActor = newFocusActor.Get();
		UE_LOG(LogTemp, Log, TEXT("Focus actor changed to (%s)."), *GetNameSafe(CachedFocusedActor));
		OnFocusedActorChanged.Broadcast(newFocusActor.Get());
	}
}

const void UFocusComponent::DrawDebugs(float deltaTime) const
{
	DrawDebugSphere(GetWorld(), CastCrossHairLineTrace(GetOwner(), FocusingMaxDistance).ImpactPoint, 5.0f, 4, FColor::Magenta, false, -1.0f, 0, 2.0f);
	DrawDebugSphere(GetWorld(), CastCrossHairLineTrace(GetOwner(), FocusingMaxDistance).ImpactPoint, FocusingMaxArea, 16, FColor::Cyan, false, -1.0f, 0, 2.0f);
}

const TWeakObjectPtr<AActor> UFocusComponent::FindClosestFocusedActor_Internal(TArray<AActor*> overlappingActors) const
{
	TWeakObjectPtr<AActor> candidate;
	float bestDistance = 99999.0f;

	for (auto& actor : overlappingActors)
	{
		float distanceToFocusWorldLocation = (FocusWorldLocation - actor->GetActorLocation()).Size();
		float distanceToActorWhoIsFocusing = (GetOwner()->GetActorLocation() - actor->GetActorLocation()).Size();

		//	If using the developer mode, ignore every setting and just focus on everything.
		if (!bDeveloperMode)
		{
			//	Whether or not to only focus on actors with the FocusableComponent and if they are focusable or not
			if (bFocusOnlyOnFocusables)
			{
				UFocusableComponent* focusableComponent = Cast<UFocusableComponent>(actor->GetComponentByClass(UFocusableComponent::StaticClass()));

				if (!IsValid(focusableComponent) || !focusableComponent->IsFocusable() || (distanceToActorWhoIsFocusing > focusableComponent->GetFocusDistance()))
				{
					continue;
				}
			}
		}

		if (distanceToFocusWorldLocation < bestDistance)
		{
			candidate = actor;
			bestDistance = distanceToFocusWorldLocation;
		}
	}

	return candidate;
}

// Called every frame
void UFocusComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateFocusedActor();

	bShowDebug = CVarShowFocusDebugs.GetValueOnGameThread() == 1 ? true:false;

	if ((bShowDebug) && !FocusWorldLocation.IsZero())
	{
		DrawDebugs(DeltaTime);
	}
}




#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFocusComponentModule, FocusComponent)