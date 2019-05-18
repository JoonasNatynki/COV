// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <DelegateCombinations.h>
#include "COVFocusComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFocusedActorChanged, AActor*, NewFocusedActor);

//	Component that casts either a ray from the camera or a more complex area focus mechanic to determine which object in the game world is being focused on.
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, meta=(ShortTooltip = "Component used for focusing on objects.") )
class COV_API UCOVFocusComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCOVFocusComponent();

	UPROPERTY(BlueprintAssignable)
		FOnFocusedActorChanged OnFocusedActorChanged;

	UPROPERTY(Category = "Focus", BlueprintReadOnly, VisibleAnywhere, Transient)
		AActor* _cachedFocusedActor;
	UPROPERTY(Category = "Focus", EditDefaultsOnly)
		float _focusingMaxDistance = 350.0f;
	UPROPERTY(Category = "Debug", EditDefaultsOnly)
		bool bShowDebug = false;

	//	Internal implementation of the updating logic
	TWeakObjectPtr<AActor> UpdateFocusedActor_Internal() const;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(Category = "Focus", BlueprintCallable, BlueprintPure)
		//	Gets and updates the focused actor.
		AActor* GetFocusedActor();
	UFUNCTION(Category = "Focus", BlueprintCallable, BlueprintPure)
		//	Gets the cached focused actor from the last time the focus actor was updated.
		AActor* GetCachedFocusedActor() const;
	UFUNCTION(Category = "Focus", BlueprintCallable)
		//	Goes through the logic of how the focus actor is determined and updates the cached focused actor variable.
		void UpdateFocusedActor();
	UFUNCTION(Category = "Focus", BlueprintCallable)
		void SetFocusedActor(AActor* newFocus) { _cachedFocusedActor = newFocus; };
};
