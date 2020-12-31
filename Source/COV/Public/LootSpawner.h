// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "LootBase.h"
#include "GameFramework/Actor.h"
#include "LootSpawner.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogLootSpawner, Log, All)

//	Loot definition and probability
USTRUCT(BlueprintType)
struct FLootSpawnDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(Category = "Loot", BlueprintReadWrite, EditAnywhere)
	TSubclassOf<ACollectibleItemBase> LootType;

	//	The higher this value is the higher chance it has to spawn
	UPROPERTY(Category = "Loot", BlueprintReadWrite, EditAnywhere, meta = (ClampMin = 0, ClampMax = 1000))
	int32 SpawnProbabilityWeight = 1;

	//	How many times can this loot spawn. 0 means infinite.
	UPROPERTY(Category = "Loot", BlueprintReadWrite, EditAnywhere, meta = (ClampMin = 0, ClampMax = 1000))
	int32 MaximumNumberOfSpawns = 0;

	//	Transient. ONLY USED WHEN SPAWNING
	int32 TimesAlreadySpawned = 0;
	
	FString ToString() const;

	virtual bool operator==(const FLootSpawnDefinition& Other) const
	{
		return LootType == Other.LootType;
	}
};

USTRUCT(BlueprintType)
struct FLootSpawnAmount
{
	GENERATED_BODY()

public:
	UPROPERTY(Category = "Loot", BlueprintReadWrite, EditAnywhere, meta = (ClampMin = 0, ClampMax = 1000))
	int32 MinimumAmountToSpawn = 0;

	UPROPERTY(Category = "Loot", BlueprintReadWrite, EditAnywhere, meta = (ClampMin = 0, ClampMax = 1000))
	int32 MaximumAmountToSpawn = 0;
};

//	The overall profile of a loot profile to be spawned through a loot spawned
USTRUCT(BlueprintType)
struct FLootProfile
{
	GENERATED_BODY()

public:
	//	How many items of loot will be spawned by this spawner
	UPROPERTY(Category = "Loot", BlueprintReadWrite, EditAnywhere)
	FLootSpawnAmount AmountOfLootToSpawn;
	
	UPROPERTY(Category = "Loot", BlueprintReadWrite, EditAnywhere)
	TArray<FLootSpawnDefinition> LootSpawnDefinitions;

	FString ToString() const;
};

UCLASS()
class COV_API ALootSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALootSpawner();

	UPROPERTY(Category = "Loot", BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn=true))
	FLootProfile LootProfile;

	//	Spawns all the loot given in the parameter. If one loot fails to spawn, return is FALSE
	UFUNCTION(Category = "Loot", BlueprintCallable)
	bool SpawnLoot(FLootProfile LootProfileToSpawn);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
