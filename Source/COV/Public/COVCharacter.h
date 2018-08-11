// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "COVPlayerInput.h"
#include "COVCharacter.generated.h"

class UCameraComponent;
class ACOVPlayerController;

DECLARE_LOG_CATEGORY_EXTERN(XYZCharacter, Log, All)

UCLASS()
class COV_API ACOVCharacter : public ACharacter, public ICOVPlayerInput
{
	GENERATED_BODY()
public:
	//	VARIABLES	##########################################################################################
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


	UPROPERTY(EditAnywhere)
		//	Angle at which the character will start rotating towards aiming location
		float _angleToStartRotatingHips = 110.0f;
	UPROPERTY(EditAnywhere)
		//	How far away can the player interact with things?
		float _maximumInteractionDistance = 200.0f;
	UPROPERTY(EditAnywhere)
		//	How fast the player rotates to movement vector when receiving movement input?
		float _movementInputRotationSpeed = 5.0f;

private:
	uint32_t _bIsReceivingForwardInput : 1;
	uint32_t _bIsReceivingRightInput : 1;
	//	######################################################################################################

public:
	//	DEBUGS	#######################################################################
	bool _bShowDebugForwardVector = false;

	void DrawDebugEyeVector();
	//	###############################################################################


	//	Constructor
	ACOVCharacter(const class FObjectInitializer& PCIP);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	//	Registers replicated variables to the engine
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

	//	PLAYERINPUT INTERFACE IMPLEMENTATIONS
	virtual void Input_W_Implementation(float amount) override;
	virtual void Input_D_Implementation(float amount) override;
	virtual void Input_Spacebar_Pressed_Implementation() override;
	virtual void Input_Spacebar_Released_Implementation() override;
	virtual void Input_E_Pressed_Implementation() override;
	virtual void Input_E_Released_Implementation() override;
	virtual void Input_LeftMouseButton_Pressed_Implementation() override;
	virtual void Input_LeftMouseButton_Released_Implementation() override;
	virtual void Input_MouseMovementY_Implementation(float amount) override;
	virtual void Input_MouseMovementX_Implementation(float amount) override;

private:
	//	INPUTS	#############################################################################################
	UFUNCTION(Category = "Movement", BLueprintCallable)
		//	Move character forward/back
		void Input_MoveForward(float amount);
	UFUNCTION(Category = "Movement", BlueprintCallable)
		//	Move character left/right
		void Input_MoveRight(float amount);
	UFUNCTION(Category = "Movement", BlueprintCallable)
		//	Set pitch based on control input
		void Input_AimUp(float amount);
	UFUNCTION(Category = "Movement", BlueprintCallable)
		//	Set yaw based on control input
		void Input_AimRight(float amount);
	UFUNCTION(Category = "Input_Interact", BlueprintCallable)
		//	Interact with the world
		void Input_Interact();
	//	#####################################################################################################



public:
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
	//	####################################################################################################


	//	GETTERS	############################################################################################
	UFUNCTION(Category = "XYZCharacter", BlueprintPure)
		//	Get the player eye position in world space
		FVector GetEyeWorldLocation() const;
	UFUNCTION(Category = "XYZCharacter", BlueprintPure)
		//	Get the character's camera
		UCameraComponent* GetCharacterCamera() const;
	UFUNCTION(Category = "XYZCharacter", BlueprintPure)
		//	Get the XYZCharacterController of this character
		ACOVPlayerController* GetXYZPlayerController() const;
	UFUNCTION(Category = "XYZCharacter", BlueprintPure)
		//	Get the aiming vector
		FVector GetAimingLocation();
	UFUNCTION(Category = "XYZCharacter", BlueprintPure)
		//	Get the aiming vector
		FVector GetAimingVector();
	UFUNCTION(Category = "XYZCharacterAnimationVariables", BlueprintPure)
		//	Simple getter for yaw
		float GetYaw();
	UFUNCTION(Category = "XYZCharacterAnimationVariables", BlueprintPure)
		//	Simple getter for _upperTorsopitch
		float GetPitch();
	UFUNCTION(Category = "XYZCharacterAnimationVariables", BlueprintPure)
		FRotator GetHipRotation() const;

	//	Tries to get the actor which the player might be interacting with
	AActor* TryGetInteractedActor();
	//	GETTERS	############################################################################################
	

	UFUNCTION(Category = "XYZCharacterAnimationVariables", BlueprintCallable)
		void Update_IsReceivingMovementInput();

	UFUNCTION(Category = "XYZCharacterAnimationVariables", BlueprintCallable)
		float CalculateYaw();
	UFUNCTION(Category = "XYZCharacterAnimationVariables", BlueprintCallable)
		float CalculatePitch();
	UFUNCTION(Category = "XYZCharacterAnimationVariables", BlueprintCallable)
		FVector CalculateAimingLocation();
	UFUNCTION(Category = "XYZCharacterAnimationVariables", BlueprintCallable)
		FRotator CalculateRotation(float deltaTime);
};
