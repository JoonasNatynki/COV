// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CinematicCamera/Public/CineCameraComponent.h"
#include "COVCameraComponent.generated.h"

UENUM(BlueprintType) enum ECameraRotation
{
	Clockwise,
	CounterClockwise
};

DECLARE_LOG_CATEGORY_EXTERN(LogCamera, Log, All)

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class COV_API UCOVCameraComponent : public UCineCameraComponent
{
	GENERATED_BODY()

public:

	UCOVCameraComponent();

	UFUNCTION(Category = "COVCamera", BlueprintCallable, BlueprintPure)
		class APawn* GetOwnerPawn() const;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(Category = "COVCamera", BlueprintCallable)
		void RotateCamera(const ECameraRotation direction);

private:

	FORCEINLINE void UpdateCameraTransform(const float deltaTime);

	float CameraTransformLerpSpeed = 0.08f;
	const FVector CameraPlayerDefaultOffset = FVector(0, 1000.0f, 1000.0f);
	bool bStepRotation = true;
	float DegreesPerRotation = 45.0f;
	FRotator RotationOffset = FRotator(0, 0, 0);
	float RotationLerpSpeed = 0.08f;
	bool bIsAnimating = false;
};
