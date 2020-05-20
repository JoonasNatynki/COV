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

	FORCEINLINE const FVector GetCameraCurrentLocation() const;
	FORCEINLINE const FRotator GetCameraCurrentRotation() const;
	FORCEINLINE const FVector GetPlayerLocation() const;
	FORCEINLINE void UpdateCameraTransform(const float deltaTime);
	FORCEINLINE void UpdateDebugs(float deltaTime);

	UPROPERTY(Category = "3rd Person Camera", EditDefaultsOnly)
		//	The default offset from the player camera
		FVector CameraDefaultOffset = FVector(0, 1000.0f, 1000.0f);

	//	How fast the camera should move to new desired locations
	float CameraTransformLerpSpeed = 0.08f;

	//	Do we rotate the camera in steps when changing rotation settings?
	bool bStepRotation = true;
	//	How many degrees is one camera rotation setting operation exactly? (Player pressing "Rotate camera clockwise" button)
	float RotationSettingAdjustmentStep = 45.0f;

	//	This is the current desired rotation settings for the camera
	FRotator CameraDesiredRotationSetting = FRotator(0.0f, 0.0f, 0.0f);
	FRotator CameraCurrentRotationSetting = FRotator(0.0f, 0.0f, 0.0f);
	float CameraRotationLerpSpeed = 0.05f;

	//	The location where the camera is pointing at or trying to focus at
	FVector CameraInterestLocation;

};
