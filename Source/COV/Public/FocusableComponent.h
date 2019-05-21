// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FocusableComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogFocusable, All, Log)

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COV_API UFocusableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFocusableComponent();

	UFUNCTION(Category = "Focusable", BlueprintCallable, BlueprintPure)
		FORCEINLINE bool IsFocusable() const;

	UFUNCTION(Category = "Focusable", BlueprintCallable)
		void SetIsFocusable(bool bIsFocusable);
	UPROPERTY(Category = "Focusable", EditDefaultsOnly)
		bool bCanBeFocusedAt = true;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
private:
};

bool UFocusableComponent::IsFocusable() const
{
	return bCanBeFocusedAt;
}