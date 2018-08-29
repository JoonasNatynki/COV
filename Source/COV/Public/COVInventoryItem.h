// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "COVInventoryItem.generated.h"

class UCOVInventory;

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
		UCOVInventory* GetOwningInventory() const;

	UFUNCTION(Category = "COV Inventory Item", BlueprintCallable)
		void SetOwningInventory(UCOVInventory* inventory);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;	
};
