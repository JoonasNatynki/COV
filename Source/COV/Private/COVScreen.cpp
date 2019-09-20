// Fill out your copyright notice in the Description page of Project Settings.

#include "COVScreen.h"
#include "COVBlueprintFunctionLibrary.h"
#include <Reply.h>

DEFINE_LOG_CATEGORY(COVScreen)

UCOVScreen::UCOVScreen(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
	bIsFocusable = true;
}

FReply UCOVScreen::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	//COV_LOG(COVScreen, Log, TEXT(""));

	FKey key = InKeyEvent.GetKey();

	FReply result(FReply::Handled());

	return result;
}
