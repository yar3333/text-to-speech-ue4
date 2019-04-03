#include "TextToSpeechPCH.h"

class FTextToSpeechModule : public IModuleInterface
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(FTextToSpeechModule, TextToSpeech)

void FTextToSpeechModule::StartupModule()
{
}

void FTextToSpeechModule::ShutdownModule()
{
}
