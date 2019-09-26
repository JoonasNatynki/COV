#include "COVEditorRuntime.h"

#include "Engine.h"
#include <Engine/EngineBaseTypes.h>
#include <Engine/EngineTypes.h>
#include <Camera/PlayerCameraManager.h>
#include <MessageLog.h>
#include <UObjectToken.h>
#include <IAssetRegistry.h>
#include <Engine/AssetManager.h>

#if WITH_EDITOR

#include <KismetEditorUtilities.h>

#endif
#include "ScreenStack.h"
#include <LogMacros.h>

void UCOVEditorRuntime::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void UCOVEditorRuntime::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#define LOCTEXT_NAMESPACE "ScreenStack"

class UUserWidget* UCOVEditorRuntimeLibrary::Create(UObject* WorldContextObject, TSubclassOf<class UUserWidget> WidgetType, APlayerController* OwningPlayer)
{
	if (WidgetType == nullptr)
	{
		return nullptr;
	}

	//	Make sure the screen stack component exists in the player controller
	auto screenStack = OwningPlayer->GetComponentByClass(UScreenStack::StaticClass());

	if (!screenStack)
	{
		UE_LOG(LogTemp, Error, TEXT("The owning player controller does not have a screen stack component. Unable to create and push a screen to a stack."));
		FMessageLog("PIE").Error(FText(LOCTEXT("ScreenStack", "The owning player controller does not have a screen stack component. Unable to create and push a screen to a stack.")))->AddToken(FUObjectToken::Create(OwningPlayer));

		return nullptr;
	}

	if (GIsEditor)
	{
		//	WHAT DO!?
	}

	if (OwningPlayer)
	{
		TSubclassOf<UScreen> type = WidgetType;
		UScreen* screen = Cast<UScreen>(Cast<UScreenStack>(screenStack)->PushScreenByClass(type));

		return screen;
	}
	else if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
	{
		return CreateWidget(World, WidgetType);
	}

	return nullptr;
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(UCOVEditorRuntime, COVEditorRuntime)
