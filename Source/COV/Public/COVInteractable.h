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
		//	If the object is currently interactable or not.
		bool GetIsInteractable();
	UFUNCTION(Category = "Interaction", BlueprintCallable, BlueprintImplementableEvent, BlueprintAuthorityOnly)
		//	Call this when interacting with the object. Most often only the client should be calling this function. Returns TRUE if interaction is successful
		bool Interact(AActor* Interactor);
	UFUNCTION(Category = "Interaction", BlueprintCallable, BlueprintImplementableEvent)
		//	Returns the default text about the type of interaction that will happen when interacting with this object.
		FText GetDefaultPromptText();
	UFUNCTION(Category = "Interaction", BlueprintCallable, BlueprintImplementableEvent)
		//	Returns the default location in world space of the text that is displayed on the interactable object about its interaction type.
		FVector GetDefaultPromptLocation();

};
