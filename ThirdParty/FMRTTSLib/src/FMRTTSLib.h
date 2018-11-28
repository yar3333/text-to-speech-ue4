namespace FMRTTSLib
{
	class FMRTTSLibMain
	{
		private:
			static char* TextToWavInner(const wchar_t* voiceRequiredAttributes, const  wchar_t* voiceOptionalAttributes, long rate, const wchar_t* textToRender, unsigned long* bytesRead);
			static void checkAndThowException(HRESULT hr);

		public:
			static char* TextToWav(const wchar_t* voiceRequiredAttributes, const  wchar_t* voiceOptionalAttributes, long rate, const wchar_t* textToRender, unsigned long* bytesRead);
	};
}