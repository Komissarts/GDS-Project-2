// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MarioSelf : ModuleRules
{
	public MarioSelf(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
