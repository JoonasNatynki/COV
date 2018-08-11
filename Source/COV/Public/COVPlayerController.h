// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "COVPlayerController.generated.h"

/**
 * 
 */

class ACOVCharacter;

DECLARE_LOG_CATEGORY_EXTERN(COVPlayerController, All, Log)

UCLASS()
class COV_API ACOVPlayerController : public APlayerController
{
	GENERATED_BODY()
	
		//	Virtual function from APlayerController that allows custom input bindings
		void SetupInputComponent() override;

public:

	UPROPERTY(EditAnywhere)
		//	X axis sensitivity
		float _XSensitivity = 1;
	UPROPERTY(EditAnywhere)
		//	Y axis sensitivity
		float _YSensitivity = 1;


	UFUNCTION(BlueprintPure)
		//	Get the AXYZ_Character this controller should be controlling
		ACOVCharacter* GetControlledCOVCharacter();


	UFUNCTION(BlueprintNativeEvent)
		void Input_E_Pressed();
	UFUNCTION(BlueprintNativeEvent)
		void Input_E_Released();
	UFUNCTION(BlueprintNativeEvent)
		void Input_Spacebar_Pressed();
	UFUNCTION(BlueprintNativeEvent)
		void Input_Spacebar_Released();
	UFUNCTION(BlueprintNativeEvent)
		void Input_LeftShift_Pressed();
	UFUNCTION(BlueprintNativeEvent)
		void Input_LeftShift_Released();
	UFUNCTION(BlueprintNativeEvent)
		void Input_LeftMouseButton_Pressed();
	UFUNCTION(BlueprintNativeEvent)
		void Input_LeftMouseButton_Released();
	UFUNCTION(BlueprintNativeEvent)
		void Input_Key_W(float amount);
	UFUNCTION(BlueprintNativeEvent)
		void Input_Key_D(float amount);
	UFUNCTION(BlueprintNativeEvent)
		void Input_MouseMovementY(float amount);
	UFUNCTION(BlueprintNativeEvent)
		void Input_MouseMovementX(float amount);
};
