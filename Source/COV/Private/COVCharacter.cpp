// Fill out your copyright notice in the Description page of Project Settings.

#include "COVCharacter.h"
#include "COVPlayerController.h"
#include "Engine.h"
#include "UnrealNetwork.h"
#include <Kismet/KismetMathLibrary.h>
#include "COVSmoothAnimationComponent.h"
#include "COVInteractionComponent.h"
#include "FocusComponent.h"
#include <Kismet/KismetSystemLibrary.h>
#include "UE4Helpers.h"
#include "Inventory.h"

DEFINE_LOG_CATEGORY(COVCharacter)

// Sets default values
ACOVCharacter::ACOVCharacter(const class FObjectInitializer& PCIP)/* : Super(PCIP.SetDefaultSubobjectClass<UXYZ_CharacterMovementComponent>(ACharacter::CharacterMovementComponentName))*/
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorTickEnabled(false);
	bUseControllerRotationYaw = false;
}

// Called when the game starts or when spawned
void ACOVCharacter::BeginPlay()
{
	Super::BeginPlay();

	//	Here we see if the character blueprint is configured properly with the proper components that it needs to function properly. If one component is missing, we ensure that it is added to the blueprint. The reason why we add the components in the blueprint instead of code is: it's much easier and designer friendly. No reason to hardcode it here since there is no performance gain in doing so and we can access the component just as well if it is initialized through the blueprint scripting language. Although there is nothing wrong in initializing the components in the constructor here in code either. It is just a personal preference. A good rule of thumb is that you write implementation and the functionality in C++ and you do the higher level logic and execution of those implementations in Blueprints. In other words: "Write the functions in C++, use the functions in Blueprints.".

	//	Inventory component
	GET_AND_CACHE_COMPONENT(UInventoryComponent, Inventory)
}

void ACOVCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

//	Required for network replication of variables
void ACOVCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty, FDefaultAllocator>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);	
}

//	INPUTS	############################################################################################################################
void ACOVCharacter::Input_E_Pressed_Implementation()
{

}

void ACOVCharacter::Input_E_Released_Implementation()
{

}

bool ACOVCharacter::Input_Interact_Server_Validate(AActor* interactedActor)
{
	return true;
}

void ACOVCharacter::Input_Interact_Server_Implementation(AActor* interactedActor)
{
	if (ICOVInteractable::Execute_Interact(interactedActor, this))
	{
		COV_LOG(COVCharacter, Log, TEXT("Character (%s) interaction with actor (%s) was successful."), *GetNameSafe(this), *GetNameSafe(interactedActor));
	}
	else
	{
		COV_LOG(COVCharacter, Warning, TEXT("Character (%s) interaction with actor (%s) was NOT successful. The interacted actor does not implement interface 'Interactable'"), *GetNameSafe(this), *GetNameSafe(interactedActor));
	}
}

void ACOVCharacter::Input_F_Pressed_Implementation()
{
	Input_Interact();
}

void ACOVCharacter::Input_F_Released_Implementation()
{

}

void ACOVCharacter::Input_D_Implementation(float amount)
{
	Input_MoveRight(amount);
}

void ACOVCharacter::Input_W_Implementation(float amount)
{
	Input_MoveForward(amount);
}

void ACOVCharacter::Input_Spacebar_Pressed_Implementation()
{

}

void ACOVCharacter::Input_Spacebar_Released_Implementation()
{

}

void ACOVCharacter::Input_LeftShift_Pressed_Implementation()
{
	//	If using smooth motion component, use it to set the current movement speed. Otherwise just use the character movement component
	if (SmoothMotionComponent)
	{
		SmoothMotionComponent->SetCurrentMovementSpeed(SmoothMotionComponent->GetDefaultRunningSpeed());
	}
}

void ACOVCharacter::Input_LeftShift_Released_Implementation()
{
	if (SmoothMotionComponent)
	{
		SmoothMotionComponent->SetCurrentMovementSpeed(SmoothMotionComponent->GetDefaultWalkingSpeed());
	}
}

void ACOVCharacter::Input_LeftMouseButton_Pressed_Implementation()
{

}

void ACOVCharacter::Input_LeftMouseButton_Released_Implementation()
{

}

void ACOVCharacter::Input_RightMouseButton_Pressed_Implementation()
{

}

void ACOVCharacter::Input_RightMouseButton_Released_Implementation()
{

}

void ACOVCharacter::Input_MouseMovementY_Implementation(float amount)
{

}

void ACOVCharacter::Input_MouseMovementX_Implementation(float amount)
{

}

void ACOVCharacter::Input_MouseWheelUp_Implementation()
{

}

void ACOVCharacter::Input_MouseWheelDown_Implementation()
{

}

void ACOVCharacter::Input_LeftControl_Pressed_Implementation()
{

}

void ACOVCharacter::Input_LeftControl_Released_Implementation()
{

}

void ACOVCharacter::Input_Interact_Implementation()
{
	//	We need the focus component for this
	if(!IsValid(FocusComponent))
	{
		COV_LOG(COVCharacter, Warning, TEXT("No FocusComponent found on character. Can't focus to interact with anything."));
		return;
	}

	//	Find out the actor that the player is focusing on
	AActor* focusedActor = FocusComponent->GetFocusedActor();
	if (IsValid(focusedActor))
	{
		//	Make sure the focused actor is interactable
		if (focusedActor->Implements<UCOVInteractable>())
		{
			//	Can the focused actor be interacted with right now?
			if (ICOVInteractable::Execute_GetIsInteractable(focusedActor))
			{
				//	Interaction will be successful
				COV_LOG(COVCharacter, Log, TEXT("Character (%s) interacting with actor (%s)."), *GetNameSafe(this), *GetNameSafe(focusedActor));
				Input_Interact_Server(focusedActor);

			}
			else
			{
				COV_LOG(COVCharacter, Log, TEXT("Character (%s) interacted with actor (%s), but it was not interactable."), *GetNameSafe(this), *GetNameSafe(focusedActor));
				return;
			}
		}
		else
		{
			COV_LOG(COVCharacter, Log, TEXT("Character (%s) interacting with actor (%s), but the actor does not implement the interface 'Interactable'."), *GetNameSafe(this), *GetNameSafe(focusedActor));
			return;
		}
	}
	else
	{
		COV_LOG(COVCharacter, Log, TEXT("Character (%s) has nothing to interact with."), *GetNameSafe(this));
	}
}

void ACOVCharacter::Input_MovementInput_Implementation(float amount)
{
	if (SmoothMotionComponent)
	{
		SmoothMotionComponent->SetShouldRotateHips(amount != 0);
	}
}

void ACOVCharacter::Input_MoveForward_Implementation(float amount)
{
	if (this != nullptr)
	{
		auto cam = GetCharacterCamera();

		if (!IsValid(cam))
			return;

		FVector dir = cam->GetForwardVector();
		dir.Z = 0.0f;
		dir.Normalize();
		AddMovementInput(dir * amount);
	}
}

void ACOVCharacter::Input_MoveRight_Implementation(float amount)
{
	if (this != nullptr)
	{
		TWeakObjectPtr<UCameraComponent> cam = GetCharacterCamera();

		if (!cam.IsValid())
			return;

		FVector dir = cam->GetRightVector();
		dir.Z = 0.0f;
		dir.Normalize();
		AddMovementInput(dir * amount);
	}
}
//	INPUTS	############################################################################################################################

UCameraComponent* ACOVCharacter::GetCharacterCamera() const
{
	auto cam = Cast<UCameraComponent>(FindComponentByClass(UCameraComponent::StaticClass()));

	//	Error handling
	if (!IsValid(cam))
	{
		COV_LOG(COVCharacter, Error, TEXT("Could not find camera on COVCharacter or it is pending kill."));
	}

	return cam;
}

ACOVPlayerController* ACOVCharacter::GetCOVPlayerController() const
{
	ACOVPlayerController* playerController = Cast<ACOVPlayerController>(GetController());

	if (!IsValid(playerController))
	{
		COV_LOG(COVCharacter, Error, TEXT("No COVPlayerController found on character (%s). Is this intentional?"), *GetName());
	}

	return playerController;
}

void ACOVCharacter::COV_ShowCharacterAimingVectors(bool bOn)
{
	_bDebugModeIsOn = bOn;
	SetActorTickEnabled(bOn);
	COV_LOG(COVCharacter, Warning, TEXT("TODO"));
}

// Called every frame
void ACOVCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (_bDebugModeIsOn && IsValid(SmoothMotionComponent))
	{
		UE4CodeHelpers::SimpleTraceByChannel(this, GetCharacterCamera()->GetComponentLocation(), SmoothMotionComponent->GetAimingLocation(), ECollisionChannel::ECC_Visibility, FName("AimingVector"));
	}
}
