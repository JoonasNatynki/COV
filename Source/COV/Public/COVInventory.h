// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <DelegateCombinations.h>
#include "COVInventory.generated.h"

class UCOVInventoryItem;
class UCOVInventory;
class UPrimitiveComponent;

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

	FInventoryAction(const FGuid& itemGUID, UCOVInventory* invin, const EInventoryAction act)
	{
		UniqueItemGUID = itemGUID;
		inventory = invin;
		action = act;
	};

	UPROPERTY(BlueprintReadOnly)
		FGuid UniqueItemGUID;
	UPROPERTY(BlueprintReadOnly)
		UCOVInventory* inventory = nullptr;
	UPROPERTY(BlueprintReadOnly)
		TEnumAsByte<EInventoryAction> action = EInventoryAction::Add;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventoryChanged, const FInventoryAction, _action);

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
		TArray<UCOVInventoryItem*> Inventory;
	UFUNCTION()
		void OnRep_Inventory(TArray<UCOVInventoryItem*> inv) const;

	UPROPERTY(Category = "Inventory", BlueprintAssignable)
		//	Called whenever the inventory changes
		FOnInventoryChanged OnInventoryChanged;

	UFUNCTION(Category = "Inventory", Server, Reliable, WithValidation, BlueprintCallable, BlueprintAuthorityOnly)
		void AddItem(UCOVInventoryItem* item);

	UFUNCTION(Category = "Inventory", Server, Reliable, WithValidation, BlueprintCallable, BlueprintAuthorityOnly)
		void RemoveItem(UCOVInventoryItem* item);

	UFUNCTION(Category = "Inventory", Server, Reliable, WithValidation, BlueprintCallable, BlueprintAuthorityOnly)
		void PackItem(UCOVInventoryItem* item);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


	UPROPERTY(Transient, Replicated)
		//	For storing the last changed item in the inventory so we can retrieve information more quickly for logging.
		FInventoryAction _cachedLastAction;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;	
};
