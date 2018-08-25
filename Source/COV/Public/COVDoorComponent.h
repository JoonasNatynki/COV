// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <DelegateCombinations.h>
#include "COVDoorComponent.generated.h"

class USceneComponent;

UENUM(BlueprintType) enum EDoorState
{
	Closed,
	Closing,
	Open,
	Opening,
	Cracked
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDoorStateChanged, EDoorState, DoorState);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class COV_API UCOVDoorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCOVDoorComponent();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty, FDefaultAllocator>& OutLifetimeProps) const;

	UFUNCTION()
	void OnRep_DoorState();

	UPROPERTY(BlueprintAssignable)
		//	Called when the door state changes
		FOnDoorStateChanged OnDoorStateChanged;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, ReplicatedUsing = OnRep_DoorState)
		//	The current state of the door and that it is in
		TEnumAsByte<EDoorState> _doorState = EDoorState::Closed;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		//	The state alpha. From 0 to 1 with 0 being fully closed and 1 is fully open
		float _doorStateAlpha = 0.0f;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		//	The value at which the door will be considered closed
		float _doorClosedAlphaThreshold = 0.1f;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		//	The value at which the door will be considered opened
		float _doorOpenAlphaThreshold = 0.9f;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		//	The transform of the door when it is fully closed
		FTransform _initialClosedTransform;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		//	The transform of the door when it is fully open
		FTransform _finalOpenTransform;

private:
	UPROPERTY()
		USceneComponent* _doorHinge;

public:
	UFUNCTION(BlueprintCallable)
		void UpdateDoorState();


	//	SETTERS	#############################################################################################
	UFUNCTION(BlueprintCallable)
		void SetDoorState(EDoorState doorState);
	UFUNCTION(BlueprintCallable)
		void SetDoorStateAlpha(float alpha);
	UFUNCTION(BlueprintCallable)
		void SetInitialClosedTransform(FTransform openTransform);
	UFUNCTION(BlueprintCallable)
		void SetFinalOpenTransform(FTransform finalTransform);
	UFUNCTION(BlueprintCallable)
		void SetDoorHinge(USceneComponent* doorHinge);
	//	SETTERS	#############################################################################################

	//	GETTERS	#############################################################################################
	UFUNCTION(BlueprintCallable)
		EDoorState GetDoorState() const;
	UFUNCTION(BlueprintCallable)
		float GetDoorStateAlpha() const;
	UFUNCTION(BlueprintCallable)
		FTransform GetInitialOpenTransform() const;
	UFUNCTION(BlueprintCallable)
		FTransform GetFinalClosedTransform() const;
	//	GETTERS	#############################################################################################

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;	
};
