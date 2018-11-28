using UnrealBuildTool;
using System;
using System.IO;

namespace UnrealBuildTool.Rules
{
	public class TextToSpeechRuntime : ModuleRules
	{
		public TextToSpeechRuntime(ReadOnlyTargetRules Target) : base(Target)
		{
			PublicIncludePaths.AddRange(
				new string[] {
					
				}
			);

			PrivateIncludePaths.AddRange(
				new string[] {
					"TextToSpeechRuntime/Private",
					"FMRTTSLib"
				}
			);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"Engine",
					"InputCore",
					"Media"
					
				}
			);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
				}
			);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
				}
			);
			
			//Necessary to build Media Sound Wave - should be fixed in 4.11
			PrivateIncludePathModuleNames.Add("Media");
			PrivateIncludePathModuleNames.Add("Engine");
			
			LoadFMRTTSLib(Target);
		}
		
		public bool LoadFMRTTSLib(ReadOnlyTargetRules Target)
		{
			if (Target.Platform != UnrealTargetPlatform.Win64 && Target.Platform != UnrealTargetPlatform.Win32)
			{
				Definitions.Add("WITH_FMRTTSLIB=0");
				return false;
			}

			string PluginPath = Path.Combine(ModuleDirectory, @"..\..\ThirdParty", "FMRTTSLib");
			string LibraryPath = Path.Combine(PluginPath, Target.Platform == UnrealTargetPlatform.Win64 ? "x64" : "x86");
			PublicLibraryPaths.Add(LibraryPath);
			PublicAdditionalLibraries.Add(Path.Combine(LibraryPath, "FMRTTSLib.lib"));
			PrivateIncludePaths.Add(Path.Combine(PluginPath, "include"));

			Definitions.Add("WITH_FMRTTSLIB=1");

			return true;
		}
	}
}