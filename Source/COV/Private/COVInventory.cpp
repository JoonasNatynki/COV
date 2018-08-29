// Fill out your copyright notice in the Description page of Project Settings.

#include "COVInventory.h"
#include "COVBlueprintFunctionLibrary.h"
#include <Components/ActorComponent.h>
#include <Kismet/KismetSystemLibrary.h>
#include "COVInventoryItem.h"
#include <UnrealNetwork.h>

DEFINE_LOG_CATEGORY(COVInventory)

// Sets default values for this component's properties
UCOVInventory::UCOVInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bReplicates = true;
}

// Called when the game starts
void UCOVInventory::BeginPlay()
{
	Super::BeginPlay();
}

void UCOVInventory::GetLifetimeReplicatedProps(TArray<FLifetimeProperty, FDefaultAllocator>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UCOVInventory, _inventory);
	DOREPLIFETIME(UCOVInventory, _cachedLastAction);
}

void UCOVInventory::OnRep_Inventory(TArray<UCOVInventoryItem*> inv) const
{
	FString enumAsString = EnumToString<EInventoryAction>(FString(TEXT("EInventoryAction")), _cachedLastAction.action.GetValue());

	COV_LOG(COVInventory, Log, TEXT("OnRep = (%s). Action = (%s). Changed item = (%s)"), *UKismetSystemLibrary::GetDisplayName(this), *enumAsString, *UKismetSystemLibrary::GetDisplayName(_cachedLastAction.item));

	OnInventoryChanged.Broadcast(_cachedLastAction);
}

bool UCOVInventory::AddItem_Validate(UCOVInventoryItem* item)
{
	return true;
}

void UCOVInventory::AddItem_Implementation(UCOVInventoryItem* item)
{
	int32 index = _inventory.Find(item);

	if (index != INDEX_NONE)
	{
		COV_LOG(COVInventory, Warning, TEXT("Item (%s) was NOT added into inventory (%s). It already existed in the same inventory."), *UKismetSystemLibrary::GetDisplayName(item), *UKismetSystemLibrary::GetDisplayName(this));
		return;
	}

	_inventory.AddUnique(item);

	COV_LOG(COVInventory, Log, TEXT("Item (%s) added into inventory (%s)."), *UKismetSystemLibrary::GetDisplayName(item), *UKismetSystemLibrary::GetDisplayName(this));

	FInventoryAction* action = new FInventoryAction(item, this, EInventoryAction::Add);
	_cachedLastAction = *action;

	//	Now make the inventory item aware of the inventory it is in
	item->SetOwningInventory(this);

	OnRep_Inventory(_inventory);
}

bool UCOVInventory::RemoveItem_Validate(UCOVInventoryItem* item)
{
	return true;
}

void UCOVInventory::RemoveItem_Implementation(UCOVInventoryItem* item)
{
	int32 indexOfFoundItem;
	_inventory.Find(item, indexOfFoundItem);

	if (indexOfFoundItem == INDEX_NONE)
	{
		AActor* itemActor = item->GetOwner();
		COV_LOG(COVInventory, Warning, TEXT("No item (%s) found in inventory (%s)."), *UKismetSystemLibrary::GetDisplayName(itemActor), *UKismetSystemLibrary::GetDisplayName(this));
		return;
	}

	_inventory.RemoveAt(indexOfFoundItem);
	FInventoryAction* action = new FInventoryAction(item, this, EInventoryAction::Add);
	_cachedLastAction = *action;

	//	Now lets update the item's owning inventory
	item->SetOwningInventory(nullptr);

	OnRep_Inventory(_inventory);
}

// Called every frame
void UCOVInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

