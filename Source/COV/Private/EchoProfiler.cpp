// Fill out your copyright notice in the Description page of Project Settings.

#include "EchoProfiler.h"
#include "COVBlueprintFunctionLibrary.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include <Map.h>
#include <Kismet/KismetSystemLibrary.h>

// Sets default values for this component's properties
UEchoProfiler::UEchoProfiler()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UEchoProfiler::BeginPlay()
{
	Super::BeginPlay();

	IndexedMesh test = GenerateIcoSphere(IcoSphereSubdivisions);
	mesh = test.Key;
}

FIndex UEchoProfiler::GetVertexForEdge(Lookup& lookup,
	VertexList& vertices, FIndex first, FIndex second)
{
	TPair<FIndex, FIndex> key(first, second);
	if (key.Key > key.Value)
		std::swap(key.Key, key.Value);

	Lookup temp;
	temp.Emplace(key, vertices.Num());
	auto inserted = lookup.Add(key, vertices.Num());
	if (true)
	{
		auto& edge0 = vertices[first];
		auto& edge1 = vertices[second];
		auto point = (edge0 + edge1);
		point.Normalize();
		vertices.Push(point);
	}

	return inserted;
}

TriangleList UEchoProfiler::SubdivideIcoSphereMesh(VertexList& vertices,
	TriangleList triangles)
{
	Lookup lookup;
	TriangleList result;

	for (auto & each : triangles)
	{
		TArray<FIndex> mid;
		for (int edge = 0; edge < 3; ++edge)
		{
			mid.Add(GetVertexForEdge(lookup, vertices,
				each.vertex[edge], each.vertex[(edge + 1) % 3]));
		}

		result.Push({ each.vertex[0], mid[0], mid[2] });
		result.Push({ each.vertex[1], mid[1], mid[0] });
		result.Push({ each.vertex[2], mid[2], mid[1] });
		result.Push({ mid[0], mid[1], mid[2] });
	}

	return result;
}

IndexedMesh UEchoProfiler::GenerateIcoSphere(int subdivisions)
{
	for (int i = 0; i < subdivisions; ++i)
	{
		triangles = SubdivideIcoSphereMesh(vertices, triangles);
	}
	IndexedMesh temp;
	temp.Key = vertices;
	temp.Value = triangles;

	COV_LOG(LogTemp, Log, TEXT("Icosphere generated with subdivisions (%d)."), IcoSphereSubdivisions);
	return temp;
}

void UEchoProfiler::GenerateEchoProfile(FVector sourceLocation)
{
	EchoSpaceSizeProfile = 0;
	EchoCoverageProfile = 0;

	//FVector startPos;
	FVector endPos;

	for (auto & vertex : GetMesh())
	{
		//startPos = GetOwner()->GetActorLocation();
		endPos = GetOwner()->GetActorLocation() + (vertex * EchoMeasureMaximumDistance);
		FHitResult hit = UCOVBlueprintFunctionLibrary::SimpleTraceByChannel
		(
			GetOwner(),
			sourceLocation,
			endPos,
			ECollisionChannel::ECC_Visibility,
			FName("EchoTrace")
		);

		//	Here we calculate how we add this ray trace into the echo float profile
		float tempResult = (hit.Distance) / (10.0f * GetMesh().Num());
		FVector rayNormalized = (endPos - sourceLocation);
		rayNormalized.Normalize();
		float dotFloat = FVector::DotProduct(hit.ImpactNormal, rayNormalized);
		tempResult = tempResult * (dotFloat * dotFloat);
		EchoSpaceSizeProfile += tempResult;

		//	Add into coverage profile
		hit.bBlockingHit ? EchoCoverageProfile += 1.0f : EchoCoverageProfile;
	}

	//	Calculate the wall coverage ratio 0 = open space and 1 = completely closed space
	EchoCoverageProfile -= (float)(GetMesh().Num() / 2);
	if (EchoCoverageProfile < 0)
	{
		EchoCoverageProfile = 0;
	}
	else
	{
		EchoCoverageProfile = EchoCoverageProfile / (GetMesh().Num() / 2);
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

