// Fill out your copyright notice in the Description page of Project Settings.

#include "COVSmoothAnimationComponent.h"
#include <UnrealNetwork.h>
#include <GameFramework/Character.h>
#include <GameFramework/CharacterMovementComponent.h>
#include <Kismet/KismetMathLibrary.h>
#include <Camera/CameraComponent.h>
#include <Components/SkeletalMeshComponent.h>
#include <Kismet/KismetSystemLibrary.h>
#include <DrawDebugHelpers.h>
#include <GameFramework/Pawn.h>
#include <GameFramework/PlayerController.h>
#include <CoreGlobals.h>
#include "UE4Helpers.h"

DEFINE_LOG_CATEGORY(COVSmoothAnimation)

#define IS_LOCALLY_CONTROLLED Cast<APawn>(GetOwner())->IsLocallyControlled()

// Sets default values for this component's properties
UCOVSmoothAnimationComponent::UCOVSmoothAnimationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//PrimaryComponentTick.TickGroup = ETickingGroup::TG_PostUpdateWork;	//	IMPORTANT FOR TICK TO NOT LAG BEHIND IF DRAWING DEBUG THINGS
	AddTickPrerequisiteActor(GetOwner());
	SetIsReplicatedByDefault(true);
}

// Called when the game starts
void UCOVSmoothAnimationComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UCOVSmoothAnimationComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty, FDefaultAllocator>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//	Add replicated variables to list using this macro
	DOREPLIFETIME_CONDITION(UCOVSmoothAnimationComponent, AnimationCache, COND_SkipOwner);
	DOREPLIFETIME_CONDITION(UCOVSmoothAnimationComponent, _bShouldBeRotatingHips, COND_SkipOwner);
}

bool UCOVSmoothAnimationComponent::Server_SetAimingLocation_Validate(const FVector& aimingVector)
{
	return true;
}

void UCOVSmoothAnimationComponent::Server_SetAimingLocation_Implementation(const FVector& aimLoc)
{
	AnimationCache.CachedAimingLocation = aimLoc;
}

bool UCOVSmoothAnimationComponent::Server_SetActorRotation_Validate(const FRotator& actorRotation)
{
	return true;
}

void UCOVSmoothAnimationComponent::Server_SetActorRotation_Implementation(const FRotator& actorRotation)
{
	AnimationCache.CachedHipRotation = actorRotation;
}

bool UCOVSmoothAnimationComponent::Server_SetPitch_Validate(const float pitch)
{
	return true;
}

void UCOVSmoothAnimationComponent::Server_SetPitch_Implementation(const float pitch)
{
	AnimationCache.CachedPitch = pitch;
}

bool UCOVSmoothAnimationComponent::Server_SetYaw_Validate(const float yaw)
{
	return true;
}

void UCOVSmoothAnimationComponent::Server_SetYaw_Implementation(const float yaw)
{
	AnimationCache.CachedYaw = yaw;
}

bool UCOVSmoothAnimationComponent::Server_SetLocationOfSpecialInterest_Validate(const FVector& loc)
{
	return true;
}

void UCOVSmoothAnimationComponent::Server_SetLocationOfSpecialInterest_Implementation(const FVector& location)
{
	AnimationCache.CachedInterestLocation = location;
}

float UCOVSmoothAnimationComponent::GetYaw() const
{
	if (IS_LOCALLY_CONTROLLED)
	{
		return CalculateYaw();
	}

	return AnimationCache.CachedYaw;
}

float UCOVSmoothAnimationComponent::GetPitch() const
{
	if (IS_LOCALLY_CONTROLLED)
	{
		return CalculatePitch();
	}

	return AnimationCache.CachedPitch;
}

FRotator UCOVSmoothAnimationComponent::GetHipRotation(const float deltaTime) const
{
	if(IS_LOCALLY_CONTROLLED)
	{
		return CalculateHipRotation(deltaTime);
	}

	return AnimationCache.CachedHipRotation;
}

bool UCOVSmoothAnimationComponent::GetShouldBeRotatingHips() const
{
	return _bShouldBeRotatingHips;
}

FVector UCOVSmoothAnimationComponent::GetAimingLocation() const
{
	if (IS_LOCALLY_CONTROLLED)
	{
		return CalculateAimingLocation();
	}

	return AnimationCache.CachedAimingLocation;
}

FVector UCOVSmoothAnimationComponent::CalculateHeadLocation() const
{
	const TWeakObjectPtr<USkeletalMeshComponent> ownerSkeletalMeshComp = Cast<USkeletalMeshComponent>(GetOwner()->GetComponentByClass(USkeletalMeshComponent::StaticClass()));

	if (!ensureMsgf(ownerSkeletalMeshComp.IsValid(), TEXT("Owner (%s) did not have a SkeletalMeshComponent."), *GetNameSafe(GetOwner())))
	{
		return FVector(0, 0, 0);
	}

	const bool socketDoesExist = ownerSkeletalMeshComp->DoesSocketExist("Head");
		
	if (!ensureMsgf(socketDoesExist, TEXT("Owner (%s) did not have a socket named 'Head'."), *GetNameSafe(GetOwner())))
	{
		return FVector(0, 0, 0);
	}

	const FVector headLoc = ownerSkeletalMeshComp->GetSocketLocation("Head");

		return headLoc;

	return FVector(0, 0, 0);
}

void UCOVSmoothAnimationComponent::SetYaw(const float yaw)
{
	AnimationCache.CachedYaw = yaw;
	Server_SetYaw(yaw);
}

void UCOVSmoothAnimationComponent::SetPitch(const float pitch)
{
	AnimationCache.CachedPitch = pitch;
	Server_SetPitch(pitch);
}

void UCOVSmoothAnimationComponent::SetHipRotation(const FRotator& rot)
{
	AnimationCache.CachedHipRotation = rot;
	Server_SetActorRotation(rot);
}

void UCOVSmoothAnimationComponent::SetShouldRotateHips(const float inputAmount)
{
	_bShouldBeRotatingHips = inputAmount != 0.0f;
}

void UCOVSmoothAnimationComponent::SetAimingLocation(const FVector& loc)
{
	AnimationCache.CachedAimingLocation = loc;
	Server_SetAimingLocation(loc);
}

void UCOVSmoothAnimationComponent::SetLocationOfSpecialInterest(const FVector& location)
{
	if (IS_LOCALLY_CONTROLLED)
	{
		AnimationCache.CachedInterestLocation = location;
		Server_SetLocationOfSpecialInterest(location);
	}
}

FVector UCOVSmoothAnimationComponent::GetCameraViewLocation() const
{
	APawn* pawn = Cast<APawn>(GetOwner());
	AController* controller = pawn->GetController();
	APlayerController* playerController = Cast<APlayerController>(controller);
	
	if (!IsValid(playerController))
	{
		return FVector(0, 0, 0);
	}
	
	AActor* playerCameraManagerActor = Cast<AActor>(playerController->PlayerCameraManager);

	//	Ray starting point
	return playerCameraManagerActor->GetActorLocation();
}

float UCOVSmoothAnimationComponent::GetDefaultRunningSpeed() const
{
	return _defaultMaximumRunningSpeed;
}

float UCOVSmoothAnimationComponent::GetDefaultWalkingSpeed() const
{
	return _defaultMaximumWalkingSpeed;
}

FVector UCOVSmoothAnimationComponent::CalculateAimingLocation() const
{
	FHitResult RV_Hit(ForceInit);

	//	Ray starting point
	FVector playerViewWorldLocation = GetCameraViewLocation();
	//	end point target direction
	AController* playerController = Cast<APawn>(GetOwner())->GetController();

	if (!IsValid(playerController))
	{
		return FVector(0, 0, 0);
	}

	FVector controllerForwardVector = Cast<AActor>(playerController)->GetActorForwardVector();
	
	float lineTraceLength = _aimingLocationTraceLength;

	RV_Hit = UE4CodeHelpers::SimpleTraceByChannel
	(
		GetOwner(),
		playerViewWorldLocation + (controllerForwardVector),
		playerViewWorldLocation + (controllerForwardVector * lineTraceLength),
		ECollisionChannel::ECC_Camera,
		FName("AimTrace")
	);

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

FRotator UCOVSmoothAnimationComponent::GetRotationToTargetDirection() const
{
	switch (AimOffsetMode)
	{
		case EAimOffsetCalculationMode::Nothing:
		{
			break;
		}
		case EAimOffsetCalculationMode::ControlRotation:
		{	
			//	We return the rotation of the controller of the character
			FRotator targetRot = Cast<ACharacter>(GetOwner())->GetControlRotation();
			return targetRot;
			break;
		}
		case EAimOffsetCalculationMode::AimLocation:
		{
			//	We return the rotation to the aiming location from the character's head
			FRotator targetRot = UKismetMathLibrary::FindLookAtRotation(CalculateHeadLocation(), CalculateAimingLocation());
			return targetRot;
			break;
		}
	};

	//	Fail
	return FRotator::ZeroRotator;
}

float UCOVSmoothAnimationComponent::CalculateYaw() const
{
	const FRotator targetRot = GetRotationToTargetDirection();
	const FRotator playerRot = Cast<ACharacter>(GetOwner())->GetActorRotation();
	const FRotator deltaRot = UKismetMathLibrary::NormalizedDeltaRotator(playerRot, targetRot);

	//	If hips turn over too much...
	if (FMath::Abs(deltaRot.Yaw) > _angleToStartRotatingHips)
	{
		//	Clamp the yaw to torso max rotations
		float clampedYaw = UKismetMathLibrary::ClampAngle(deltaRot.Yaw - 360.0f, -_upperTorsoMaxRotation, _upperTorsoMaxRotation);
		return -clampedYaw;
	}
	else   //	Need to rotate character towards _aimingVector
	{
		//	Clamp the yaw to torso max rotations
		float clampedYaw = UKismetMathLibrary::ClampAngle(deltaRot.Yaw, -_upperTorsoMaxRotation, _upperTorsoMaxRotation);
		return -clampedYaw;
	}
}

float UCOVSmoothAnimationComponent::CalculatePitch() const
{
	FRotator controlRot = GetRotationToTargetDirection();

	if (controlRot.Pitch > 90)
	{
		return (controlRot.Pitch - 360.0f);
	}
	else
	{
		return controlRot.Pitch;
	}
}

FRotator UCOVSmoothAnimationComponent::CalculateHipRotation(const float deltaTime) const
{
	FRotator goalRotation = GetRotationToTargetDirection();
	FRotator startRotation = AnimationCache.CachedHipRotation;

	float absAngle = FMath::Abs(AnimationCache.CachedYaw);

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

FVector UCOVSmoothAnimationComponent::GetLocationOfSpecialInterest() const
{
	return AnimationCache.CachedInterestLocation;
}

FVector UCOVSmoothAnimationComponent::CalculateHeadLookAtLocation() const
{
	if (bAllowLocationOfInterestHeadRotation)
	{
		return GetLocationOfSpecialInterest();
	}
	else
	{
		return CalculateAimingLocation();
	}
}

void UCOVSmoothAnimationComponent::UpdateHipRotation(float deltaTime)
{
	SetHipRotation(CalculateHipRotation(deltaTime));
}

void UCOVSmoothAnimationComponent::UpdateAimingLocation()
{
	SetAimingLocation(CalculateAimingLocation());
}

void UCOVSmoothAnimationComponent::UpdateAimOffset()
{
	SetYaw(CalculateYaw());
	SetPitch(CalculatePitch());
}

FRotator UCOVSmoothAnimationComponent::CalculateHeadRotation() const
{
	FVector headLoc = CalculateHeadLocation();
	FVector targetLoc = CalculateHeadLookAtLocation();
	FRotator tempRot = UKismetMathLibrary::FindLookAtRotation(headLoc, targetLoc);
	FRotator headRot = FRotator(90.0f, 0, 90.0f);
	headRot += tempRot;

	return headRot;
}

void UCOVSmoothAnimationComponent::Update_AllAnimationVariables_TICK(const float deltaTime)
{
	UpdateAimingLocation();
	UpdateHipRotation(deltaTime);
	UpdateAimOffset();
}

void UCOVSmoothAnimationComponent::DrawDebugs()
{
	if (bDrawDebugs)
	{
		DrawDebugSphere(GetWorld(), AnimationCache.CachedAimingLocation, 8.0f, 6, FColor::Red, false, -1.0f, 0, 2.0f);
	}
}

// Called every frame
void UCOVSmoothAnimationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//	Only client should be updating these values
	if (Cast<APawn>(GetOwner())->IsLocallyControlled())
	{
		//	Creates cached variable values and sends them to the server
		Update_AllAnimationVariables_TICK(DeltaTime);
	}

	DrawDebugs();
}

