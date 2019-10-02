// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <DelegateCombinations.h>
#include "COVInteractionComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(COVInteractionComponent, Log, All)

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractableFocused, AActor*, interactableActor);

class UFocusComponent;

UCLASS( ClassGroup=(COV), meta=(BlueprintSpawnableComponent), Blueprintable )
class COV_API UCOVInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCOVInteractionComponent();

private:
	//	The focus component reference of the owner, if present. This will be primarily used in determining which actor to interact with at any given time
	TWeakObjectPtr<UFocusComponent> OwnerFocusComponent;

	UPROPERTY(BlueprintAssignable)
		FOnInteractableFocused OnInteractableFocused;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(Category = "Interaction", BlueprintCallable)
		UFocusComponent* TryGetOwnerFocusComponent() const;
	UFUNCTION(Category = "Interaction", BlueprintCallable)
		AActor* TryGetInteractedActor() const;
};
