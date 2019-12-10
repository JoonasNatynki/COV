// Fill out your copyright notice in the Description page of Project Settings.

#include "COVDoorBase.h"

// Sets default values
ACOVDoorBase::ACOVDoorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SpawnDoorComponents_Internal();
}

// Called when the game starts or when spawned
void ACOVDoorBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACOVDoorBase::SpawnDoorComponents_Internal()
{
	switch (DoorType)
	{
		case EDoorType::SingleDoor:
		{
			break;
		}
		case EDoorType::DoubleDoor:
		{
			break;
		}
		case EDoorType::Iris:
		{
			break;
		}
	}
}

// Called every frame
void ACOVDoorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

