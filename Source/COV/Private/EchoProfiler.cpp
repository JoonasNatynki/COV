// Fill out your copyright notice in the Description page of Project Settings.

#include "EchoProfiler.h"
#include "COVBlueprintFunctionLibrary.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include <Map.h>
#include <Kismet/KismetSystemLibrary.h>
#include <CollisionQueryParams.h>

// Sets default values for this component's properties
UEchoProfiler::UEchoProfiler()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	IcoSphereMeshComponent = CreateDefaultSubobject<UIcoSphereComponent>(TEXT("Icosphere mesh component"));
}

// Called when the game starts
void UEchoProfiler::BeginPlay()
{
	Super::BeginPlay();
	IcoSphereMeshComponent->GenerateIcoSphere(IcoSphereSubdivisions);
}

void UEchoProfiler::GenerateEchoProfile(FVector sourceLocation)
{
	EchoSpaceSizeProfile = 0;
	EchoCoverageProfile = 0;
	TArray<FVector> meshVertices = GetMesh();
	AActor* ownerActor = GetOwner();
	FVector ownerLocation = ownerActor->GetActorLocation();
	//FVector startPos;
	FVector endPos;
	ECollisionChannel collisionChannel = ECollisionChannel::ECC_Visibility;
	FName traceTag = FName("EchoTrace");
	int32 verticeCount = meshVertices.Num();

	for (auto & vertex : meshVertices)
	{
		endPos = ownerLocation + (vertex * EchoMeasureMaximumDistance);
		FHitResult hit = UCOVBlueprintFunctionLibrary::SimpleTraceByChannel
		(
			ownerActor,
			sourceLocation,
			endPos,
			collisionChannel,
			traceTag
		);

		//	Here we calculate how we add this ray trace into the echo float profile
		float tempResult = (hit.Distance) / (10.0f *verticeCount);
		FVector rayNormalized = (endPos - sourceLocation);
		rayNormalized.Normalize();
		float dotFloat = FVector::DotProduct(hit.ImpactNormal, rayNormalized);
		tempResult = tempResult * (dotFloat * dotFloat);
		EchoSpaceSizeProfile += tempResult;

		//	Add into coverage profile
		hit.bBlockingHit ? EchoCoverageProfile += 1.0f : EchoCoverageProfile;
	}

	//	Calculate the wall coverage ratio 0 = open space and 1 = completely closed space
	EchoCoverageProfile -= (float)(verticeCount / 2);
	if (EchoCoverageProfile < 0)
	{
		EchoCoverageProfile = 0;
	}
	else
	{
		EchoCoverageProfile = EchoCoverageProfile / (verticeCount / 2);
	}
}

void UEchoProfiler::DrawDebugs() const 
{
	int32 showEchoDebugVolume = CVarShowEchoProfilerDebugSphere.GetValueOnGameThread();

	if (showEchoDebugVolume == 1)
	{
		FVector ownerLocation = GetOwner()->GetActorLocation();
		UKismetSystemLibrary::DrawDebugSphere(GetOwner(), ownerLocation, EchoSpaceSizeProfile * 40, 12, FLinearColor::Red, 0.0f, 4.0f);
		UKismetSystemLibrary::DrawDebugString(GetOwner(), FVector(0,0,80.0f), FString::SanitizeFloat(EchoSpaceSizeProfile), GetOwner(), FLinearColor::Red, 0.0f);
	}
}

// Called every frame
void UEchoProfiler::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	DrawDebugs();
	// ...
}

