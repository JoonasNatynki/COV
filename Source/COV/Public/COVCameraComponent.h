// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CinematicCamera/Public/CineCameraComponent.h"
#include "COVCameraComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class COV_API UCOVCameraComponent : public UCineCameraComponent
{
	GENERATED_BODY()

public:

	UCOVCameraComponent();

	UFUNCTION(Category = "COVCamera", BlueprintCallable, BlueprintPure)
		class APawn* GetOwnerPawn() const;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
