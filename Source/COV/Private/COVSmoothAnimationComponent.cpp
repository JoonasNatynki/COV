// Fill out your copyright notice in the Description page of Project Settings.

#include "COVSmoothAnimationComponent.h"
#include <UnrealNetwork.h>
#include <GameFramework/Character.h>
#include <GameFramework/CharacterMovementComponent.h>
#include "COVBlueprintFunctionLibrary.h"
#include <Kismet/KismetMathLibrary.h>
#include <Camera/CameraComponent.h>
#include <Components/SkeletalMeshComponent.h>
#include <Kismet/KismetSystemLibrary.h>
#include <DrawDebugHelpers.h>

DEFINE_LOG_CATEGORY(COVSmoothAnimation)

// Sets default values for this component's properties
UCOVSmoothAnimationComponent::UCOVSmoothAnimationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//SetTickGroup(ETickingGroup::TG_PrePhysics);	//	Maybe set post update group so that animation has time to finish?
	AddTickPrerequisiteActor(GetOwner());
	bReplicates = true;
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
	DOREPLIFETIME_CONDITION(UCOVSmoothAnimationComponent, _bShouldBeRotatingHips, COND_SkipOwner);
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

void UCOVSmoothAnimationComponent::OnRep_currentMaximumMovementSpeed()
{
	//UE_LOG(XYZCharacter, Log, TEXT("%s: ONREP!."), PRINT_FUNCTION);

	TWeakObjectPtr<UCharacterMovementComponent> charMove = Cast<ACharacter>(GetOwner())->GetCharacterMovement();

	if (charMove.IsValid())
	{
		Cast<ACharacter>(GetOwner())->GetCharacterMovement()->MaxWalkSpeed = _currentMaximumMovementSpeed;
	}
}

float UCOVSmoothAnimationComponent::GetYaw() const
{
	return _upperTorsoYaw;
}

float UCOVSmoothAnimationComponent::GetPitch() const
{
	return _upperTorsoPitch;
}

FRotator UCOVSmoothAnimationComponent::GetHipRotation() const
{
	return _actorRotation;
}

bool UCOVSmoothAnimationComponent::GetShouldBeRotatingHips() const
{
	return _bShouldBeRotatingHips;
}

FVector UCOVSmoothAnimationComponent::GetAimingLocation() const
{
	return _aimingLocation;
}

FVector UCOVSmoothAnimationComponent::GetHeadLocation() const
{
	TWeakObjectPtr<USkeletalMeshComponent> ownerSkeletalMeshComp = Cast<USkeletalMeshComponent>(GetOwner()->GetComponentByClass(USkeletalMeshComponent::StaticClass()));

	ensureMsgf(ownerSkeletalMeshComp.IsValid(), TEXT("Owner (%s) did not have a SkeletalMeshComponent."), *UKismetSystemLibrary::GetDisplayName(GetOwner()));

	if (ownerSkeletalMeshComp.IsValid())
	{
		bool socketDoesExist = ownerSkeletalMeshComp->DoesSocketExist("Head");
		if (!socketDoesExist)
		{
			ensureMsgf(socketDoesExist, TEXT("Owner (%s) did not have a socket named 'head'."), *UKismetSystemLibrary::GetDisplayName(GetOwner()));
			return FVector(0, 0, 0);
		}

		FVector headLoc = ownerSkeletalMeshComp->GetSocketLocation("Head");
		return headLoc;
	}

	return FVector(0, 0, 0);
}

FRotator UCOVSmoothAnimationComponent::GetAimPitchTargetRotation() const
{
	if (AimOffsetMode == EAimOffsetCalculationMode::ControlRotation)
	{
		FRotator targetRot = Cast<ACharacter>(GetOwner())->GetControlRotation();
		return targetRot;
	}

	if (AimOffsetMode == EAimOffsetCalculationMode::AimLocation)
	{
		FRotator targetRot = UKismetMathLibrary::FindLookAtRotation(GetHeadLocation(), GetAimingLocation());
		return targetRot;
	}

	return FRotator(0, 0, 0);
}

void UCOVSmoothAnimationComponent::SetYaw(float yaw)
{
	_upperTorsoYaw = yaw;
	Server_SetYaw(yaw);
}

void UCOVSmoothAnimationComponent::SetPitch(float pitch)
{
	_upperTorsoPitch = pitch;
	Server_SetPitch(pitch);
}

void UCOVSmoothAnimationComponent::SetHipRotation(FRotator rot)
{
	_actorRotation = rot;
	Server_SetActorRotation(rot);
}

void UCOVSmoothAnimationComponent::SetShouldRotateHips(float inputAmount)
{
	_bShouldBeRotatingHips = inputAmount != 0.0f;
}

void UCOVSmoothAnimationComponent::SetCurrentWalkingSpeed(float currentWalkingSpeed)
{
	if (GetOwner()->Role == ENetRole::ROLE_AutonomousProxy)
	{
		_currentMaximumMovementSpeed = currentWalkingSpeed;
		OnRep_currentMaximumMovementSpeed();
		Server_SetCurrentWalkingSpeed(_currentMaximumMovementSpeed);
	}
}

void UCOVSmoothAnimationComponent::SetAimingLocation(FVector loc)
{
	_aimingLocation = loc;
	Server_SetAimingLocation(loc);
}

float UCOVSmoothAnimationComponent::CalculateYaw()
{
	float angleToStartRotatingHips = 125.0f;
	float angleToStopRotatingHips = 20.0f;
	float torsoMaxRotation = 140.0f;

	FRotator playerRot = _actorRotation;	//	REALLY IMPORTANT PART! TAKE ROTATION OF LAST CALCULATION NOT THE CURRENT ONE!
	FRotator targetRot = GetAimPitchTargetRotation();
	FRotator deltaRot = UKismetMathLibrary::NormalizedDeltaRotator(targetRot, playerRot);

	//	If hips turn over too much...
	if (FMath::Abs(deltaRot.Yaw) > angleToStartRotatingHips)
	{
		//	We clamp the yaw so that the torso can't rotate in a silly manner
		float actualYaw = UKismetMathLibrary::ClampAngle(deltaRot.Yaw - 360.0f, -torsoMaxRotation, torsoMaxRotation);
		return actualYaw;
	}
	else   //	Need to rotate character towards the target
	{
		//	We clamp the yaw so that the torso can't rotate in a silly manner
		float actualYaw = UKismetMathLibrary::ClampAngle(deltaRot.Yaw, -torsoMaxRotation, torsoMaxRotation);
		return actualYaw;
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
		GetOwner(),
		camWorldLoc + (camFwdVec * (-20.0f)),
		camWorldLoc + (camFwdVec * lineTraceLength));

	if (RV_Hit.bBlockingHit)
	{
		FVector result = RV_Hit.ImpactPoint;
		return result;
	}
	else
	{
		FVector result = RV_Hit.TraceEnd;
		return result;
	}
}

float UCOVSmoothAnimationComponent::CalculatePitch()
{
	FRotator targetRot = GetAimPitchTargetRotation();

	if (targetRot.Pitch > 90)
	{
		return (targetRot.Pitch - 360.0f);
	}
	else
	{
		return targetRot.Pitch;
	}
}

FRotator UCOVSmoothAnimationComponent::CalculateHipRotation(float deltaTime)
{
	FRotator goalRotation = Cast<ACharacter>(GetOwner())->GetControlRotation();
	FRotator startRotation = _actorRotation;

	float absAngle = FMath::Abs(_upperTorsoYaw);

	if (absAngle > _angleToStartRotatingHips || _bShouldBeRotatingHips)
	{
		float rotSpeed;
		float rotExp = 5.5f;	//	Hip rotation angle exponent

		_bShouldBeRotatingHips ? rotSpeed = _movementInputRotationSpeed : rotSpeed = (FMath::Pow((absAngle / _angleToStartRotatingHips), rotExp) * 0.25f);
		FRotator result = UKismetMathLibrary::RInterpTo(startRotation, goalRotation, deltaTime, rotSpeed);
		result.Pitch = 0;
		result.Roll = 0;
		return result;
	}

	return startRotation;
}

FRotator UCOVSmoothAnimationComponent::CalculateHeadRotation() const
{
	FVector headLoc = GetHeadLocation();
	FVector aimingLoc = _aimingLocation;
	FRotator tempRot = UKismetMathLibrary::FindLookAtRotation(headLoc, aimingLoc);
	FRotator headRot = FRotator(90.0f, 0, 90.0f);
	headRot += tempRot;

	return headRot;

	return FRotator(0, 0, 0);
}

void UCOVSmoothAnimationComponent::Update_AllAnimationVariables_TICK(float deltaTime)
{
	SetHipRotation(CalculateHipRotation(deltaTime));
	SetYaw(CalculateYaw());
	SetPitch(CalculatePitch());
	SetAimingLocation(CalculateAimingLocation());
}

// Called every frame
void UCOVSmoothAnimationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (GetOwner()->Role == ENetRole::ROLE_AutonomousProxy)
	{
		Update_AllAnimationVariables_TICK(DeltaTime);
	}

	DrawDebugSphere(GetWorld(), GetAimingLocation(), 10.0f, 12, FColor(255, 0, 255, 1), false, 0.0f, 1, 1.0f);
	DrawDebugLine(GetWorld(), GetHeadLocation(), GetAimingLocation(), FColor(255, 0, 255, 1), false, 0.0f, 1, 0.5f);
}

