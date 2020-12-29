// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "CollectibleItemBase.h"
#include "GameFramework/Actor.h"
#include "CollectibleBase.generated.h"

UCLASS()
class COV_API ACollectibleBase : public ACollectibleItemBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectibleBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(Category = "Collectible", BlueprintReadWrite, EditDefaultsOnly)
	UStaticMeshComponent* DefaultCollectibleVisualMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
