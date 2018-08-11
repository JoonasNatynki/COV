// Fill out your copyright notice in the Description page of Project Settings.

#include "COVSmoothAnimationComponent.h"
#include <UnrealNetwork.h>
#include <GameFramework/Character.h>
#include <GameFramework/CharacterMovementComponent.h>
#include "COVBlueprintFunctionLibrary.h"
#include <Kismet/KismetMathLibrary.h>
#include <Camera/CameraComponent.h>


// Sets default values for this component's properties
UCOVSmoothAnimationComponent::UCOVSmoothAnimationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	SetTickGroup(ETickingGroup::TG_PrePhysics);	//	Maybe set post update group so that animation has time to finish?
	bReplicates = true;
	// ...
	//	Initialize the variable. Will be set properly in the BeginPlay	
	_defaultMaximumWalkingSpeed = _defaultMaximumWalkingSpeed;
}


// Called when the game starts
void UCOVSmoothAnimationComponent::BeginPlay()
{
	Super::BeginPlay();

	if (Cast<ACharacter>(GetOwner())->IsLocallyControlled())
		SetCurrentWalkingSpeed(_defaultMaximumWalkingSpeed);
}

void UCOVSmoothAnimationComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty, FDefaultAllocator>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//	Add replicated variables to list using this macro
	DOREPLIFETIME_CONDITION(UCOVSmoothAnimationComponent, _upperTorsoYaw, COND_SkipOwner);
	DOREPLIFETIME_CONDITION(UCOVSmoothAnimationComponent, _upperTorsoPitch, COND_SkipOwner);
	DOREPLIFETIME_CONDITION(UCOVSmoothAnimationComponent, _aimingLocation, COND_SkipOwner);
	DOREPLIFETIME_CONDITION(UCOVSmoothAnimationComponent, _actorRotation, COND_SkipOwner);
	DOREPLIFETIME_CONDITION(UCOVSmoothAnimationComponent, _bIsReceivingMovementInput, COND_SkipOwner);
	DOREPLIFETIME_CONDITION(UCOVSmoothAnimationComponent, _currentMaximumMovementSpeed, COND_SkipOwner);
}

bool UCOVSmoothAnimationComponent::Server_SetAimingLocation_Validate(FVector aimingVector)
{
	return true;
}

void UCOVSmoothAnimationComponent::Server_SetAimingLocation_Implementation(FVector aimLoc)
{
	_aimingLocation = aimLoc;
}

bool UCOVSmoothAnimationComponent::Server_SetActorRotation_Validate(FRotator actorRotation)
{
	return true;
}

void UCOVSmoothAnimationComponent::Server_SetActorRotation_Implementation(FRotator actorRotation)
{
	_actorRotation = actorRotation;
}

bool UCOVSmoothAnimationComponent::Server_SetPitch_Validate(float pitch)
{
	return true;
}

void UCOVSmoothAnimationComponent::Server_SetPitch_Implementation(float pitch)
{
	_upperTorsoPitch = pitch;
}

bool UCOVSmoothAnimationComponent::Server_SetYaw_Validate(float yaw)
{
	return true;
}

void UCOVSmoothAnimationComponent::Server_SetYaw_Implementation(float yaw)
{
	_upperTorsoYaw = yaw;
}

bool UCOVSmoothAnimationComponent::Server_SetCurrentWalkingSpeed_Validate(float currentWalkingSpeed)
{
	return true;
}

void UCOVSmoothAnimationComponent::Server_SetCurrentWalkingSpeed_Implementation(float currentWalkingSpeed)
{
	_currentMaximumMovementSpeed = currentWalkingSpeed;
	OnRep_currentMaximumMovementSpeed();
	//UE_LOG(XYZCharacter, Log, TEXT("%s: SERVER FUNCTION CALLED!."), PRINT_FUNCTION);
}

void UCOVSmoothAnimationComponent::Server_Interact_Implementation(AActor* interacted)
{

}

bool UCOVSmoothAnimationComponent::Server_Interact_Validate(AActor* interacted)
{
	return true;
}

void UCOVSmoothAnimationComponent::SetCurrentWalkingSpeed(float currentWalkingSpeed)
{
	if (Cast<ACharacter>(GetOwner())->IsLocallyControlled())
	{
		_currentMaximumMovementSpeed = currentWalkingSpeed;
		OnRep_currentMaximumMovementSpeed();
		Server_SetCurrentWalkingSpeed(_currentMaximumMovementSpeed);
	}
}

void UCOVSmoothAnimationComponent::OnRep_currentMaximumMovementSpeed()
{
	//UE_LOG(XYZCharacter, Log, TEXT("%s: ONREP!."), PRINT_FUNCTION);

	TWeakObjectPtr<UCharacterMovementComponent> charMove = Cast<ACharacter>(GetOwner())->GetCharacterMovement();

	if (charMove.IsValid())
	{
		Cast<ACharacter>(GetOwner())->GetCharacterMovement()->MaxWalkSpeed = _currentMaximumMovementSpeed;
	}
}

float UCOVSmoothAnimationComponent::CalculateYaw()
{
	float angleToStartRotatingHips = 125.0f;
	float angleToStopRotatingHips = 20.0f;
	float torsoMaxRotation = 140.0f;

	FRotator controlRot = Cast<ACharacter>(GetOwner())->GetControlRotation();
	FRotator playerRot = _actorRotation;	//	REALLY IMPORTANT PART! TAKE ROTATION OF LAST CALCULATION NOT THE CURRENT ONE!
	FRotator deltaRot = UKismetMathLibrary::NormalizedDeltaRotator(controlRot, playerRot);

	//	If hips turn over too much...
	if (FMath::Abs(deltaRot.Yaw) > angleToStartRotatingHips)
	{
		float clampedYaw = UKismetMathLibrary::ClampAngle(deltaRot.Yaw - 360.0f, -torsoMaxRotation, torsoMaxRotation);

		Server_SetYaw(clampedYaw);
		return clampedYaw;
	}
	else   //	Need to rotate character towards _aimingVector
	{
		float clampedYaw = UKismetMathLibrary::ClampAngle(deltaRot.Yaw, -torsoMaxRotation, torsoMaxRotation);

		Server_SetYaw(clampedYaw);
		return clampedYaw;
	}
}


FVector UCOVSmoothAnimationComponent::CalculateAimingLocation()
{
	TWeakObjectPtr<UCameraComponent> cam = Cast<UCameraComponent>(Cast<ACharacter>(GetOwner())->GetComponentByClass(UCameraComponent::StaticClass()));

	if (!cam.IsValid())
	{
		//UE_LOG(COVCharacter, Error, TEXT("%s: No camera found!"), PRINT_FUNCTION);
		_aimingLocation = FVector(0, 0, 0);
		return _aimingLocation;
	}

	FHitResult RV_Hit(ForceInit);
	FVector camWorldLoc = cam->GetComponentLocation();
	FVector camFwdVec = cam->GetForwardVector();
	float lineTraceLength = 10000.0f;

	RV_Hit = UCOVBlueprintFunctionLibrary::SimpleTraceByChannel(
		this,
		camWorldLoc + (camFwdVec * (-20.0f)),
		camWorldLoc + (camFwdVec * lineTraceLength));

	if (RV_Hit.bBlockingHit)
	{
		FVector result = RV_Hit.ImpactPoint;
		Server_SetAimingLocation(result);
		return result;
	}
	else
	{
		FVector result = RV_Hit.TraceEnd;
		Server_SetAimingLocation(result);
		return result;
	}
}

bool UCOVSmoothAnimationComponent::CalculateIsReceivingMovementInput()
{
	return _bIsReceivingForwardInput || _bIsReceivingRightInput;
}

float UCOVSmoothAnimationComponent::CalculatePitch()
{
	FRotator controlRot = Cast<ACharacter>(GetOwner())->GetControlRotation();

	if (controlRot.Pitch > 90)
	{
		Server_SetPitch(controlRot.Pitch - 360.0f);
		return (controlRot.Pitch - 360.0f);
	}
	else
	{
		Server_SetPitch(controlRot.Pitch);
		return controlRot.Pitch;
	}
}

FRotator UCOVSmoothAnimationComponent::CalculateRotation(float deltaTime)
{
	FRotator controllerRotation = Cast<ACharacter>(GetOwner())->GetControlRotation();
	FRotator actorRotation = _actorRotation;

	float absAngle = FMath::Abs(_upperTorsoYaw);

	if (absAngle > _angleToStartRotatingHips || _bIsReceivingMovementInput)
	{
		float rotSpeed;
		uint8 rotExp = 6;	//	Hip rotation angle exponent

		_bIsReceivingMovementInput ? rotSpeed = _movementInputRotationSpeed : rotSpeed = FMath::Pow((absAngle / _angleToStartRotatingHips), rotExp);
		FRotator result = UKismetMathLibrary::RInterpTo(actorRotation, controllerRotation, deltaTime, rotSpeed);
		result.Pitch = 0;
		result.Roll = 0;
		return result;
	}

	return actorRotation;
}

void UCOVSmoothAnimationComponent::Update_AllAnimationVariables_TICK(float deltaTime)
{
	_actorRotation = CalculateRotation(deltaTime);
	Server_SetActorRotation(_actorRotation);

	_upperTorsoYaw = CalculateYaw();
	Server_SetYaw(_upperTorsoYaw);

	_upperTorsoPitch = CalculatePitch();
	Server_SetPitch(_upperTorsoPitch);

	_aimingLocation = CalculateAimingLocation();
	Server_SetAimingLocation(_aimingLocation);

	_bIsReceivingMovementInput = CalculateIsReceivingMovementInput();
}

// Called every frame
void UCOVSmoothAnimationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Cast<ACharacter>(GetOwner())->IsLocallyControlled())
	{
		Update_AllAnimationVariables_TICK(DeltaTime);
	}
}

