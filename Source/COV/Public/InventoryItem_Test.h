// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventoryItem_Test.generated.h"

UCLASS()
class COV_API AInventoryItem_Test : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInventoryItem_Test();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (InventoryItemData))
		int32 TestInteger = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (InventoryItemData))
		float TestFloat = 0.0f;
};
