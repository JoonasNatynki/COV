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
	Locked
};

DECLARE_LOG_CATEGORY_EXTERN(COVDoor, All, Log)

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

	UPROPERTY(Category = "Door", BlueprintAssignable)
		//	Called when the door state changes
		FOnDoorStateChanged OnDoorStateChanged;

	UPROPERTY(Category = "Door", BlueprintReadOnly, EditDefaultsOnly, ReplicatedUsing = OnRep_DoorState)
		//	The current state of the door and that it is in
		TEnumAsByte<EDoorState> _doorState = EDoorState::Closed;

	UPROPERTY(Category = "Door", BlueprintReadOnly, EditDefaultsOnly)
		//	The state alpha. From 0 to 1 with 0 being fully closed and 1is fully open
		float _doorStateAlpha = 0.0f;

	UPROPERTY(Category = "Door", BlueprintReadOnly, EditDefaultsOnly)
		//	The value at which the door will be considered closed
		float _doorClosedAlphaThreshold = 0.0f;

	UPROPERTY(Category = "Door", BlueprintReadOnly, EditDefaultsOnly)
		//	The value at which the door will be considered opened
		float _doorOpenAlphaThreshold = 1.0f;

	UPROPERTY(Category = "Door", BlueprintReadOnly, EditDefaultsOnly)
		//	The door motion interpolation exponent
		float _motionInterpolationExponent = 2.0f;

	UPROPERTY(Category = "Door", BlueprintReadOnly, EditDefaultsOnly)
		//	The door motion interpolation step count
		int32 _motionInterpolationSteps = 2;

	UPROPERTY(Category = "Configuration", BlueprintReadOnly, EditDefaultsOnly)
		//	The transform of the door when it is fully closed
		FTransform _initialClosedTransform;

	UPROPERTY(Category = "Configuration", BlueprintReadOnly, EditDefaultsOnly)
		//	The transform of the door when it is fully open
		FTransform _finalOpenTransform;

	UPROPERTY(Category = "Configuration", BlueprintReadOnly, EditDefaultsOnly)
		USceneComponent* _doorHinge;


	float _doorPreviousFrameAlpha;

public:
	UFUNCTION(BlueprintCallable)
		void UpdateDoorState();


	//	SETTERS	#############################################################################################
	UFUNCTION(Category = "Door", BlueprintCallable)
		void SetDoorState(EDoorState doorState);
	UFUNCTION(Category = "Door", BlueprintCallable)
		void SetDoorStateAlpha(float alpha);
	UFUNCTION(Category = "Door", BlueprintCallable)
		void SetInitialClosedTransform(FTransform openTransform);
	UFUNCTION(Category = "Door", BlueprintCallable)
		void SetFinalOpenTransform(FTransform finalTransform);
	UFUNCTION(Category = "Door", BlueprintCallable)
		void SetDoorHinge(USceneComponent* doorHinge);
	//	SETTERS	#############################################################################################

	//	GETTERS	#############################################################################################
	UFUNCTION(Category = "Door", BlueprintCallable, BlueprintPure)
		EDoorState GetDoorState() const;
	UFUNCTION(Category = "Door", BlueprintCallable, BlueprintPure)
		float GetDoorStateAlpha() const;
	UFUNCTION(Category = "Door", BlueprintCallable, BlueprintPure)
		FTransform GetInitialOpenTransform() const;
	UFUNCTION(Category = "Door", BlueprintCallable, BlueprintPure)
		FTransform GetFinalClosedTransform() const;
	//	GETTERS	#############################################################################################

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;	
};
