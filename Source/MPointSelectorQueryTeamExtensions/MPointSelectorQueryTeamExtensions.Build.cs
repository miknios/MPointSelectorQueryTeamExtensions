// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MPointSelectorQueryTeamExtensions : ModuleRules
{
	public MPointSelectorQueryTeamExtensions(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"MPointSelectorQuery",
				"MTeam",

				"Core",
			}
		);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
			}
		);
	}
}