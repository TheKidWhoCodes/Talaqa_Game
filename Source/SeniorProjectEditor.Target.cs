// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class SeniorProjectEditorTarget : TargetRules
{
	public SeniorProjectEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		
		// Update build settings
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		
		// Update include order version
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

		ExtraModuleNames.AddRange( new string[] { "SeniorProject" } );
	}
}
