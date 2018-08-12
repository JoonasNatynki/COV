// Fill out your copyright notice in the Description page of Project Settings.

#include "COVCharacter.h"
#include "COVPlayerController.h"
#include "COVBlueprintFunctionLibrary.h"
#include "Engine.h"
#include "UnrealNetwork.h"
#include <Kismet/KismetMathLibrary.h>
#include "COVSmoothAnimationComponent.h"

DEFINE_LOG_CATEGORY(COVCharacter)

// Sets default values
ACOVCharacter::ACOVCharacter(const class FObjectInitializer& PCIP)/* : Super(PCIP.SetDefaultSubobjectClass<UXYZ_CharacterMovementComponent>(ACharacter::CharacterMovementComponentName))*/
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorTickEnabled(true);
	//SetTickGroup(ETickingGroup::TG_PrePhysics);	//	Maybe set post update group so that animation has time to finish?

	//this->bAlwaysRelevant = true;
	bUseControllerRotationYaw = false;

	SmoothMotionComponent = CreateDefaultSubobject<UCOVSmoothAnimationComponent>(TEXT("Smooth Motion Component"));
}

// Called when the game starts or when spawned
void ACOVCharacter::BeginPlay()
{
	Super::BeginPlay();
}

//	Required for network replication of variables
void ACOVCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty, FDefaultAllocator>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);	
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
	SmoothMotionComponent->SetCurrentWalkingSpeed(SmoothMotionComponent->_defaultMaximumRunningSpeed);
}

void ACOVCharacter::Input_LeftShift_Released_Implementation()
{
	SmoothMotionComponent->SetCurrentWalkingSpeed(SmoothMotionComponent->_defaultMaximumWalkingSpeed);
}

void ACOVCharacter::Input_E_Pressed_Implementation()
{

}

void ACOVCharacter::Input_E_Released_Implementation()
{

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
		SmoothMotionComponent->SetShouldRotateHips(amount != 0.0f);
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
		SmoothMotionComponent->SetShouldRotateHips(amount != 0.0f);
	}
}

void ACOVCharacter::Input_Interact()
{
	AActor* interactedActor = TryGetInteractedActor();
}

FVector ACOVCharacter::GetEyeWorldLocation() const
{
	TWeakObjectPtr<UCameraComponent> cam = GetCharacterCamera();

	//	Error case
	if (!cam.IsValid())
		return FVector(0, 0, 0);

	return cam->GetComponentLocation();
}

UCameraComponent* ACOVCharacter::GetCharacterCamera() const
{
	TWeakObjectPtr<UCameraComponent> cam = Cast<UCameraComponent>(FindComponentByClass(UCameraComponent::StaticClass()));
	//	Error handling
	if (!cam.IsValid())
	{
		UE_LOG(COVCharacter, Error, TEXT("%s: Could not find camera on XYZ_Character or it is pending kill."), PRINT_FUNCTION);
	}
	return cam.Get();
}

ACOVPlayerController* ACOVCharacter::GetCOVPlayerController() const
{

	ACOVPlayerController* playerController = Cast<ACOVPlayerController>(GetController());

	if (!IsValid(playerController))
	{
		UE_LOG(COVCharacter, Error, TEXT("%s: No XYZPlayerController found on character (%s). Is this intentional?"), PRINT_FUNCTION, *GetName());
	}

	return playerController;
}

FVector ACOVCharacter::GetAimingLocation()
{
	return SmoothMotionComponent->_aimingLocation;
}

FVector ACOVCharacter::GetAimingVector()
{
	FVector aimingVec = GetAimingLocation() - GetEyeWorldLocation();
	return aimingVec;
}

float ACOVCharacter::GetYaw()
{
	return SmoothMotionComponent->_upperTorsoYaw;
}

float ACOVCharacter::GetPitch()
{
	return SmoothMotionComponent->_upperTorsoPitch;
}

FRotator ACOVCharacter::GetHipRotation() const
{
	return SmoothMotionComponent->_actorRotation;
}

AActor* ACOVCharacter::TryGetInteractedActor()
{
	FVector eyePos = GetEyeWorldLocation();
	TWeakObjectPtr<UCameraComponent> cam = GetCharacterCamera();

	if (!cam.IsValid())
	{
		UE_LOG(COVCharacter, Warning, TEXT("%s: No camera found!"), PRINT_FUNCTION);
		return nullptr;
	}

	FHitResult hit = UCOVBlueprintFunctionLibrary::SimpleTraceByChannel(this, eyePos, eyePos + (cam->GetForwardVector() * _maximumInteractionDistance));

	AActor* interactedActor = hit.Actor.Get();

	//	Check if interact line trace hits and actor or not
	if (!IsValid(interactedActor))
	{
		UE_LOG(COVCharacter, Log, TEXT("%s: Interact line trace of actor (%s) did not hit anything."), PRINT_FUNCTION, *GetName());
		return nullptr;
	}

	return interactedActor;
}

void ACOVCharacter::DrawDebugEyeVector()
{
	FHitResult hitOut(ForceInit);
	TArray<AActor*> actorsToIgnore;
	actorsToIgnore.Add(this);
	UKismetSystemLibrary::LineTraceSingle(this, GetEyeWorldLocation(), GetAimingLocation(), ETraceTypeQuery::TraceTypeQuery_MAX, true, actorsToIgnore, EDrawDebugTrace::ForOneFrame, hitOut, true, FLinearColor(FColor(1, 1, 1, 1)), FLinearColor(FColor(1, 1, 1, 1)), 0.1f);
}

// Called every frame
void ACOVCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	DrawDebugEyeVector();
}
