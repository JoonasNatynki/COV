// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class ScreenStackRuntimeTarget : TargetRules
{
	public ScreenStackRuntimeTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		//ExtraModuleNames.AddRange( new string[] { "COV" } );
	}
}
