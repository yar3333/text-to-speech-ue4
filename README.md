TextToSpeech UE4 plugin
=======================

Text-to-speech synthesis for Unreal Engine 4.21 via Windows SAPI.
Based on https://github.com/indomitusgames/TextToSpeech-UE4 (major bugfixes/improvements).

How to use it
-------------

* Checkout the code into your project's "Plugins" directory. It may be necessary to create it under the project root.
* Check the plugin is active in Unreal Engine 4 editor.
* The plugin exposes a new Blueprint node, "TextToWave", which output SoundWave. Just use some kind of standard "Play Sound" node to play it.

TextToWave parameters:

* VoiceRequiredAttributes / String - required voice attributes - used to search most relevant voice (see https://stackoverflow.com/questions/21220156/how-to-set-voice-sapi5);
* VoiceOptionalAttributes / String - optional voice attributes;
* Rate / Int - speech speed (-10...10);
* Text / String - text to render into wave.
