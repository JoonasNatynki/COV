// Fill out your copyright notice in the Description page of Project Settings.


#include "COVCameraComponent.h"
#include <GameFramework/Pawn.h>

UCOVCameraComponent::UCOVCameraComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetComponentTickEnabled(true);
}

class APawn* UCOVCameraComponent::GetOwnerPawn() const
{
	APawn* ownerPawn = Cast<APawn>(GetOwner());
	ensure(IsValid(ownerPawn));
	return ownerPawn;
}

void UCOVCameraComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}
