#pragma once
#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include <Engine/EngineTypes.h>
#include <GameFramework/PlayerController.h>
#include <MessageLog.h>
#include <UObjectToken.h>
#include <Kismet/BlueprintFunctionLibrary.h>
#include "COVEditorRuntime.generated.h"

class UCOVEditorRuntime : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

//	Blueprint function library class
UCLASS()
class COVEDITORRUNTIME_API UCOVEditorRuntimeLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

};

/*
class COVEDITOR_API UGISBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", FriendlyName = "Create Item Data", BlueprintInternalUseOnly = "true"), Category = "Game Inventory System")
		static class UGISItemData* Create(UObject* WorldContextObject, TSubclassOf<class UGISItemData> ItemType, APlayerController* OwningPlayer);
	template< class T > T* CreateDataItem(APlayerController* OwningPlayer, UClass* UserWidgetClass);
};
*/