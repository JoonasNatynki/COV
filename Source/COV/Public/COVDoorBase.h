// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "COVDoorBase.generated.h"

UENUM(BlueprintType)
enum EDoorType
{
	SingleDoor,
	DoubleDoor,
	Iris
};

UCLASS()
class COV_API ACOVDoorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACOVDoorBase();

	UPROPERTY(Category = "Door", BlueprintReadWrite, EditDefaultsOnly)
		TEnumAsByte<EDoorType> DoorType;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SpawnDoorComponents_Internal();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
