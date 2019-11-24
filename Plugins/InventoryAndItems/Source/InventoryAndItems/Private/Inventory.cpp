#include "Inventory.h"
#include "InventoryItem.h"
#include <UnrealNetwork.h>

DEFINE_LOG_CATEGORY(LogInventory)

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	SetIsReplicated(true);
}

void UInventoryComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty, FDefaultAllocator>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UInventoryComponent, Inventory);
}

void UInventoryComponent::TransferInventoryDataToObject(UObject* fromObject, UObject* toObject) const
{
	ensure(IsValid(fromObject) && IsValid(toObject));

	for (TFieldIterator<UProperty> property_1(fromObject->GetClass()); property_1; ++property_1)
	{
		const FName metaTag("InventoryItemData");
		const bool bHasMetaTag_1 = property_1->HasMetaData(metaTag);

		//	Only look into properties that have the metadata tag. These items want these properties to pass over to the item as it is put into - or taken out - of the inventory.
		if(bHasMetaTag_1)
		{
			for (TFieldIterator<UProperty> property_2(fromObject->GetClass()); property_2; ++property_2)
			{
				const bool bHasMetaTag_2 = property_2->HasMetaData(metaTag);

				if (bHasMetaTag_2 && (property_1->SameType(*property_1)) && (property_1->GetFName() == property_2->GetFName()))
				{
					UE_LOG(LogInventory, Log, TEXT("Copying (%s) property from (%s) to (%s)"), *property_1->GetFName().ToString(), *GetNameSafe(fromObject), *GetNameSafe(toObject));
					void* theData = property_1->ContainerPtrToValuePtr<void>(fromObject);
					void* destinationData = property_2->ContainerPtrToValuePtr<void>(toObject);
					property_1->CopySingleValue(destinationData, theData);
				}
			}
		}
	}
}

bool UInventoryComponent::AddItem(UObject* item)
{
	if (ensure(GetOwner()->HasAuthority()))
	{
		ensure(IsValid(item));

		UE_LOG(LogInventory, Log, TEXT("Adding item (%s) to inventory on (%s)."), *GetNameSafe(item), *GetNameSafe(GetOwner()));

		AActor* itemActor = Cast<AActor>(item);

		//	For actors
		if (IsValid(itemActor))
		{
			UInventoryItemComponent* inventoryItemComp = itemActor->FindComponentByClass<UInventoryItemComponent>();

			if (IsValid(inventoryItemComp))
			{
				if (!ensure(inventoryItemComp->CorrespondingActorClassToSpawn))
				{
					return false;
				}

				AActor* spawnedActor = GetWorld()->SpawnActor<AActor>(inventoryItemComp->CorrespondingActorClassToSpawn);

				check(IsValid(spawnedActor));

				//	Corresponding spawned actor must also have the inventory item component
				UInventoryItemComponent* spawnedActorInventoryItemComp = spawnedActor->FindComponentByClass<UInventoryItemComponent>();

				check(IsValid(spawnedActorInventoryItemComp));

				//	Set the corresponding class to be who spawned it
				spawnedActorInventoryItemComp->CorrespondingActorClassToSpawn = GetClass();

				//	Update the spawned item guid to match the original
				spawnedActorInventoryItemComp->SetItemGUID(inventoryItemComp->GetItemGUID());

				UE_LOG(LogInventory, Verbose, TEXT("Corresponding actor (%s) spawned for item (%s). Transferring inventory data to the spawned object..."), *GetNameSafe(spawnedActor), *GetNameSafe(item));

				TransferInventoryDataToObject(item, spawnedActor);

				UE_LOG(LogInventory, Verbose, TEXT("Inventory data transferred to actor (%s)."), *GetNameSafe(spawnedActor));

				Inventory.Add(spawnedActor);
				OnRep_Inventory();

				//	Maybe destroy the original item now?
				itemActor->Destroy();

				return true;
			}
		}
	}

	return false;
}

void UInventoryComponent::OnRep_Inventory()
{
	AActor* item = Inventory.Top();
	UE_LOG(LogInventory, Log, TEXT("OnRep_Inventory = (%s)"), *GetNameSafe(item));
	UInventoryItemComponent* inventoryItemComp = item->FindComponentByClass<UInventoryItemComponent>();
	OnItemAdded.Broadcast(inventoryItemComp);
}