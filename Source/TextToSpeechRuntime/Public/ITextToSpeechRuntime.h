#pragma once
#include "ModuleManager.h"

class ITextToSpeechRuntime : public IModuleInterface
{
	public:
		static inline ITextToSpeechRuntime& Get()
		{
			return FModuleManager::LoadModuleChecked<ITextToSpeechRuntime>("TextToSpeechRuntime");
		}

		static inline bool IsAvailable()
		{
			return FModuleManager::Get().IsModuleLoaded("TextToSpeechRuntime");
		}
};

