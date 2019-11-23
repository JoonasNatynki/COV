#pragma once

#include "InventoryItem.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogInventoryItem, Log, All)

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class INVENTORYANDITEMS_API UInventoryItemComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(Category = "InventoryItem", EditDefaultsOnly)
		TSubclassOf<AActor> CorrespondingActorClassToSpawn;
};