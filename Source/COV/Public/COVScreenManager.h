// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <UserWidget.h>
#include "COVScreenManager.generated.h"

class UCOVScreen;
class ACOVPlayerController;

DECLARE_LOG_CATEGORY_EXTERN(COVScreenManager, Log, All)

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class COV_API UCOVScreenManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCOVScreenManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(Category = "Getter", BlueprintCallable, BlueprintPure)
		APlayerController* GetOwnerPlayerController() const;

	UFUNCTION(Category = "Screen", BlueprintCallable)
		bool PushScreenByClass(TSubclassOf<UCOVScreen> widgetClass);
};
