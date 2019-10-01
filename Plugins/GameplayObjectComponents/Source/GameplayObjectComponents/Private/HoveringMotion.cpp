// Fill out your copyright notice in the Description page of Project Settings.


#include "HoveringMotion.h"
#include <Components/MeshComponent.h>
#include <MessageLog.h>
#include <UObjectToken.h>
#include <Kismet/KismetMathLibrary.h>
#include <Kismet/GameplayStatics.h>

DEFINE_LOG_CATEGORY(LogHoveringMotion)

// Sets default values for this component's properties
UHoveringMotion::UHoveringMotion()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}

// Called when the game starts
void UHoveringMotion::BeginPlay()
{
	Super::BeginPlay();

	//	If the animated mesh is not set, default to hovering the root component if it is a mesh itself
	if (!IsValid(ComponentToHover))
	{
		UE_LOG(LogHoveringMotion, Log, TEXT("No mesh set to hover. Defaulting to hovering the root component's position."));

		check(Cast<USceneComponent>(GetOwner()->GetRootComponent()));

		//	The root component is a mesh component. Set that as the hovering component
		SetHoveringComponent(GetOwner()->GetRootComponent());

		bIsRotatingRootComponent = true;
		bool bShouldAnimate = false;

		UE_LOG(LogHoveringMotion, Warning, TEXT("HoverMotionComponent is set to rotate the owner's root component. reminder that this is expensive when movement is replicated over the network ."));

		AActor* owner = GetOwner();

		if (owner->GetIsReplicated() && owner->bReplicateMovement)
		{		
			//	The actor is set to replicate its movement over the network. Only authority should now animate the root motion as it then replicates its movement to the listening clients
			bShouldAnimate = (owner->HasAuthority() && !bAnimateOnlyLocally) || (!owner->HasAuthority() && bAnimateOnlyLocally);
		}
		else
		{
			//	Just hover on both client and server independently
			bShouldAnimate = true;
		}

		SetAnimating(bShouldAnimate);
	}
}

void UHoveringMotion::SetHoveringComponent(USceneComponent* componentToHover)
{
	if (IsValid(componentToHover))
	{
		ComponentToHover = componentToHover;
		UE_LOG(LogHoveringMotion, Log, TEXT("Mesh to rotate set to (%s)"), *GetNameSafe(ComponentToHover));
	}
	else
	{
		UE_LOG(LogHoveringMotion, Error, TEXT("Could not set hovering mesh. The mesh was invalid."));
		FMessageLog("PIE").Error(FText::FromString("Could not set hovering mesh. The mesh was invalid."))->AddToken(FUObjectToken::Create(GetOwner()));
	}
}

void UHoveringMotion::SetAnimating(bool bShouldAnimate)
{
	bIsAnimating = bShouldAnimate;
	PrimaryComponentTick.SetTickFunctionEnable(bShouldAnimate);

	if (bShouldAnimate && bRandomizeInitialRotation)
	{
		FRotator randRot = UKismetMathLibrary::RandomRotator();
		ComponentToHover->SetRelativeRotation(randRot);
	}

	UE_LOG(LogHoveringMotion, Log, TEXT("%s animate (%s)."), *GetNameSafe(ComponentToHover), (bShouldAnimate)?(TEXT("Beginning")):(TEXT("Stopping")));
}

void UHoveringMotion::UpdateMeshTransform(float deltaTime)
{
	if (bRotate)
	{
		FRotator toRotateWith = FRotator(XAxisRotationSpeed, YAxisRotationSpeed, ZAxisRotationSpeed);
		ComponentToHover->AddLocalRotation(toRotateWith);
	}

	if (bHoverMovement)
	{
		float sinValue = (UKismetMathLibrary::Sin(UGameplayStatics::GetRealTimeSeconds(this)) * HoverRepeatFrequency);

		//	If we are rotating the root mesh, record the offset so we can calculate the original location of the mesh if it had not hovered at all
		if (bIsRotatingRootComponent)
		{
			FVector offset = FVector(HoverXMovementDistance, HoverYMovementDistance, HoverZMovementDistance) * deltaTime * sinValue;
			GetOwner()->SetActorLocation(GetOwner()->GetActorLocation() + offset);
		}
		else
		{
			ComponentToHover->SetRelativeLocation(FVector(HoverXMovementDistance * sinValue, HoverYMovementDistance * sinValue, HoverZMovementDistance * sinValue), false);
		}
	}
}

// Called every frame
void UHoveringMotion::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//	Update the mesh transform
	UpdateMeshTransform(DeltaTime);
}