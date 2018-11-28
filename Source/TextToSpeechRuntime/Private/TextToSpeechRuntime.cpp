#include "TextToSpeechRuntimePrivatePCH.h"
#include "TTSSoundWave.h"

class FTextToSpeechRuntime : public ITextToSpeechRuntime
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FTextToSpeechRuntime, TextToSpeechRuntime )

void FTextToSpeechRuntime::StartupModule()
{
}

void FTextToSpeechRuntime::ShutdownModule()
{
}
