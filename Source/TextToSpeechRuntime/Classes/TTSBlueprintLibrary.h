#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "TTSBlueprintLibrary.generated.h"

UCLASS()
class TEXTTOSPEECHRUNTIME_API UTTSBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	public:
		UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Text To Speech")
		static USoundWave* TextToWave(FString VoiceRequiredAttributes = "vendor=microsoft;language=409", FString VoiceOptionalAttributes = "", int32 Rate = 0, FString Text = "test");
};
