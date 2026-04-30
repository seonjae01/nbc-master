// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NBC_Master : ModuleRules
{
	public NBC_Master(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"NBC_Master",
			"NBC_Master/Variant_Platforming",
			"NBC_Master/Variant_Platforming/Animation",
			"NBC_Master/Variant_Combat",
			"NBC_Master/Variant_Combat/AI",
			"NBC_Master/Variant_Combat/Animation",
			"NBC_Master/Variant_Combat/Gameplay",
			"NBC_Master/Variant_Combat/Interfaces",
			"NBC_Master/Variant_Combat/UI",
			"NBC_Master/Variant_SideScrolling",
			"NBC_Master/Variant_SideScrolling/AI",
			"NBC_Master/Variant_SideScrolling/Gameplay",
			"NBC_Master/Variant_SideScrolling/Interfaces",
			"NBC_Master/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
