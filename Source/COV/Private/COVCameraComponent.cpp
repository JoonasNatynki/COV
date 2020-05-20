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

FORCEINLINE const FVector UCOVCameraComponent::GetCameraLookAtLocation() const
{
	return GetOwner()->GetActorLocation();
}

FORCEINLINE void UCOVCameraComponent::UpdateCameraTransform(const float deltaTime)
{
	const FVector LookAtTargetLocation = GetCameraLookAtLocation();
	const FVector PreviousCameraPositionRootLocation = UpToDateCameraRootLocation;
	UpToDateCameraRootLocation = UKismetMathLibrary::VLerp(PreviousCameraPositionRootLocation, LookAtTargetLocation, CameraTransformLerpSpeed);

	//	Location
	const FVector CurrentCameraLocation = GetCameraCurrentLocation();
	const FVector CameraUnrotatedLocation = UpToDateCameraRootLocation + CameraDefaultOffset;
	//	Lerps between camera rotation setting and the current rotation setting
	CameraCurrentRotationSetting = CameraCurrentRotationSetting + (CameraRotationLerpSpeed * (CameraDesiredRotationSetting - CameraCurrentRotationSetting));

	//	Rotation
	FVector FinalCameraLocation = UE4CodeHelpers::RotateVectorAroundPoint(CameraUnrotatedLocation, UpToDateCameraRootLocation, CameraCurrentRotationSetting);
	const FRotator currentCameraRotation = GetCameraCurrentRotation();
	const FRotator FinalCameraRotation = UKismetMathLibrary::FindLookAtRotation(FinalCameraLocation, UpToDateCameraRootLocation);

	//	Finally update the transform
	//SetWorldLocation(FinalCameraLocation);
	SetWorldLocation(FinalCameraLocation);
	SetWorldRotation(FinalCameraRotation);
	//	Apply boom offset
	const FVector CameraForwardVector = GetForwardVector();
	FinalCameraLocation = FinalCameraLocation + (CameraForwardVector * CameraBoomLength);
	SetWorldLocation(FinalCameraLocation);
	SetWorldRotation(FinalCameraRotation);
}

FORCEINLINE void UCOVCameraComponent::UpdateDebugs(float deltaTime)
{
	DrawDebugSphere(GetWorld(), UpToDateCameraRootLocation, 20.0f, 12, FColor::Emerald, false, deltaTime, 0, 1.0f);
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