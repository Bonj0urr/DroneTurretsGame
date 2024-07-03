// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class DroneTurretsGameTarget : TargetRules
{
	public DroneTurretsGameTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("DroneTurretsGame");
	}
}
