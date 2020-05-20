// Fill out your copyright notice in the Description page of Project Settings.


#include "COVCameraComponent.h"
#include <GameFramework/Pawn.h>
#include <Kismet/KismetMathLibrary.h>
#include "UE4Helpers.h"
#include <DrawDebugHelpers.h>

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
	const FVector playerCurrentLocation = GetPlayerLocation();
	CameraInterestLocation = UKismetMathLibrary::VLerp(CameraInterestLocation, playerCurrentLocation, CameraTransformLerpSpeed);

	//	Location
	const FVector currentCameraLocation = GetCameraCurrentLocation();
	const FVector cameraDefaultLocation = CameraInterestLocation + CameraDefaultOffset;
	//	Lerps between camera rotation setting and the current rotation setting
	CameraCurrentRotationSetting = CameraCurrentRotationSetting + (CameraRotationLerpSpeed * (CameraDesiredRotationSetting - CameraCurrentRotationSetting));

	//	Now find out the actual desired camera location
	const FVector cameraTargetLocation = UE4CodeHelpers::RotateVectorAroundPoint(cameraDefaultLocation, CameraInterestLocation, CameraCurrentRotationSetting);
	const FVector desiredCameraLocation = cameraTargetLocation;

	//	Rotation
	const FRotator currentCameraRotation = GetCameraCurrentRotation();
	const FRotator desiredCameraRotation = UKismetMathLibrary::FindLookAtRotation(desiredCameraLocation, CameraInterestLocation);

	SetWorldLocation(desiredCameraLocation);
	SetWorldRotation(desiredCameraRotation);
}

FORCEINLINE void UCOVCameraComponent::UpdateDebugs(float deltaTime)
{
	DrawDebugSphere(GetWorld(), CameraInterestLocation, 20.0f, 12, FColor::Emerald, false, deltaTime, 0, 1.0f);
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

	//UpdateDebugs(DeltaTime);
}