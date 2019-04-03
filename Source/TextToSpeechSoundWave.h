#pragma once

#include "TextToSpeechPCH.h"
#include "TextToSpeechSoundWave.generated.h"

UCLASS()
class TEXTTOSPEECH_API UTextToSpeechSoundWave : public USoundWaveProcedural
{
	GENERATED_UCLASS_BODY()

	public:
		bool Initialize(const FString &VoiceRequiredAttributes, const FString &VoiceOptionalAttributes, int32 Rate, const FString &Text);
};
