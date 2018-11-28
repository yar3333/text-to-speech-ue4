namespace FMRTTSLib
{
	class FMRTTSLibMain
	{
		public:
			static char* TextToWav(const wchar_t* voiceRequiredAttributes, const wchar_t* voiceOptionalAttributes, long Rate, const wchar_t* textToRender, unsigned long* bytesRead);
	};
}