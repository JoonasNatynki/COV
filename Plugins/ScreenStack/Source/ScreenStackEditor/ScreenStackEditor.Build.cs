// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ScreenStackEditor : ModuleRules
{
	public ScreenStackEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "UMG" });

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
               "Core",
               "CoreUObject",
               "InputCore",
               "Slate",
               "Engine",
               "AssetTools",
               "UnrealEd", // for FAssetEditorManager
               "KismetWidgets",
               "KismetCompiler",
               "BlueprintGraph",
               "GraphEditor",
               "Kismet",  // for FWorkflowCentricApplication
               "PropertyEditor",
               "EditorStyle",
               "Slate",
               "SlateCore",
               "Sequencer",
               "DetailCustomizations",
               "Settings",
               "RenderCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);

        DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
