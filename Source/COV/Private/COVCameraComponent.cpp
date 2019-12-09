// Fill out your copyright notice in the Description page of Project Settings.


#include "COVCameraComponent.h"
#include <GameFramework/Pawn.h>
#include <Kismet/KismetMathLibrary.h>
#include "UE4Helpers.h"

DEFINE_LOG_CATEGORY(LogCamera)

UCOVCameraComponent::UCOVCameraComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	if (IsValid(GetOwner()) && !GetOwner()->HasAuthority())
	{
		SetComponentTickEnabled(true);
	}
}

class APawn* UCOVCameraComponent::GetOwnerPawn() const
{
	APawn* ownerPawn = Cast<APawn>(GetOwner());
	ensure(IsValid(ownerPawn));
	return ownerPawn;
}

FORCEINLINE const FVector UCOVCameraComponent::GetCameraDefaultLocation() const
{
	const FVector playerLocation = GetOwner()->GetActorLocation();
	const FVector cameraDefaultLocation = playerLocation + CameraPlayerDefaultOffset;

	return cameraDefaultLocation;
}

FORCEINLINE const FVector UCOVCameraComponent::GetCameraDesiredLocation() const
{
	const FVector playerLocation = GetOwner()->GetActorLocation();
	const FVector cameraDefaultLocation = GetCameraDefaultLocation();
	const FVector cameraTargetLocation = UE4CodeHelpers::RotateVectorAroundPoint(cameraDefaultLocation, playerLocation, CameraDesiredRotationSetting);

	return cameraTargetLocation;
}

FORCEINLINE const FVector UCOVCameraComponent::GetCameraCurrentLocation() const
{
	return GetComponentLocation();
}

FORCEINLINE const FRotator UCOVCameraComponent::GetCameraCurrentRotation() const
{
	return GetComponentRotation();
}

FORCEINLINE const FVector UCOVCameraComponent::GetPlayerLocation() const
{
	return GetOwner()->GetActorLocation();
}

FORCEINLINE void UCOVCameraComponent::UpdateCameraTransform(const float deltaTime)
{
	//	Location
	const FVector currentCameraLocation = GetCameraCurrentLocation();
	const FVector desiredCameraLocation = GetCameraDesiredLocation();
	const FVector finalCameraLocationResult = UKismetMathLibrary::VLerp(currentCameraLocation, desiredCameraLocation, CameraTransformLerpSpeed);
	SetWorldLocation(finalCameraLocationResult);

	//	Rotation
	const FRotator currentCameraRotation = GetCameraCurrentRotation();
	const FVector playerLocation = GetPlayerLocation();
	const FRotator desiredCameraRotation = UKismetMathLibrary::FindLookAtRotation(finalCameraLocationResult, playerLocation);
	SetWorldRotation(desiredCameraRotation);
}

void UCOVCameraComponent::ApplyCameraRotationInput(const ECameraRotation direction)
{
	const FRotator newAddedRotation = direction == (ECameraRotation::Clockwise) ? (FRotator(0.0f, RotationSettingAdjustmentStep, 0.0f)) : (FRotator(0.0f, -RotationSettingAdjustmentStep, 0.0f));
	CameraDesiredRotationSetting = CameraDesiredRotationSetting + newAddedRotation;
}

void UCOVCameraComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateCameraTransform(DeltaTime);

	UE_LOG(LogCamera, Log, TEXT("%s"), (bIsAnimating)?(TEXT("TRUE")):(TEXT("FALSE")));
}