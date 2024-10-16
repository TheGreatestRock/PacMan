// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PacMan : ModuleRules
{
	public PacMan(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "HeadMountedDisplay", "AIModule", "NavigationSystem", "Paper2D" });
	}
}
