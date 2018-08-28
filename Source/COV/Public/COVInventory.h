// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <DelegateCombinations.h>
#include "COVInventory.generated.h"

class UCOVInventoryItem;
class UCOVInventory;

DECLARE_LOG_CATEGORY_EXTERN(COVInventory, Log, All)

UENUM(BlueprintType) enum EInventoryAction
{
	Add,
	Remove
};

USTRUCT(Blueprintable) struct FInventoryAction
{
	GENERATED_BODY()

		FInventoryAction() {};

	FInventoryAction(UCOVInventoryItem* itemin, UCOVInventory* invin, EInventoryAction act)
	{
		item = itemin;
		inventory = invin;
		action = act;
	};

	UPROPERTY(BlueprintReadOnly)
		UCOVInventoryItem* item;
	UPROPERTY(BlueprintReadOnly)
		UCOVInventory* inventory;
	UPROPERTY(BlueprintReadOnly)
		TEnumAsByte<EInventoryAction> action;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventoryChanged, const FInventoryAction&, _action);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class COV_API UCOVInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCOVInventory();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty, FDefaultAllocator>& OutLifetimeProps) const override;

	UPROPERTY(Category = "Inventory", VisibleAnywhere, ReplicatedUsing = OnRep_Inventory)
		//	The inventory that contains Inventory Items
		TArray<UCOVInventoryItem*> _inventory;
	UFUNCTION()
		void OnRep_Inventory(TArray<UCOVInventoryItem*> inv) const;

	UPROPERTY(Transient, Replicated)
	//	For storing the last changed item in the inventory so we can retrieve information more quickly for logging.
	FInventoryAction _cachedLastAction;

	UPROPERTY(Category = "Inventory", BlueprintAssignable)
		//	Called whenever the inventory changes
		FOnInventoryChanged OnInventoryChanged;

	UFUNCTION(Category = "Inventory", Server, Reliable, WithValidation, BlueprintCallable, BlueprintAuthorityOnly)
		void AddItem(UCOVInventoryItem* item);

	UFUNCTION(Category = "Inventory", Server, Reliable, WithValidation, BlueprintCallable, BlueprintAuthorityOnly)
		void RemoveItem(UCOVInventoryItem* item);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;	
};
