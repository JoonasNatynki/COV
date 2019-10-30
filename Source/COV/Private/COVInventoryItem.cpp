// Fill out your copyright notice in the Description page of Project Settings.

#include "COVInventoryItem.h"
#include <UnrealNetwork.h>
#include "COVInventory.h"
#include <Kismet/KismetSystemLibrary.h>
#include <GameFramework/Actor.h>
#include <Components/PrimitiveComponent.h>
#include "UE4Helpers.h"

DEFINE_LOG_CATEGORY(COVInventoryItem)

// Sets default values for this component's properties
UCOVInventoryItem::UCOVInventoryItem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	bReplicates = true;
}

// Called when the game starts
void UCOVInventoryItem::BeginPlay()
{
	Super::BeginPlay();

	GenerateNewGUID();
}

void UCOVInventoryItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty, FDefaultAllocator>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UCOVInventoryItem, OwningInventory);
	DOREPLIFETIME(UCOVInventoryItem, UniqueItemID);
}

const FGuid& UCOVInventoryItem::GetUniqueItemID()
{
	return UniqueItemID;
}

TSubclassOf<class AActor> UCOVInventoryItem::GetCorrespondingItemActorType()
{
	return CorrespondingItemActorType;
}

void UCOVInventoryItem::Initialize(const UCOVInventoryItem* copyItem)
{
	DisplayName = copyItem->DisplayName;
	UniqueItemID = copyItem->UniqueItemID;
	SetOwningInventory(copyItem->OwningInventory);
}

void UCOVInventoryItem::GenerateNewGUID()
{
	if (GetOwner()->HasAuthority())
	{
		//	Make a guid for the item that will persist
		UniqueItemID = FGuid::NewGuid();
		COV_LOG(COVInventoryItem, Log, TEXT("New GUID (%s) generated for (%s)."), *UniqueItemID.ToString(), *GetNameSafe(GetOwner()));
	}
}

UCOVInventory* UCOVInventoryItem::GetOwningInventory() const
{
	return OwningInventory;
}

void UCOVInventoryItem::SetOwningInventory(UCOVInventory* inventory)
{	
	if (IsValid(inventory))
	{
		OwningInventory = inventory;
	}
	else
	{
		
	}
}

// Called every frame
void UCOVInventoryItem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

