// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "COVFocusComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class COV_API UCOVFocusComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCOVFocusComponent();

	UPROPERTY(Category = "Focus", BlueprintReadOnly, VisibleAnywhere)
		AActor* _cachedFocusedActor;
	UPROPERTY(Category = "Focus", EditDefaultsOnly)
		float _focusingMaxDistance = 350.0f;

	TWeakObjectPtr<AActor> FindActorToFocus() const;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(Category = "Focus", BlueprintCallable, BlueprintPure)
		AActor* GetCachedFocusedActor();
	UFUNCTION(Category = "Focus", BlueprintCallable)
		void UpdateFocusedActor();
	UFUNCTION(Category = "Focus", BlueprintCallable)
		void SetFocusedActor(AActor* newFocus) { _cachedFocusedActor = newFocus; };
};
