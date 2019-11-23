#pragma once

#include "Inventory.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogInventory, Log, All)

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class INVENTORYANDITEMS_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(Category = "Inventory", BlueprintCallable)
		//	This function goes through all the properties in the fromobject and transfers properties tagged with "InventoryItemData" metatag to the toobject. NOTE: The properties need to be exactly the same name and type for the values to pass between each other
		void TransferInventoryDataToObject(UObject* fromObject, UObject* toObject) const;

	UFUNCTION(Category = "Inventory", BlueprintCallable, BlueprintAuthorityOnly)
		bool AddItem(UObject* item);


	UPROPERTY(Category = "Inventory", BlueprintReadOnly)
		TArray<UObject*> Inventory;
};