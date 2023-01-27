#ifndef AUDIO_H
#define AUDIO_H

#include "..\dep\include\irrKlang\irrKlang.h"
#include <iostream>
#include <string.h>


namespace GCR
{
	class Audio
	{
	public:
		Audio(const char* filePath);
		

		void Play();
		void AutoReset(bool value);
		void Pause();
		void ToStart();
		void Reset();
		bool IsPaused();
		bool IsDone();

		static float ToSeconds(unsigned int millisecond);
		int LengthMillis();
		int CurrentMillis();
		float LengthSeconds();
		float CurrentSeconds();
		void SetCurrent(int position);
		void SetVolume(float value);
		float GetVolume();
		/// <summary>
		/// Returns whether this object is safe to use; i.e: audio is not null.
		/// </summary>
		/// <returns></returns>
		bool IsASafeObject();
		



	private:
		bool autoReset = false;
		float volume = 1;
		std::string path;
		static irrklang::ISoundEngine* engine;
		irrklang::ISound* audio;		
		bool isPaused;
		int lengthMillis;
	};


}



#endif