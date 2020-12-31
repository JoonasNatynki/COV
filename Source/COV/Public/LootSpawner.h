// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LootSpawner.generated.h"

//	Loot definition and probability
USTRUCT(BlueprintType)
struct FLootSpawnDefinition
{
	GENERATED_BODY()

public:	
};

//	The overall profile of a loot profile to be spawned through a loot spawned
USTRUCT(BlueprintType)
struct FLootProfile
{
	GENERATED_BODY()

public:
};

UCLASS()
class COV_API ALootSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALootSpawner();

	UPROPERTY(Category = "Loot", BlueprintReadWrite, VisibleAnywhere, meta = (ClampMin = 0, ClampMax = 100, ExposeOnSpawn = true))
	int32 AmountToSpawn = 0;

	UPROPERTY(Category = "Loot", BlueprintReadWrite, VisibleAnywhere, meta = (ExposeOnSpawn=true))
	FLootProfile LootProfile;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
