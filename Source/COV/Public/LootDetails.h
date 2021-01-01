// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LootDetails.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COV_API ULootDetails : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULootDetails();

	//	The rarity of the loot. Higher values mean the loot is more rare. 2.0 is twice as rare as 1.0. This value will modify the loot spawn probability weight of FLootSpawnDefinition. See: FLootSpawnDefinition::SpawnProbabilityWeight
	UPROPERTY(Category = "Loot details", EditDefaultsOnly, meta = (ClampMin = 1.0f, ClampMax = 100.0f))
	float Rarity = 1.0f;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
