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

		//	Is this screen being forced to stay in stack?
		bool _bHasScreenLock = false;

public:
	UFUNCTION(Category = "Screen", BlueprintCallable)
		//	Is the screen locked in place and can't be removed from stack?
		bool GetHasScreenLock() const { return _bHasScreenLock; };
	UFUNCTION(Category = "Screen", BlueprintCallable)
		// Locks the screen so that it can't be removed from the stack.
		void LockScreen() { _bHasScreenLock = true; };
	UFUNCTION(Category = "Screen", BlueprintCallable)
		// Release lock for this window so that it can be removed from the stack.
		void ReleaseLock() { _bHasScreenLock = false; };
	UFUNCTION(Category = "Screen", BlueprintCallable)
		// Release lock for this window so that it can be removed from the stack.
		bool GetIsScreenLocked() { return _bHasScreenLock; };
};
