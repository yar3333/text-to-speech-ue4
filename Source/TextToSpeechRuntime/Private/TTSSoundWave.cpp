#include "TextToSpeechRuntimePrivatePCH.h"
#include "TTSSoundWave.h"
#include "FMRTTSLib.h"
#include <inttypes.h>
#include "Audio.h"
//#include "AudioDevice.h"

UTTSSoundWave::UTTSSoundWave(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NumChannels = 1;
	SampleRate = 44100;

	Duration = 0;
	bProcedural = true;
	SampleCursor = 0;
	SamplesRead = 0;
	AudioBuffer = NULL;
}

bool UTTSSoundWave::Initialize(FString VoiceRequiredAttributes, FString VoiceOptionalAttributes, int32 Rate, FString Text)
{
	unsigned long BytesRead;
	AudioBuffer = (int16*)FMRTTSLib::FMRTTSLibMain::TextToWav(*VoiceRequiredAttributes, *VoiceOptionalAttributes, Rate, *Text, &BytesRead);
	if (AudioBuffer)
	{
		SamplesRead = BytesRead / 2;
		Duration = SamplesRead / 44100.0;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Can't generate wave from speech (may be voice not found, check VoiceRequiredAttributes)."));
	}
	return true;
}

int32 UTTSSoundWave::GeneratePCMData(uint8* PCMData, const int32 SamplesNeeded)
{
	if (!AudioBuffer) return 0;

	auto samplesToCopy = SampleCursor + SamplesNeeded <= SamplesRead ? SamplesNeeded : SamplesRead - SampleCursor;
	memcpy(PCMData, AudioBuffer + SampleCursor, samplesToCopy * 2);
	SampleCursor += samplesToCopy;

	return samplesToCopy * 2;
}

UTTSSoundWave::~UTTSSoundWave()
{
	if (AudioBuffer)
	{
		delete AudioBuffer;
	}
}