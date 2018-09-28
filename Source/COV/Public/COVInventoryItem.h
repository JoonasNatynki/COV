// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "COVInventoryItem.generated.h"

class UCOVInventory;

DECLARE_LOG_CATEGORY_EXTERN(COVInventoryItem, Log, All)

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class COV_API UCOVInventoryItem : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Category = "COV Inventory Item", Replicated, VisibleAnywhere)
		UCOVInventory* _owningInventory;

public:	
	// Sets default values for this component's properties
	UCOVInventoryItem();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty, FDefaultAllocator>& OutLifetimeProps) const override;

	UFUNCTION(Category = "COV Inventory Item", BlueprintCallable)
		//	Gets the inventory that this item is in currently, if any
		UCOVInventory* GetOwningInventory() const;

	UFUNCTION(Category = "COV Inventory Item", BlueprintCallable)
		//	Set the inventory that this item is in currently, if in any
		void SetOwningInventory(UCOVInventory* inventory);

	UFUNCTION(Category = "COV Inventory Item", BlueprintCallable, NetMulticast, Reliable, BlueprintAuthorityOnly, WithValidation)
		//	Packs the item to be ready for be inserted into an inventory
		void PackItem();
	UFUNCTION(Category = "COV Inventory Item", BlueprintCallable, NetMulticast, Reliable, BlueprintAuthorityOnly, WithValidation)
		//	Packs the item to be ready for be inserted into an inventory
		void UnpackItem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;	
};
