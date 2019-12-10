// Fill out your copyright notice in the Description page of Project Settings.

#include "COVEchoProfiler.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include <Map.h>
#include <Kismet/KismetSystemLibrary.h>
#include <CollisionQueryParams.h>
#include "UE4Helpers.h"

DEFINE_LOG_CATEGORY(LogEchoProfile)

static TAutoConsoleVariable<int32> CVarShowEchoProfilerDebugSphere(TEXT("COV.ShowEchoProfilerDebugSphere"),
	1,
	TEXT("Show the aproximate size of the echo profile as volume."));

// Sets default values for this component's properties
UCOVEchoProfiler::UCOVEchoProfiler()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	IcoSphereMeshComponent = CreateDefaultSubobject<UIcoSphereComponent>(TEXT("Icosphere mesh component"));
}

// Called when the game starts
void UCOVEchoProfiler::BeginPlay()
{
	Super::BeginPlay();
	IcoSphereMeshComponent->GenerateIcoSphere(IcoSphereSubdivisions);
}

void UCOVEchoProfiler::SetEchoProfileDebugsEnabled(bool bOn)
{
	SetComponentTickEnabled(bOn);
	UE_LOG(LogEchoProfile, Log, TEXT("EchoProfile tick is set to (%s)"), (bOn)?(TEXT("TRUE")):(TEXT("FALSE")));
}

void UCOVEchoProfiler::GenerateEchoProfile(FVector sourceLocation)
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
		FHitResult hit = UE4CodeHelpers::SimpleTraceByChannel
		(
			GetOwner(),
			sourceLocation,
			endPos,
			collisionChannel,
			traceTag
		);

		//	Here we calculate how we add this ray trace into the echo float profile
		float rayHitLocationBaseAreaOnASphere = (1.0f / 3.0f)*(((4.0f * 3.15826f)*FMath::Pow(hit.Distance, 2))/verticeCount);
		float aproximateVolumeOfRay = (rayHitLocationBaseAreaOnASphere)*hit.Distance;
		FVector rayNormalized = (endPos - sourceLocation);
		rayNormalized.Normalize();
		float dotFloat = FVector::DotProduct(hit.ImpactNormal, rayNormalized);
		aproximateVolumeOfRay = aproximateVolumeOfRay * (dotFloat * dotFloat);
		EchoSpaceSizeProfile += (aproximateVolumeOfRay)/100000000.0f;

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

void UCOVEchoProfiler::DrawDebugs() const 
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
void UCOVEchoProfiler::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	DrawDebugs();
}

