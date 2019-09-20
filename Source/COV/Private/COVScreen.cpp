// Fill out your copyright notice in the Description page of Project Settings.

#include "COVScreen.h"
#include "COVBlueprintFunctionLibrary.h"
#include <Reply.h>
#include "COVScreenManager.h"
#include <MessageLog.h>
#include <UObjectToken.h>

DEFINE_LOG_CATEGORY(COVScreen)
#define LOCTEXT_NAMESPACE "COVScreen"

UCOVScreen::UCOVScreen(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
	bIsFocusable = true;
}

FReply UCOVScreen::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	FKey key = InKeyEvent.GetKey();

	if (key == KeyToCloseScreenWith)
	{
		COV_LOG(COVScreen, Log, TEXT("Screen escape key (%s) pressed. Popping screen (%s) from stack."), *KeyToCloseScreenWith.ToString(), *GetNameSafe(this));
		UCOVScreenManager* screenManager = Cast<UCOVScreenManager>(GetOwningPlayer()->GetComponentByClass(UCOVScreenManager::StaticClass()));

		if (IsValid(screenManager))
		{
			//	Pop the screen!
			screenManager->PopScreen(this);
		}
		else
		{
			COV_LOG(COVScreen, Error, TEXT("No screen stack component found from the owning player (%s) of this widget (%s). Could not escape currently displayed screen.."), *GetNameSafe(this));
			FMessageLog("COVScreen").Error(FText::FromString("No screen stack component found from the owning player of this widget. Could not escape currently displayed screen."))->AddToken(FUObjectToken::Create(this));
		}
	}

	FReply result(FReply::Handled());

	return result;
}
