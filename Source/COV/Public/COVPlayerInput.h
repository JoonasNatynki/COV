// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "COVPlayerInput.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable, MinimalAPI)
class UCOVPlayerInput : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class COV_API ICOVPlayerInput
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:	
	UFUNCTION(Category = "Player Input", BlueprintCallable, BlueprintNativeEvent)
		void Input_W(float amount);
	UFUNCTION(Category = "Player Input", BlueprintCallable, BlueprintNativeEvent)
		void Input_D(float amount);
	UFUNCTION(Category = "Player Input", BlueprintCallable, BlueprintNativeEvent)
		void Input_E_Pressed();
	UFUNCTION(Category = "Player Input", BlueprintCallable, BlueprintNativeEvent)
		void Input_E_Released();
	UFUNCTION(Category = "Player Input", BlueprintCallable, BlueprintNativeEvent)
		void Input_F_Pressed();
	UFUNCTION(Category = "Player Input", BlueprintCallable, BlueprintNativeEvent)
		void Input_F_Released();
	UFUNCTION(Category = "Player Input", BlueprintCallable, BlueprintNativeEvent)
		void Input_Spacebar_Pressed();
	UFUNCTION(Category = "Player Input", BlueprintCallable, BlueprintNativeEvent)
		void Input_Spacebar_Released();
	UFUNCTION(Category = "Player Input", BlueprintCallable, BlueprintNativeEvent)
		void Input_LeftShift_Pressed();
	UFUNCTION(Category = "Player Input", BlueprintCallable, BlueprintNativeEvent)
		void Input_LeftShift_Released();
	UFUNCTION(Category = "Player Input", BlueprintCallable, BlueprintNativeEvent)
		void Input_LeftMouseButton_Pressed();
	UFUNCTION(Category = "Player Input", BlueprintCallable, BlueprintNativeEvent)
		void Input_LeftMouseButton_Released();
	UFUNCTION(Category = "Player Input", BlueprintCallable, BlueprintNativeEvent)
		void Input_MovementInput(float amount);
	UFUNCTION(Category = "Player Input", BlueprintCallable, BlueprintNativeEvent)
		void Input_MouseMovementY(float amount);
	UFUNCTION(Category = "Player Input", BlueprintCallable, BlueprintNativeEvent)
		void Input_MouseMovementX(float amount);
};
