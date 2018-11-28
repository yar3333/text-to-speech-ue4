#include "TextToSpeechRuntimePrivatePCH.h"
#include "TTSBlueprintLibrary.h"
#include "TTSSoundWave.h"

UTTSBlueprintLibrary::UTTSBlueprintLibrary(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{
}

USoundWave* UTTSBlueprintLibrary::TextToWave(FString VoiceRequiredAttributes, FString VoiceOptionalAttributes, int32 Rate, FString Text)
{
	auto TTSSoundWave = NewObject<UTTSSoundWave>();
	TTSSoundWave->Initialize(VoiceRequiredAttributes, VoiceOptionalAttributes, Rate, Text);
	return TTSSoundWave;
}
