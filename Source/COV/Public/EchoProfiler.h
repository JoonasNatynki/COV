// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <vector>
#include <NoExportTypes.h>
#include "IcoSphereComponent.h"
#include "EchoProfiler.generated.h"

class UIcoSphereComponent;

static TAutoConsoleVariable<int32> CVarShowEchoProfilerDebugSphere(TEXT("COV.ShowEchoProfilerDebugSphere"),
	0,
	TEXT("Show the aproximate size of the echo profile as volume."));

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class COV_API UEchoProfiler : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		int32 IcoSphereSubdivisions = 2;
	UPROPERTY(EditAnywhere)
		float EchoMeasureMaximumDistance = 10000.0f;
	UPROPERTY(VisibleAnywhere)
		float EchoSpaceSizeProfile;
	UPROPERTY(VisibleAnywhere)
		float EchoCoverageProfile;

	TWeakObjectPtr<UIcoSphereComponent> IcoSphereMeshComponent;

public:

	// Sets default values for this component's properties
	UEchoProfiler();

	//	Getter for the icosphere mesh
	UFUNCTION(BlueprintCallable)
		TArray<FVector>& GetMesh() { return IcoSphereMeshComponent->GetMesh(); };
	UFUNCTION(BlueprintCallable)
		void GenerateEchoProfile(FVector sourceLocation);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		float GetEchoFloatProfile() const { return EchoSpaceSizeProfile; };
	UFUNCTION(BlueprintCallable, BlueprintPure)
		float GetEchoCoverageProfile() const { return EchoCoverageProfile; };

	FIndex GetVertexForEdge(Lookup& lookup, VertexList& vertices, FIndex first, FIndex second);
	TriangleList SubdivideIcoSphereMesh(VertexList& vertices, TriangleList triangles);
	IndexedMesh GenerateIcoSphere(int subdivisions);
	void DrawDebugs() const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;	
};
