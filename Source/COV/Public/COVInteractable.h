// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "COVInteractable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCOVInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class COV_API ICOVInteractable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(Category = "Interaction", BlueprintCallable, BlueprintImplementableEvent)
		//	Call this when interacting with the object. Most often only the client should be calling this function.
		bool GetIsInteractable();
	UFUNCTION(Category = "Interaction", BlueprintCallable, BlueprintImplementableEvent)
		//	Call this when interacting with the object. Most often only the client should be calling this function.
		bool Interact(AActor* Interactor);
	UFUNCTION(Category = "Interaction", BlueprintCallable, BlueprintImplementableEvent)
		//	Call this when interacting with the object. Most often only the client should be calling this function.
		FText GetDefaultPromptText();
	UFUNCTION(Category = "Interaction", BlueprintCallable, BlueprintImplementableEvent)
		//	Call this when interacting with the object. Most often only the client should be calling this function.
		FVector GetDefaultPromptLocation();

};
