#include "TextToSpeechPCH.h"
#include "TextToSpeechLibrary.h"
#include "TextToSpeechSoundWave.h"

UTextToSpeechLibrary::UTextToSpeechLibrary(const class FObjectInitializer& PCIP) : Super(PCIP)
{
}

USoundWave* UTextToSpeechLibrary::TextToWave(FString VoiceRequiredAttributes, FString VoiceOptionalAttributes, int32 Rate, FString Text)
{
	auto TTSSoundWave = NewObject<UTextToSpeechSoundWave>();
	TTSSoundWave->Initialize(VoiceRequiredAttributes, VoiceOptionalAttributes, Rate, Text);
	return TTSSoundWave;
}
