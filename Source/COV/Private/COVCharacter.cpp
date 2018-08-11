// Fill out your copyright notice in the Description page of Project Settings.

#include "COVCharacter.h"
#include "COVPlayerController.h"
#include "COVBlueprintFunctionLibrary.h"
#include "Engine.h"
#include "UnrealNetwork.h"
#include <Kismet/KismetMathLibrary.h>

DEFINE_LOG_CATEGORY(XYZCharacter)

// Sets default values
ACOVCharacter::ACOVCharacter(const class FObjectInitializer& PCIP)/* : Super(PCIP.SetDefaultSubobjectClass<UXYZ_CharacterMovementComponent>(ACharacter::CharacterMovementComponentName))*/
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorTickEnabled(true);
	SetTickGroup(ETickingGroup::TG_PrePhysics);	//	Maybe set post update group so that animation has time to finish?

	this->bAlwaysRelevant = true;
}

// Called when the game starts or when spawned
void ACOVCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void ACOVCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

//	Required for network replication of variables
void ACOVCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty, FDefaultAllocator>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//	Add replicated variables to list using this macro
	DOREPLIFETIME_CONDITION(ACOVCharacter, _upperTorsoYaw, COND_SkipOwner);
	DOREPLIFETIME_CONDITION(ACOVCharacter, _upperTorsoPitch, COND_SkipOwner);
	DOREPLIFETIME_CONDITION(ACOVCharacter, _aimingLocation, COND_SkipOwner);
	DOREPLIFETIME_CONDITION(ACOVCharacter, _actorRotation, COND_SkipOwner);
	DOREPLIFETIME_CONDITION(ACOVCharacter, _bIsReceivingMovementInput, COND_SkipOwner);
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

bool ACOVCharacter::Server_SetAimingLocation_Validate(FVector aimingVector)
{
	return true;
}

void ACOVCharacter::Server_SetAimingLocation_Implementation(FVector aimLoc)
{
	_aimingLocation = aimLoc;
}

bool ACOVCharacter::Server_SetActorRotation_Validate(FRotator actorRotation)
{
	return true;
}

void ACOVCharacter::Server_SetActorRotation_Implementation(FRotator actorRotation)
{
	_actorRotation = actorRotation;
}

bool ACOVCharacter::Server_SetPitch_Validate(float pitch)
{
	return true;
}

void ACOVCharacter::Server_SetPitch_Implementation(float pitch)
{
	_upperTorsoPitch = pitch;
}

bool ACOVCharacter::Server_SetYaw_Validate(float yaw)
{
	return true;
}

void ACOVCharacter::Server_SetYaw_Implementation(float yaw)
{
	_upperTorsoYaw = yaw;
}

void ACOVCharacter::Input_MoveForward(float amount)
{
	if (this != nullptr)
	{
		UCameraComponent* cam = GetCharacterCamera();

		if (!IsValid(cam))
			return;

		FVector dir = cam->GetForwardVector();
		dir.Z = 0.0f;
		dir.Normalize();
		AddMovementInput(dir * amount);
		_bIsReceivingForwardInput = amount != 0.0f;
	}
}

void ACOVCharacter::Input_MoveRight(float amount)
{
	if (this != nullptr)
	{
		UCameraComponent* cam = GetCharacterCamera();

		if (!IsValid(cam))
			return;

		FVector dir = cam->GetRightVector();
		dir.Z = 0.0f;
		dir.Normalize();
		AddMovementInput(dir * amount);
		_bIsReceivingRightInput = amount != 0.0f;
	}
}

void ACOVCharacter::Update_IsReceivingMovementInput()
{
	if (_bIsReceivingForwardInput || _bIsReceivingRightInput)
	{
		_bIsReceivingMovementInput = true;
	}
	else
	{
		_bIsReceivingMovementInput = false;
	}
}

void ACOVCharacter::Input_AimUp(float amount)
{
	if (this != nullptr)
		_upperTorsoPitch += amount;
}

void ACOVCharacter::Input_AimRight(float amount)
{
	if (this != nullptr)
		_upperTorsoYaw += amount;
}

float ACOVCharacter::CalculateYaw()
{
	float angleToStartRotatingHips = 125.0f;
	float angleToStopRotatingHips = 20.0f;
	float torsoMaxRotation = 140.0f;

	IS_NOT_LOCALLY_CONTROLLED_WARNING;

	FRotator controlRot = GetControlRotation();
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

float ACOVCharacter::GetYaw()
{
	return _upperTorsoYaw;
}

float ACOVCharacter::CalculatePitch()
{
	IS_NOT_LOCALLY_CONTROLLED_WARNING;

	FRotator controlRot = GetControlRotation();

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

float ACOVCharacter::GetPitch()
{
	return _upperTorsoPitch;
}

UCameraComponent* ACOVCharacter::GetCharacterCamera() const
{
	UCameraComponent* cam = Cast<UCameraComponent>(FindComponentByClass(UCameraComponent::StaticClass()));
	//	Error handling
	if (!IsValid(cam))
	{
		UE_LOG(XYZCharacter, Error, TEXT("%s: Could not find camera on XYZ_Character or it is pending kill."), PRINT_FUNCTION);
	}
	return cam;
}

FVector ACOVCharacter::GetEyeWorldLocation() const
{
	UCameraComponent * cam = GetCharacterCamera();

	//	Error case
	if (!IsValid(cam))
		return FVector(0, 0, 0);

	return cam->GetComponentLocation();
}

FVector ACOVCharacter::GetAimingVector()
{
	FVector aimingVec = GetAimingLocation() - GetEyeWorldLocation();
	return aimingVec;
}

FVector ACOVCharacter::CalculateAimingLocation()
{
	IS_NOT_LOCALLY_CONTROLLED_WARNING;

	UCameraComponent* cam = GetCharacterCamera();

	if (!IsValid(cam))
	{
		UE_LOG(XYZCharacter, Error, TEXT("%s: No camera found!"), PRINT_FUNCTION);
		_aimingLocation = FVector(0, 0, 0);
		return _aimingLocation;
	}

	FHitResult RV_Hit(ForceInit);
	FVector camWorldLoc = GetEyeWorldLocation();
	FVector camFwdVec = cam->GetForwardVector();
	float lineTraceLength = 10000.0f;

	RV_Hit = UCOVBlueprintFunctionLibrary::SimpleTraceByChannel(
		camWorldLoc + (camFwdVec * (-20.0f)),
		camWorldLoc + (camFwdVec * lineTraceLength),
		this);

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

FVector ACOVCharacter::GetAimingLocation()
{
	return _aimingLocation;
}

AActor* ACOVCharacter::TryGetInteractedActor()
{
	FVector eyePos = GetEyeWorldLocation();
	UCameraComponent* cam = GetCharacterCamera();

	if (!IsValid(cam))
	{
		UE_LOG(XYZCharacter, Warning, TEXT("%s: No camera found!"), PRINT_FUNCTION);
		return nullptr;
	}

	FHitResult hit = UCOVBlueprintFunctionLibrary::SimpleTraceByChannel(eyePos, eyePos + (cam->GetForwardVector() * _maximumInteractionDistance), this);

	AActor* interactedActor = hit.Actor.Get();

	//	Check if interact line trace hits and actor or not
	if (!IsValid(interactedActor))
	{
		UE_LOG(XYZCharacter, Log, TEXT("%s: Interact line trace of actor (%s) did not hit anything."), PRINT_FUNCTION, *GetName());
		return nullptr;
	}

	return interactedActor;
}

void ACOVCharacter::Input_Interact()
{
	AActor* interactedActor = TryGetInteractedActor();

	if (IsValid(interactedActor))
		Server_Interact(interactedActor);
}

void ACOVCharacter::Server_Interact_Implementation(AActor* interacted)
{

}

bool ACOVCharacter::Server_Interact_Validate(AActor* interacted)
{
	return true;
}

FRotator ACOVCharacter::GetHipRotation() const
{
	return _actorRotation;
}

FRotator ACOVCharacter::CalculateRotation(float deltaTime)
{
	FRotator controllerRotation = GetControlRotation();
	FRotator actorRotation = _actorRotation;

	float absAngle = FMath::Abs(GetYaw());

	if (absAngle > _angleToStartRotatingHips || _bIsReceivingMovementInput)
	{
		float rotSpeed;
		uint8 rotExp = 6;	//	Hip rotation angle exponent

		_bIsReceivingMovementInput ? rotSpeed = _movementInputRotationSpeed : rotSpeed = FMath::Pow((absAngle / _angleToStartRotatingHips), rotExp);;
		FRotator result = UKismetMathLibrary::RInterpTo(actorRotation, controllerRotation, deltaTime, rotSpeed);
		result.Pitch = 0;
		result.Roll = 0;
		return result;
	}

	return actorRotation;
}

void ACOVCharacter::DrawDebugEyeVector()
{
	FHitResult hitOut(ForceInit);
	TArray<AActor*> actorsToIgnore;
	actorsToIgnore.Add(this);
	UKismetSystemLibrary::LineTraceSingle(this, GetEyeWorldLocation(), GetAimingLocation(), ETraceTypeQuery::TraceTypeQuery_MAX, true, actorsToIgnore, EDrawDebugTrace::ForOneFrame, hitOut, true, FLinearColor(FColor(1, 1, 1, 1)), FLinearColor(FColor(1, 1, 1, 1)), 0.1f);
}

ACOVPlayerController* ACOVCharacter::GetXYZPlayerController() const
{

	ACOVPlayerController* playerController = Cast<ACOVPlayerController>(GetController());

	if (!IsValid(playerController))
	{
		UE_LOG(XYZCharacter, Error, TEXT("%s: No XYZPlayerController found on character (%s). Is this intentional?"), PRINT_FUNCTION, *GetName());
	}

	return playerController;
}

// Called every frame
void ACOVCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//	DEBUGS	###########################################################################################
	if (_bShowDebugForwardVector)
	{
		DrawDebugLine(GetWorld(), GetActorLocation(), (GetActorLocation() + (GetActorForwardVector() * 100)), FColor(0, 0, 1), false, -1, 1, 1);
	}
	//	###################################################################################################

	if (IsLocallyControlled())
	{
		FRotator rot = CalculateRotation(DeltaTime);
		_actorRotation = rot;
		Server_SetActorRotation(rot);

		float yaw = CalculateYaw();
		_upperTorsoYaw = yaw;
		Server_SetYaw(yaw);

		float pitch = CalculatePitch();
		_upperTorsoPitch = pitch;
		Server_SetPitch(pitch);

		FVector aimingLocation = CalculateAimingLocation();
		_aimingLocation = aimingLocation;
		Server_SetAimingLocation(aimingLocation);

		Update_IsReceivingMovementInput();
	}

	DrawDebugEyeVector();
}
