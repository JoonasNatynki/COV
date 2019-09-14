// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <UserWidget.h>
#include "COVScreenManager.generated.h"

class UCOVScreen;
class ACOVPlayerController;

DECLARE_LOG_CATEGORY_EXTERN(COVScreenManager, Log, All)

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScreenRemoval, UCOVScreen*, PoppedScreen);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScreenPushed, UCOVScreen*, PushedScreen);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class COV_API UCOVScreenManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCOVScreenManager();

	TArray<UCOVScreen*> screenStack;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void UpdateScreenStackVisibilities_Internal();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(Category = "Screen", BlueprintAssignable)
		FOnScreenRemoval OnScreenRemoval;
	UPROPERTY(Category = "Screen", BlueprintAssignable)
		FOnScreenPushed OnScreenPushed;

	
	UFUNCTION(Category = "Screen", BlueprintCallable, BlueprintPure)
		APlayerController* GetOwnerPlayerController() const;

	UFUNCTION(Category = "Screen", BlueprintCallable)
		bool PushScreenByClass(TSubclassOf<UCOVScreen> widgetClass);

	UFUNCTION(Category = "Screen", BlueprintCallable)
		bool PopTopScreen();

	UFUNCTION(Category = "Screen", BlueprintCallable)
		UCOVScreen* GetTopMostScreen();

	UFUNCTION(Category = "Screen", BlueprintCallable)
		bool PopScreen(UCOVScreen* screen);

	UFUNCTION(Category = "Screen", BlueprintCallable)
		UCOVScreen* FindScreenOfType(TSubclassOf<UCOVScreen> screenType);

	UFUNCTION(Category = "Screen", BlueprintCallable)
		bool HasScreen(UCOVScreen* screen);
};

FORCEINLINE UCOVScreen* UCOVScreenManager::GetTopMostScreen()
{
	if (screenStack.Num() > 0)
	{
		return screenStack[screenStack.Num() - 1];
	}
	else
	{
		return nullptr;
	}
}