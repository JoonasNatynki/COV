// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ScreenStackEditor.h"
#include "KismetCompiler.h"
#include "BlueprintNodeSpawner.h"
#include "EditorCategoryUtils.h"
#include <K2Node_CallFunction.h>
#include <EdGraph/EdGraph.h>
#include <EdGraph/EdGraphPin.h>
#include <K2Node_ConstructObjectFromClass.h>

void FScreenStackEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FScreenStackEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.



#define LOCTEXT_NAMESPACE "ScreenStackEditor"


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FScreenStackEditorModule, ScreenStackEditor)