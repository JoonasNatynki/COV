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

bool UCOVInventoryItem::PackItem_Validate()
{
	return true;
}

void UCOVInventoryItem::PackItem_Implementation()
{
	COV_LOG(COVInventoryItem, Log, TEXT("Packing item (%s)"), *DisplayName);
	AActor* itemActor = GetOwner();
	itemActor->SetActorHiddenInGame(true);
	
	UPrimitiveComponent* tempcomp = Cast<UPrimitiveComponent>(itemActor->GetRootComponent());
	
	if (IsValid(tempcomp))
	{
		tempcomp->SetSimulatePhysics(false);
		tempcomp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
	else
	{
		COV_LOG(COVInventoryItem, Warning, TEXT("Could not pack item (%s), root component was not valid or did not inherit from UPrimitiveComponent."), *DisplayName);
	}
}

bool UCOVInventoryItem::UnpackItem_Validate()
{
	return true;
}

void UCOVInventoryItem::UnpackItem_Implementation()
{
	COV_LOG(COVInventoryItem, Log, TEXT("Unpacking item (%s)"), *GetNameSafe(GetOwner()));
	AActor* itemActor = GetOwner();
	//itemActor->SetActorHiddenInGame(false);
	UPrimitiveComponent* tempcomp = Cast<UPrimitiveComponent>(itemActor->GetRootComponent());
	tempcomp->SetSimulatePhysics(true);
	tempcomp->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
}

// Called every frame
void UCOVInventoryItem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

