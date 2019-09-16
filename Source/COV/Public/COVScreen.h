// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "COVScreen.generated.h"

/**
 * 
 */
UCLASS()
class COV_API UCOVScreen : public UUserWidget
{
	GENERATED_BODY()

public:

	UCOVScreen(const FObjectInitializer& ObjInit);
	
	UPROPERTY(Category = "Screen", EditAnywhere)
		//	Is this screen being forced to stay in stack?
		bool bScreenIsLocked = false;

	UPROPERTY(Category = "Screen", EditDefaultsOnly)
		//	If the screen is an overlay, which means it will not hide the screens under it
		bool bScreenIsAnOverlay = false;

	UPROPERTY(Category = "Screen", EditDefaultsOnly)
		//	If there can exist more than one of these screen or just one
		bool bAllowMultipleInstances = false;

	UPROPERTY(Category = "Screen", EditDefaultsOnly)
		//	If this screen should take over the mouse and display a cursor
		bool bTakeOverMouse = false;



	UFUNCTION(Category = "Screen", BlueprintCallable, BlueprintPure)
		//	Is the screen locked in place and can't be removed from stack?
		bool GetHasScreenLock() const { return bScreenIsLocked; };

	UFUNCTION(Category = "Screen", BlueprintCallable, BlueprintPure)
		//	Should this screen capture the mouse cursor?
		bool GetShouldScreenTakeOverMouse() const { return bTakeOverMouse; };

	UFUNCTION(Category = "Screen", BlueprintCallable)
		// Locks the screen so that it can't be removed from the stack.
		void LockScreen() { bScreenIsLocked = true; };

	UFUNCTION(Category = "Screen", BlueprintCallable)
		// Release lock for this window so that it can be removed from the stack.
		void ReleaseLock() { bScreenIsLocked = false; };

	UFUNCTION(Category = "Screen", BlueprintCallable, BlueprintPure)
		//	Is the screen locked in place and can't be removed from stack?
		bool GetIsScreenLocked() const { return bScreenIsLocked; };

	UFUNCTION(Category = "Screen", BlueprintCallable, BlueprintPure)
		//	Is the screen an overlay?
		bool GetIsScreenAnOverlay() const { return bScreenIsAnOverlay; };

	UFUNCTION(Category = "Screen", BlueprintCallable, BlueprintPure)
		//	Can more than one screen exist at the same time in the stack?
		bool GetAllowMultipleInstances() const { return bAllowMultipleInstances; };
};
