// Fill out your copyright notice in the Description page of Project Settings.

#include "COVCharacter.h"
#include "COVPlayerController.h"
#include "COVBlueprintFunctionLibrary.h"
#include "Engine.h"
#include "UnrealNetwork.h"
#include <Kismet/KismetMathLibrary.h>
#include "COVSmoothAnimationComponent.h"
#include "COVInteractionComponent.h"
#include "COVFocusComponent.h"
#include <Kismet/KismetSystemLibrary.h>

DEFINE_LOG_CATEGORY(COVCharacter)

#define GET_AND_STORE_COMPONENT(_componentclass, _containervariablename) {\
_componentclass* tempComp = nullptr;\
TSet<UActorComponent*> comps = GetComponents();\
for (auto & comp : comps)\
{\
	tempComp = Cast<_componentclass>(comp);\
	if (tempComp)\
	{\
		_containervariablename = tempComp;\
		break;\
	}\
}\
ensureMsgf(tempComp != nullptr, TEXT("##_componentclass Component was not found on the character! Please add it as a component to this character or the character won't work properly!"));\
}\

// Sets default values
ACOVCharacter::ACOVCharacter(const class FObjectInitializer& PCIP)/* : Super(PCIP.SetDefaultSubobjectClass<UXYZ_CharacterMovementComponent>(ACharacter::CharacterMovementComponentName))*/
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorTickEnabled(true);
	bUseControllerRotationYaw = false;
}

// Called when the game starts or when spawned
void ACOVCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ACOVCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	//	Smooth animation component
	GET_AND_STORE_COMPONENT(UCOVSmoothAnimationComponent, SmoothMotionComponent)
	//	Interaction component
	GET_AND_STORE_COMPONENT(UCOVInteractionComponent, InteractionComponent)
	//	Focus component
	GET_AND_STORE_COMPONENT(UCOVFocusComponent, FocusComponent)
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

bool ACOVCharacter::Server_Interact_Validate(AActor* interactedActor)
{
	return true;
}

void ACOVCharacter::Server_Interact_Implementation(AActor* interactedActor)
{
	ICOVInteractable::Execute_Interact(interactedActor, this);
}

void ACOVCharacter::Input_F_Pressed_Implementation()
{
	AActor* focusedActor = FocusComponent->GetFocusedActor();
	if (IsValid(focusedActor))
	{
		if (focusedActor->Implements<UCOVInteractable>())
		{
			//	Interaction will be successful
			COV_LOG(LogTemp, Log, TEXT("Character (%s) interacting with actor (%s)."), *UKismetSystemLibrary::GetDisplayName(this), *UKismetSystemLibrary::GetDisplayName(focusedActor));
			Server_Interact(focusedActor);
		}
		else
		{
			COV_LOG(LogTemp, Log, TEXT("Character (%s) interacting with actor (%s), but the actor does not implement the interface 'Interactable'."), *UKismetSystemLibrary::GetDisplayName(this), *UKismetSystemLibrary::GetDisplayName(focusedActor));
			return;
		}
	}
	else
	{
		COV_LOG(LogTemp, Log, TEXT("Character (%s) has nothing to interact with."), *UKismetSystemLibrary::GetDisplayName(this));
	}
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
	if (SmoothMotionComponent)
	{
		SmoothMotionComponent->SetCurrentMovementSpeed(SmoothMotionComponent->GetDefaultRunningSpeed());
	}
	else
	{
		COV_LOG(LogTemp, Error, TEXT("VITTU!"));
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

void ACOVCharacter::Input_MouseMovementY_Implementation(float amount)
{

}

void ACOVCharacter::Input_MouseMovementX_Implementation(float amount)
{

}

void ACOVCharacter::Input_MovementInput_Implementation(float amount)
{
	if (SmoothMotionComponent)
	{
		SmoothMotionComponent->SetShouldRotateHips(amount != 0);
	}
}

void ACOVCharacter::Input_MoveForward(float amount)
{
	if (this != nullptr)
	{
		TWeakObjectPtr<UCameraComponent> cam = GetCharacterCamera();

		if (!cam.IsValid())
			return;

		FVector dir = cam->GetForwardVector();
		dir.Z = 0.0f;
		dir.Normalize();
		AddMovementInput(dir * amount);
	}
}

void ACOVCharacter::Input_MoveRight(float amount)
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
	TWeakObjectPtr<UCameraComponent> cam = Cast<UCameraComponent>(FindComponentByClass(UCameraComponent::StaticClass()));

	//	Error handling
	if (!cam.IsValid())
	{
		COV_LOG(COVCharacter, Error, TEXT("Could not find camera on COVCharacter or it is pending kill."));
	}

	return cam.Get();
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

void ACOVCharacter::ShowAimingVectors(bool bOn)
{
	_bDebugModeIsOn = bOn;
}

void ACOVCharacter::DebugHelpers_TICK() const
{
	if (_bDebugModeIsOn)
	{
		FVector aimLocation = SmoothMotionComponent->GetAimingLocation();
		DrawDebugSphere(GetWorld(), aimLocation, 5.0f, 4, FColor(255, 0, 0, 255), false, 0.0f, 0, 1.0f);
		DrawDebugLine(GetWorld(), SmoothMotionComponent->CalculateHeadLocation(), aimLocation, FColor(255, 0, 0, 255), false, 0.0f, 1, 0.5f);
	}
}

// Called every frame
void ACOVCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DebugHelpers_TICK();
}
