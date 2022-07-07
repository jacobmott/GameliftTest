// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameliftTest : ModuleRules
{
	public GameliftTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "GameLiftServerSDK", "UMG", "SlateCore", "HTTP", "Json", "JsonUtilities", "WebBrowserWidget" });
	}
}
