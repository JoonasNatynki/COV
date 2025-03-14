// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "COVSmoothAnimationComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(COVSmoothAnimation, Log, All)

USTRUCT(BlueprintType) struct FAnimationCache
{
	GENERATED_BODY()
public:
	UPROPERTY()
		float CachedYaw;

	UPROPERTY()
		float CachedPitch;

	UPROPERTY()
		FVector CachedAimingLocation;

	UPROPERTY()
		FRotator CachedHipRotation;

	UPROPERTY()
		FVector CachedInterestLocation;
};

UENUM(BlueprintType) enum EAimOffsetCalculationMode
{
	Nothing				UMETA(DisplayName = "Nothing"),
	ControlRotation		UMETA(DisplayName = "Control rotation"),
	AimLocation			UMETA(DisplayName = "Aim location"),
	InterestLocation	UMETA(DisplayName = "Interest location")
};


UCLASS( ClassGroup=(COV), meta=(BlueprintSpawnableComponent), Blueprintable, Config=Game)
class COV_API UCOVSmoothAnimationComponent : public UActorComponent
{
	GENERATED_BODY()

	// Sets default values for this component's properties
	UCOVSmoothAnimationComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty, FDefaultAllocator>& OutLifetimeProps) const override;

	UPROPERTY(Replicated)
		FAnimationCache AnimationCache;

private:
	//	VARIABLES ###########################################################################################
	UPROPERTY(Replicated, VisibleAnywhere, Transient)
		//	Tells if the character is receiving player movement input to rotate hips towards aiming location
		bool _bShouldBeRotatingHips;

	UPROPERTY(Category = "Animation", EditDefaultsOnly)
		//	Angle at which the character will start rotating towards aiming location
		float _angleToStartRotatingHips = 90;
	UPROPERTY(Category = "Animation", EditDefaultsOnly)
		//	Angle at which the character will start rotating towards aiming location
		float _upperTorsoMaxRotation = 140.0f;
	UPROPERTY(Category = "Movement", EditDefaultsOnly)
		//	How fast the player rotates to movement vector when receiving movement input?
		float _movementInputRotationSpeed = 5.0f;
	UPROPERTY(Category = "Animation", EditDefaultsOnly)
		//	The maximum distance that we use to determine where the player is looking at.
		float _aimingLocationTraceLength = 10000.0f;
	UPROPERTY(Category = "Animation", EditDefaultsOnly)
		//	Do we allow the head to also orient to look at locations of interest?
		bool bAllowLocationOfInterestHeadRotation;

	UPROPERTY(Category = "Animation", EditDefaultsOnly)
		TEnumAsByte<EAimOffsetCalculationMode> AimOffsetMode = EAimOffsetCalculationMode::ControlRotation;

	UPROPERTY(Category = "Movement", EditDefaultsOnly, Config)
		//	The default maximum speed the character will be running at without sprinting
		float _defaultMaximumRunningSpeed = 600.0f;
	UPROPERTY(Category = "Movement", EditDefaultsOnly)
		//	The default maximum speed the character will be running at without sprinting
		float _defaultMaximumWalkingSpeed = 200.0f;
	//	/VARIABLES ###########################################################################################

	//	SERVER ONLY FUNCTIONS	#############################################################################
	UFUNCTION(Category = "Server", Server, Unreliable, WithValidation, BlueprintAuthorityOnly)
		//	Server version of the UpdateYawAndPitch function
		void Server_SetAimingLocation(const FVector& aimingLocation);
	UFUNCTION(Category = "Server", Server, Unreliable, WithValidation, BlueprintAuthorityOnly)
		//	Server version of the UpdateYawAndPitch function
		void Server_SetPitch(const float pitch);
	UFUNCTION(Category = "Server", Server, Unreliable, WithValidation, BlueprintAuthorityOnly)
		//	Server version of the UpdateYawAndPitch function
		void Server_SetYaw(const float yaw);
	UFUNCTION(Category = "Server", Server, Unreliable, WithValidation, BlueprintAuthorityOnly)
		//	Server version of the UpdateYawAndPitch function
		void Server_SetActorRotation(const FRotator& actorRotation);
	UFUNCTION(Category = "Server", Server, Reliable, WithValidation, BlueprintAuthorityOnly)
		//	Server version of the location of special interest setter
		void Server_SetLocationOfSpecialInterest(const FVector& location);
	//	####################################################################################################


public:
	//	GETTERS ############################################################################################
	UFUNCTION(Category = "Smooth Animation", BlueprintCallable, BlueprintPure)
		//	Get the yaw value of the aim offset
		float GetYaw() const;
	UFUNCTION(Category = "Smooth Animation", BlueprintCallable, BlueprintPure)
		//	Get the pitch value of the aim offset
		float GetPitch() const;
	UFUNCTION(Category = "Smooth Animation", BlueprintCallable, BlueprintPure)
		//	Get the amount that the hips should be rotated at
		FRotator GetHipRotation(const float deltaTime) const;
	UFUNCTION(Category = "Smooth Animation", BlueprintCallable, BlueprintPure)
		//	Get if the hips should be rotating this frame
		bool GetShouldBeRotatingHips() const;
	UFUNCTION(Category = "Smooth Animation", BlueprintCallable, BlueprintPure)
		//	Get the location where the player is aiming at. This is done by ray casting from the camera straight forward
		FVector GetAimingLocation() const;
	UFUNCTION(Category = "Smooth Animation", BlueprintCallable, BlueprintPure)
		//	Gets the actual frame accurate location of the player camera view
		FVector GetCameraViewLocation() const;
	UFUNCTION(Category = "Smooth Animation", BlueprintCallable, BlueprintPure)
		//	Get the default maximum running speed
		float GetDefaultRunningSpeed() const;
	UFUNCTION(Category = "Smooth Animation", BlueprintCallable, BlueprintPure)
		//	Get the default maximum walking speed
		float GetDefaultWalkingSpeed() const;
	UFUNCTION(Category = "Smooth Animation", BlueprintCallable, BlueprintPure)
		//	Get a location of special interest. This is the location where the head will be looking at if it is allowed to look at special interest locations. Return 0,0,0 if no location was set
		FVector GetLocationOfSpecialInterest() const;
		//	Gets the target rotation that the yaw and pitch try to aim at.
		FRotator GetRotationToTargetDirection() const;
	//	/GETTERS ############################################################################################

	//	SETTERS ############################################################################################
	UFUNCTION(Category = "Smooth Animation", BlueprintCallable)
		void SetYaw(const float yaw);
	UFUNCTION(Category = "Smooth Animation", BlueprintCallable)
		void SetPitch(const float pitch);
	UFUNCTION(Category = "Smooth Animation", BlueprintCallable)
		void SetHipRotation(const FRotator& rot);
	UFUNCTION(Category = "Smooth Animation", BlueprintCallable)
		void SetShouldRotateHips(const float inputAmount);
	UFUNCTION(Category = "Smooth Animation", BlueprintCallable)
		void SetAimingLocation(const FVector& loc);
	UFUNCTION(Category = "Movement", BlueprintCallable)
		void SetLocationOfSpecialInterest(const FVector& location);
	//	/SETTERS ############################################################################################
	
	//	CALCULATORS ########################################################################################
	UFUNCTION(Category = "COVCharacterAnimationVariables", BlueprintCallable)
		//	Calculates a new yaw value at this frame
		float CalculateYaw() const;
	UFUNCTION(Category = "COVCharacterAnimationVariables", BlueprintCallable)
		//	Calculates a new pitch value at this frame
		float CalculatePitch() const;
	UFUNCTION(Category = "COVCharacterAnimationVariables", BlueprintCallable)
		//	Calculates a new aiming location at this frame
		FVector CalculateAimingLocation() const;
	UFUNCTION(Category = "Smooth Animation", BlueprintCallable, BlueprintPure)
		//	Gets the "head" socket's location. If nothing is found, return 0,0,0 vector
		FVector CalculateHeadLocation() const;
	UFUNCTION(Category = "COVCharacterAnimationVariables", BlueprintCallable)
		//	Calculates a new hip rotation at this frame
		FRotator CalculateHipRotation(const float deltaTime) const;
	UFUNCTION(Category = "COVCharacterAnimationVariables", BlueprintCallable)
		//	Calculates a new head rotation at this frame. The head is looking at either the aiming location or another one specifiec independently by SetInterestLocation()
		FRotator CalculateHeadRotation() const;
	UFUNCTION(Category = "Smooth Animation", BlueprintCallable, BlueprintPure)
		//	This is the location that is used to determine where the head is looking at
		FVector CalculateHeadLookAtLocation() const;
	//	/CALCULATORS ########################################################################################

	void UpdateHipRotation(float deltaTime);
	void UpdateAimingLocation();
	void UpdateAimOffset();

	UFUNCTION(Category = "COVCharacterAnimationVariables", BlueprintCallable)
		//	This function updates all of the necessary variables needed to animate the character. Put this in your character's tick and make sure it only runs on a local client.
		void Update_AllAnimationVariables_TICK(const float deltaTime);

	UFUNCTION(Exec)
		void EnableSmoothAnimationDebugs(bool bEnabled) { bDrawDebugs = bEnabled; };
	bool bDrawDebugs = false;
	void DrawDebugs();

};
