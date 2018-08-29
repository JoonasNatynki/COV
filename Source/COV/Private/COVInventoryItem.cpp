// Fill out your copyright notice in the Description page of Project Settings.

#include "COVInventoryItem.h"
#include <UnrealNetwork.h>
#include "COVInventory.h"


// Sets default values for this component's properties
UCOVInventoryItem::UCOVInventoryItem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bReplicates = true;
}

// Called when the game starts
void UCOVInventoryItem::BeginPlay()
{
	Super::BeginPlay();
}

void UCOVInventoryItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty, FDefaultAllocator>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UCOVInventoryItem, _owningInventory);
}

UCOVInventory* UCOVInventoryItem::GetOwningInventory() const
{
	return _owningInventory;
}

void UCOVInventoryItem::SetOwningInventory(UCOVInventory* inventory)
{
	_owningInventory = inventory;
	//	TODO: When a new inventory is set, do the item hiding and stuff needed to carry it around in the inventory
}

// Called every frame
void UCOVInventoryItem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

