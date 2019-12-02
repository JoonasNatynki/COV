// Fill out your copyright notice in the Description page of Project Settings.


#include "COVCameraComponent.h"
#include <GameFramework/Pawn.h>
#include <Kismet/KismetMathLibrary.h>
#include "UE4Helpers.h"

DEFINE_LOG_CATEGORY(LogCamera)

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

void UCOVCameraComponent::UpdateCameraTransform(const float deltaTime)
{
	//	Position
	FVector playerLocation = GetOwner()->GetActorLocation();
	FVector cameraLocationAfterOffset = playerLocation + CameraPlayerDefaultOffset;
	//	Now add in the rotation location offset
	cameraLocationAfterOffset = UE4CodeHelpers::RotateVectorAroundPoint(cameraLocationAfterOffset, playerLocation, RotationOffset);

	FVector currentCameraLocation = GetComponentLocation();
	FVector finalCameraLocationResult = UKismetMathLibrary::VLerp(currentCameraLocation, cameraLocationAfterOffset, CameraTransformLerpSpeed);
	SetWorldLocation(finalCameraLocationResult);

	//	Rotation
	FRotator playerRotation = GetOwner()->GetActorRotation();
	FRotator cameraCurrentRotation = GetComponentRotation();
	FRotator cameraEndRotation = UKismetMathLibrary::FindLookAtRotation(finalCameraLocationResult, playerLocation);

	SetWorldRotation(cameraEndRotation);
}

void UCOVCameraComponent::RotateCamera(const ECameraRotation direction)
{
	FRotator rot = direction == (ECameraRotation::Clockwise) ? (FRotator(0.0f, DegreesPerRotation, 0.0f)) : (FRotator(0.0f, -DegreesPerRotation, 0.0f));
	RotationOffset = RotationOffset + rot;
}

void UCOVCameraComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateCameraTransform(DeltaTime);

	UE_LOG(LogCamera, Log, TEXT("%s"), (bIsAnimating)?(TEXT("TRUE")):(TEXT("FALSE")));
}