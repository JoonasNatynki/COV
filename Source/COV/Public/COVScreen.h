// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <InputCoreTypes.h>

#include "COVScreen.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(COVScreen, Log, All)

class FReply;

UCLASS()
class COV_API UCOVScreen : public UUserWidget
{
	GENERATED_BODY()

public:

	UCOVScreen(const FObjectInitializer& ObjInit);
	
	UPROPERTY(Category = "Screen", EditAnywhere)
		//	Is this screen being forced to stay in stack? Screen can not be removed, only hidden.
		bool bScreenIsLocked = false;

	UPROPERTY(Category = "Screen", EditDefaultsOnly)
		//	If the screen is an overlay. Screen under it will be visible until a screen that is not an overlay.
		bool bScreenIsAnOverlay = false;

	UPROPERTY(Category = "Screen", EditDefaultsOnly)
		//	If there can exist more than one of these screen or just one. If only one instance is allowed and the same screen is being pushed back into the stack, the stack will simply move that screen to the top and display it instead.
		bool bAllowMultipleInstances = false;

	UPROPERTY(Category = "Screen", EditDefaultsOnly)
		//	If this screen should take over mouse and keyboard input
		bool bTakeOverInput = false;

	UPROPERTY(Category = "Screen", EditDefaultsOnly)
		//	Bind a key to automatically close the screen with
		FKey KeyToCloseScreenWith;




	UFUNCTION(Category = "Screen", BlueprintCallable, BlueprintPure)
		//	Is the screen locked in place and can't be removed from stack?
		bool GetHasScreenLock() const { return bScreenIsLocked; };

	UFUNCTION(Category = "Screen", BlueprintCallable, BlueprintPure)
		//	Should this screen capture the mouse cursor?
		bool GetShouldScreenTakeOverMouse() const { return bTakeOverInput; };

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


	void ReleaseInputControl();
	void TakeOverInputControl();


	//	Bind button to close the screen
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
	bool bScreenStackManagerChangesVisibility = false;
	bool bShouldScreenBeShownWhenPossible = true;	//	Basically tells you if something else wanted to hide this screen or not
	virtual void SetVisibility(ESlateVisibility visibility) override;
};
