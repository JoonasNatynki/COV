// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "COVSmoothAnimationComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COV_API UCOVSmoothAnimationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCOVSmoothAnimationComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty, FDefaultAllocator>& OutLifetimeProps) const override;


	UPROPERTY(Replicated, VisibleAnywhere)
		//	The yaw of this characters upper torso value. To be used in the animation blueprint
		float _upperTorsoYaw;
	UPROPERTY(Replicated, VisibleAnywhere)
		//	The pitch of this characters upper torso value. To be used in the animation blueprint
		float _upperTorsoPitch;
	UPROPERTY(Replicated, VisibleAnywhere)
		//	The location and direction the player is aiming at
		FVector _aimingLocation;
	UPROPERTY(Replicated, VisibleAnywhere)
		//	The hip rotation of the actor
		FRotator _actorRotation;
	UPROPERTY(Replicated, VisibleAnywhere)
		//	Tells if the character is receiving player movement input to rotate hips towards aiming location
		bool _bIsReceivingMovementInput;

	UPROPERTY(Category = "Animation", EditDefaultsOnly)
		//	Angle at which the character will start rotating towards aiming location
		float _angleToStartRotatingHips = 90;
	UPROPERTY(Category = "Movement", EditDefaultsOnly)
		//	How fast the player rotates to movement vector when receiving movement input?
		float _movementInputRotationSpeed = 5.0f;

	UPROPERTY(Category = "Movement", VisibleAnywhere, ReplicatedUsing = OnRep_currentMaximumMovementSpeed)
		//	The default maximum speed the character will be running at without sprinting
		float _currentMaximumMovementSpeed;
	UPROPERTY(Category = "Movement", EditDefaultsOnly)
		//	The default maximum speed the character will be running at without sprinting
		float _defaultMaximumRunningSpeed = 600.0f;
	UPROPERTY(Category = "Movement", EditDefaultsOnly)
		//	The default maximum speed the character will be running at without sprinting
		float _defaultMaximumWalkingSpeed = 200.0f;

	uint32_t _bIsReceivingForwardInput : 1;
	uint32_t _bIsReceivingRightInput : 1;


	//	SERVER ONLY FUNCTIONS	#############################################################################
	UFUNCTION(Category = "XYZCharacterAnimation", Server, Unreliable, WithValidation)
		//	Server version of the UpdateYawAndPitch function
		void Server_SetAimingLocation(FVector aimingLocation);
	UFUNCTION(Category = "XYZCharacterAnimation", Server, Unreliable, WithValidation)
		//	Server version of the UpdateYawAndPitch function
		void Server_SetPitch(float pitch);
	UFUNCTION(Category = "XYZCharacterAnimation", Server, Unreliable, WithValidation)
		//	Server version of the UpdateYawAndPitch function
		void Server_SetYaw(float yaw);
	UFUNCTION(Category = "XYZCharacterAnimation", Server, Unreliable, WithValidation)
		//	Server version of the UpdateYawAndPitch function
		void Server_SetActorRotation(FRotator actorRotation);
	UFUNCTION(Category = "XYZInteraction", Server, Reliable, WithValidation)
		//	Server-side interaction
		void Server_Interact(AActor* interacted);
	UFUNCTION(Category = "XYZCharacterAnimation", Server, Reliable, WithValidation)
		//	Server version of the current walking speed setter
		void Server_SetCurrentWalkingSpeed(float currentWalkingSpeed);
	//	####################################################################################################

	UFUNCTION()
		void OnRep_currentMaximumMovementSpeed();


	//	SETTERS ############################################################################################
	UFUNCTION(Category = "Movement", BlueprintCallable)
		void SetCurrentWalkingSpeed(float currentWalkingSpeed);
	//	SETTERS ############################################################################################
	
	UFUNCTION(Category = "COVCharacterAnimationVariables", BlueprintCallable)
		float CalculateYaw();
	UFUNCTION(Category = "COVCharacterAnimationVariables", BlueprintCallable)
		float CalculatePitch();
	UFUNCTION(Category = "COVCharacterAnimationVariables", BlueprintCallable)
		FVector CalculateAimingLocation();
	UFUNCTION(Category = "COVCharacterAnimationVariables", BlueprintCallable)
		FRotator CalculateRotation(float deltaTime);

	UFUNCTION(Category = "COVCharacterAnimationVariables", BlueprintCallable)
		//	This function updates all of the necessary variables needed to animate the character. Put this in your character's tick and make sure it only runs on a local client.
		void Update_AllAnimationVariables_TICK(float deltaTime);
	UFUNCTION(Category = "COVCharacterAnimationVariables", BlueprintCallable)
		bool CalculateIsReceivingMovementInput();
};
