// Fill out your copyright notice in the Description page of Project Settings.

#include "COVInventory.h"
#include "COVBlueprintFunctionLibrary.h"
#include <Components/ActorComponent.h>
#include <Kismet/KismetSystemLibrary.h>
#include <GameFramework/Actor.h>
#include "COVInventoryItem.h"
#include <UnrealNetwork.h>
#include <Engine/EngineTypes.h>
#include <Components/PrimitiveComponent.h>
#include <MessageLog.h>
#include <UObjectToken.h>

DEFINE_LOG_CATEGORY(COVInventory)
#define LOCTEXT_NAMESPACE "COVInventory"

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

	DOREPLIFETIME(UCOVInventory, Inventory);
	DOREPLIFETIME(UCOVInventory, _cachedLastAction);
}

void UCOVInventory::OnRep_Inventory(TArray<UCOVInventoryItem*> inv) const
{
	FString enumAsString = EnumToString<EInventoryAction>(FString(TEXT("EInventoryAction")), _cachedLastAction.action.GetValue());

	if (GetOwner()->Role != ROLE_Authority)
	{
		COV_LOG(COVInventory, Log, TEXT("OnRep = (%s). Action = (%s). Changed item ID = (%s)"), *GetNameSafe(this), *enumAsString, *_cachedLastAction.UniqueItemGUID.ToString());
	}

	OnInventoryChanged.Broadcast(_cachedLastAction);
	_cachedLastAction;
}

bool UCOVInventory::AddItem_Validate(UCOVInventoryItem* item)
{
	return true;
}

void UCOVInventory::AddItem_Implementation(UCOVInventoryItem* item)
{
	if (!IsValid(item))
	{
		COV_LOG(COVInventory, Error, TEXT("Item that was not valid added to inventory."));
		FMessageLog("COVInventory").Error(FText::FromString("Item being added to inventory was invalid."))->AddToken(FUObjectToken::Create(this));

		return;
	}

	UCOVInventoryItem* foundItem = nullptr;
	
	if (Inventory.Num() > 0)
	{
		foundItem = *Inventory.FindByPredicate([&](UCOVInventoryItem* anotherItem)
		{
			return item->GetUniqueItemID() == anotherItem->GetUniqueItemID();
		});
	}

	if (foundItem)
	{
		COV_LOG(COVInventory, Warning, TEXT("Item (%s) was NOT added into inventory (%s). It already existed in the same inventory."), *GetNameSafe(item), *GetNameSafe(this));

		return;
	}

	COV_LOG(COVInventory, Log, TEXT("Item (%s) being added to inventory (%s)."), *item->GetItemDisplayName(), *GetNameSafe(this));

	Inventory.AddUnique(item);

	//	Update the cached action
	FInventoryAction action(item->GetUniqueItemID(), this, EInventoryAction::Add);
	_cachedLastAction = action;
	//	Now make the inventory item aware of the inventory it is in
	item->SetOwningInventory(this);
	OnRep_Inventory(Inventory);
}

bool UCOVInventory::RemoveItem_Validate(UCOVInventoryItem* item)
{
	return true;
}

void UCOVInventory::RemoveItem_Implementation(UCOVInventoryItem* item)
{
	int32 indexOfFoundItem;
	Inventory.Find(item, indexOfFoundItem);

	if (indexOfFoundItem == INDEX_NONE)
	{
		AActor* itemActor = item->GetOwner();
		COV_LOG(COVInventory, Warning, TEXT("No item (%s) found in inventory (%s)."), *GetNameSafe(itemActor), *GetNameSafe(this));
		return;
	}

	Inventory.RemoveAt(indexOfFoundItem);

	FInventoryAction* action = new FInventoryAction(item->GetUniqueItemID(), this, EInventoryAction::Remove);
	_cachedLastAction = *action;

	//	Now lets update the item's owning inventory
	item->SetOwningInventory(nullptr);

	OnRep_Inventory(Inventory);
}

bool UCOVInventory::PackItem_Validate(UCOVInventoryItem* item)
{
	return true;
}

void UCOVInventory::PackItem_Implementation(UCOVInventoryItem* item)
{
	AActor* ownerActor = GetOwner();
	AActor* itemActor = item->GetOwner();

	Cast<UPrimitiveComponent>(itemActor->GetRootComponent())->SetSimulatePhysics(false);

	COV_LOG(COVInventory, Log, TEXT("Item (%s) packed into inventory and the component simulation data has been generated."), *GetNameSafe(itemActor));

	//	Disables collisions
	itemActor->SetActorEnableCollision(false);
	//	Hides actor
	itemActor->SetActorHiddenInGame(true);
	FAttachmentTransformRules rules(FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	itemActor->AttachToActor(ownerActor, rules);
	itemActor->SetActorLocation(ownerActor->GetActorLocation());
}

// Called every frame
void UCOVInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

