// Fill out your copyright notice in the Description page of Project Settings.

#include "COVDoorComponent.h"
#include <UnrealNetwork.h>
#include <Kismet/KismetMathLibrary.h>
#include <Components/SceneComponent.h>

// Sets default values for this component's properties
UCOVDoorComponent::UCOVDoorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bReplicates = true;
}


// Called when the game starts
void UCOVDoorComponent::BeginPlay()
{
	Super::BeginPlay();
}

//	Required for network replication of variables
void UCOVDoorComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty, FDefaultAllocator>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(UCOVDoorComponent, _doorState, COND_SkipOwner);
}

void UCOVDoorComponent::OnRep_DoorState()
{
	OnDoorStateChanged.Broadcast(_doorState);
}

void UCOVDoorComponent::UpdateDoorState()
{
	EDoorState newDoorState;

	if (_doorStateAlpha <= _doorClosedAlphaThreshold)
	{
		newDoorState = EDoorState::Closed;
	}

	if (_doorStateAlpha >= _doorOpenAlphaThreshold)
	{
		newDoorState = EDoorState::Open;
	}

	SetDoorState(newDoorState);
}

void UCOVDoorComponent::SetDoorState(EDoorState doorState)
{
	_doorState = doorState;
	OnRep_DoorState();
}

void UCOVDoorComponent::SetDoorStateAlpha(float alpha)
{
	_doorStateAlpha = alpha;
	FTransform tempTrans = UKismetMathLibrary::TEase(_initialClosedTransform, _finalOpenTransform, _doorStateAlpha, EEasingFunc::EaseInOut, 2, 2);
	_doorHinge->SetRelativeTransform(tempTrans);
	UpdateDoorState();
}

void UCOVDoorComponent::SetInitialClosedTransform(FTransform openTransform)
{
	_initialClosedTransform = openTransform;
}

void UCOVDoorComponent::SetFinalOpenTransform(FTransform finalTransform)
{
	_finalOpenTransform = finalTransform;
}

void UCOVDoorComponent::SetDoorHinge(USceneComponent* doorHinge)
{
	_doorHinge = doorHinge;
}

EDoorState UCOVDoorComponent::GetDoorState() const
{
	return _doorState;
}

float UCOVDoorComponent::GetDoorStateAlpha() const
{
	return _doorStateAlpha;
}

FTransform UCOVDoorComponent::GetInitialOpenTransform() const
{
	return _initialClosedTransform;
}

FTransform UCOVDoorComponent::GetFinalClosedTransform() const
{
	return _finalOpenTransform;
}

// Called every frame
void UCOVDoorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

