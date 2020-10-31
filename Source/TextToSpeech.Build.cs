using UnrealBuildTool;
using System;
using System.IO;

namespace UnrealBuildTool.Rules
{
	public class TextToSpeech : ModuleRules
	{
		public TextToSpeech(ReadOnlyTargetRules Target) : base(Target)
		{
			PublicIncludePaths.AddRange(new string[]
			{
			});

			PrivateIncludePaths.AddRange(new string[]
			{
			});

			PublicDependencyModuleNames.AddRange(new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"Media"
			});

			PrivateDependencyModuleNames.AddRange(new string[]
			{
			});
			
			DynamicallyLoadedModuleNames.AddRange(new string[]
			{
			});

			//Necessary to build Media Sound Wave - should be fixed in 4.11
			//PrivateIncludePathModuleNames.Add("Media");
			//PrivateIncludePathModuleNames.Add("Engine");

			PrivatePCHHeaderFile = "TextToSpeechPCH.h";

			LoadFMRTTSLib(Target);
		}
		
		public bool LoadFMRTTSLib(ReadOnlyTargetRules Target)
		{
			if (Target.Platform != UnrealTargetPlatform.Win64 && Target.Platform != UnrealTargetPlatform.Win32)
			{
				PublicDefinitions.Add("WITH_FMRTTSLIB=0");
				return false;
			}

			var FMRTTSLibFolder = Path.Combine(ModuleDirectory, @"..\ThirdParty", "FMRTTSLib");
			var LibraryPath = Path.Combine(FMRTTSLibFolder, Target.Platform == UnrealTargetPlatform.Win64 ? "x64" : "x86");
			
			PublicSystemLibraryPaths.Add(LibraryPath);
			
			PublicAdditionalLibraries.Add(Path.Combine(LibraryPath, "FMRTTSLib.lib"));
			PrivateIncludePaths.Add(Path.Combine(FMRTTSLibFolder, "include"));

			PublicDefinitions.Add("WITH_FMRTTSLIB=1");

			return true;
		}
	}
}