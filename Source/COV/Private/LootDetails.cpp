// Fill out your copyright notice in the Description page of Project Settings.


#include "LootDetails.h"

// Sets default values for this component's properties
ULootDetails::ULootDetails()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULootDetails::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULootDetails::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

