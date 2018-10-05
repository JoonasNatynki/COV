// Fill out your copyright notice in the Description page of Project Settings.

#include "EchoProfiler.h"
#include "COVBlueprintFunctionLibrary.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include <Map.h>

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

TriangleList UEchoProfiler::Subdivide(VertexList& vertices,
	TriangleList triangles)
{
	Lookup lookup;
	TriangleList result;

	for (auto&& each : triangles)
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
		triangles = Subdivide(vertices, triangles);
	}
	IndexedMesh temp;
	temp.Key = vertices;
	temp.Value = triangles;

	UE_LOG(LogTemp, Log, TEXT("Icosphere generated with subdivisions (%d)."), IcoSphereSubdivisions);
	return temp;
}

void UEchoProfiler::GenerateEchoProfile(FVector sourceLocation)
{
	EchoFloatProfile = 0;

	FVector startPos;
	FVector endPos;

	for (auto & vertex : GetMesh())
	{
		startPos = GetOwner()->GetActorLocation();
		endPos = GetOwner()->GetActorLocation() + (vertex * 10000.0f);
		FHitResult hit = UCOVBlueprintFunctionLibrary::SimpleTraceByChannel(GetOwner(), startPos, endPos, ECollisionChannel::ECC_Visibility);

		float tempResult = hit.Distance * hit.Distance;
		FVector rayNormalized = (endPos - startPos);
		rayNormalized.Normalize();
		float dotFloat = FVector::DotProduct(hit.ImpactNormal, rayNormalized);
		tempResult = tempResult * dotFloat;
		EchoFloatProfile -= tempResult;
	}

	EchoFloatProfile = EchoFloatProfile / 1000000.0f;
}

// Called every frame
void UEchoProfiler::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

