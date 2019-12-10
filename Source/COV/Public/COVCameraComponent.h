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
		void ApplyCameraRotationInput(const ECameraRotation direction);

private:

	//	This is the default fixed relative position of the camera to the player to view the game from
	FORCEINLINE const FVector GetCameraDefaultLocation() const;
	//	This is where the camera wants to move now to view the game from
	FORCEINLINE const FVector GetCameraDesiredLocation() const;
	FORCEINLINE const FVector GetCameraCurrentLocation() const;
	FORCEINLINE const FRotator GetCameraCurrentRotation() const;
	FORCEINLINE const FVector GetPlayerLocation() const;
	FORCEINLINE void UpdateCameraTransform(const float deltaTime);

	//	How fast the camera should move to new desired locations
	float CameraTransformLerpSpeed = 0.08f;
	//	The default offset from the player camera
	const FVector CameraPlayerDefaultOffset = FVector(0, 1000.0f, 1000.0f);
	//	Do we rotate the camera in steps when changing rotation settings?
	bool bStepRotation = true;
	//	How many degrees is one camera rotation setting operation exactly? (Player pressing "Rotate camera clockwise" button)
	float RotationSettingAdjustmentStep = 45.0f;
	//	This is the current desired rotation settings for the camera
	FRotator CameraDesiredRotationSetting = FRotator(0, 0, 0);
	//	How fast the camera rotates to a new setting
	float RotationLerpSpeed = 0.08f;
	//	Is the camera currently animating or just following?
	bool bIsAnimating = false;
	//	Used to determine rotation velocities
	FRotator cachedRotation;

};
