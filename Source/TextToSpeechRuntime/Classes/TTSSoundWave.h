#pragma once

#include "Engine/EngineTypes.h"
#include "Sound/SoundWave.h"
#include "TTSSoundWave.generated.h"

UCLASS()
class TEXTTOSPEECHRUNTIME_API UTTSSoundWave : public USoundWave
{
	GENERATED_UCLASS_BODY()

	private:
		int16* AudioBuffer;
		unsigned long SamplesRead;
		unsigned long SampleCursor;

	public:
		bool Initialize(FString VoiceRequiredAttributes, FString VoiceOptionalAttributes, int32 Rate, FString Text);
		virtual int32 GeneratePCMData(uint8* PCMData, const int32 SamplesNeeded);
		~UTTSSoundWave();
};
