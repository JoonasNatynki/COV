// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <DelegateCombinations.h>
#include "COVFocusComponent.generated.h"

static TAutoConsoleVariable<int32> CVarShowFocusDebugs(TEXT("COV.DebugFocusPoint"),
	0,
	TEXT("Show the point of focus in the world."));

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

	UPROPERTY(Category = "Focus", BlueprintReadOnly, VisibleAnywhere, Transient)
		FVector _focusWorldLocation;

	UPROPERTY(Category = "Focus", EditDefaultsOnly, BlueprintReadWrite)
		float _focusingMaxDistance = 700.0f;

	UPROPERTY(Category = "Focus", EditDefaultsOnly, BlueprintReadWrite)
		//	If TRUE, you can focus on everything and on focusable things regardless of their set distance limits.
		bool bDeveloperMode = false;

	UPROPERTY(Category = "Focus", EditDefaultsOnly, BlueprintReadWrite)
		float _focusingMaxArea = 80.0f;

	UPROPERTY(Category = "Debug", EditDefaultsOnly, BlueprintReadWrite)
		//	Whether to ignore all other actors but the ones with the FocusableComponent
		bool bFocusOnlyOnFocusables = true;

	UPROPERTY(Category = "Debug", EditDefaultsOnly, BlueprintReadWrite)
		bool bShowDebug = false;


	//	Internal implementation of the updating logic
	TWeakObjectPtr<AActor> UpdateFocusedActor_Internal();
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
	UFUNCTION(Category = "Focus", BlueprintCallable, BlueprintPure)
		FORCEINLINE FVector GetFocusWorldLocation() const;

	UFUNCTION(Category = "Focus", BlueprintCallable)
		//	Goes through the logic of how the focus actor is determined and updates the cached focused actor variable.
		void UpdateFocusedActor();
	UFUNCTION(Category = "Focus", BlueprintCallable)
		void SetFocusedActor(AActor* newFocus) { _cachedFocusedActor = newFocus; };

	const void DrawDebugs(float deltaTime) const;
	const TWeakObjectPtr<AActor> FindClosestFocusedActor_Internal(TArray<AActor*> overlappingActors) const;
};

FVector UCOVFocusComponent::GetFocusWorldLocation() const
{
	return _focusWorldLocation;
}