// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "COVPlayerInput.h"
#include "COVInteractable.h"
#include "COVCharacter.generated.h"

class UCameraComponent;
class ACOVPlayerController;
class UCOVSmoothAnimationComponent;
class UCOVInteractionComponent;
class UFocusComponent;
class UInventoryComponent;

DECLARE_LOG_CATEGORY_EXTERN(COVCharacter, Log, All)

UCLASS()
class COV_API ACOVCharacter : public ACharacter, public ICOVPlayerInput, public ICOVInteractable
{
	GENERATED_BODY()
public:
	UPROPERTY(Category = "Animation", VisibleAnywhere)
		UCOVSmoothAnimationComponent* SmoothMotionComponent;
	UPROPERTY(Category = "Interaction", VisibleAnywhere)
		UCOVInteractionComponent* InteractionComponent;
	UPROPERTY(Category = "Interaction", VisibleAnywhere)
		UInventoryComponent* Inventory;

public:
	UPROPERTY(Category = "Interaction", EditDefaultsOnly)
		//	How far away can the player interact with things?
		float _maximumInteractionDistance = 200.0f;

	//	Constructor
	ACOVCharacter(const class FObjectInitializer& PCIP);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//	Registers replicated variables to the engine
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

	//	PLAYERINPUT INTERFACE IMPLEMENTATIONS
	virtual void Input_E_Pressed_Implementation() override;
	virtual void Input_E_Released_Implementation() override;
	virtual void Input_F_Pressed_Implementation() override;
	virtual void Input_F_Released_Implementation() override;
	virtual void Input_W_Implementation(float amount) override;
	virtual void Input_D_Implementation(float amount) override;
	virtual void Input_Spacebar_Pressed_Implementation() override;
	virtual void Input_Spacebar_Released_Implementation() override;
	virtual void Input_LeftShift_Pressed_Implementation() override;
	virtual void Input_LeftShift_Released_Implementation() override;
	virtual void Input_LeftMouseButton_Pressed_Implementation() override;
	virtual void Input_LeftMouseButton_Released_Implementation() override;
	virtual void Input_RightMouseButton_Pressed_Implementation() override;
	virtual void Input_RightMouseButton_Released_Implementation() override;
	virtual void Input_MovementInput_Implementation(float amount) override;
	virtual void Input_MouseMovementY_Implementation(float amount) override;
	virtual void Input_MouseMovementX_Implementation(float amount) override;
	virtual void Input_MouseWheelUp_Implementation() override;
	virtual void Input_MouseWheelDown_Implementation() override;
	virtual void Input_LeftControl_Pressed_Implementation() override;
	virtual void Input_LeftControl_Released_Implementation() override;



	//	INPUTS	#############################################################################################
	UFUNCTION(Category = "Movement", BlueprintCallable, BlueprintNativeEvent)
		//	Move character forward/back
		void Input_MoveForward(float amount);
	UFUNCTION(Category = "Movement", BlueprintNativeEvent)
		//	Move character left/right
		void Input_MoveRight(float amount);
	UFUNCTION(Category = "Server", Server, Reliable, WithValidation, BlueprintCallable, BlueprintAuthorityOnly)
		void Input_Interact_Server(AActor* interactedActor, TSubclassOf<UInteractionOptionDetails> InteractOption);
	UFUNCTION(Category = "Interaction", BlueprintNativeEvent)
		void Input_Interact();
	//	#####################################################################################################

public:

	//	GETTERS	#############################################################################################
	UFUNCTION(Category = "COVCharacter", BlueprintPure)
		//	Get the character's camera
		UCameraComponent* GetCharacterCamera() const;
	UFUNCTION(Category = "COVCharacter", BlueprintPure)
		//	Get the XYZCharacterController of this character
		ACOVPlayerController* GetCOVPlayerController() const;
	//	GETTERS	############################################################################################

	UPROPERTY(Category = "Debug", BlueprintReadWrite, EditAnywhere)
		bool _bDebugModeIsOn = false;

	UFUNCTION(Category = "Console", Exec)
		void COV_ShowCharacterAimingVectors(bool bAimingVectorsVisible);
};
