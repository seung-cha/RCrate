#ifndef GCR_H
#define GCR_H


#include "Audio.h"
#include "File.h"
#include "Flag.h"
#include <string>
#include <windows.h>
#include <iostream>
#include <sstream>
#include <vector>


namespace GCR
{
	class GCR
	{
	public:
		static GCR* Get(); 

		void TempSetAudio(const char* path)
		{
			audioSource = new Audio(path);
		}

		Audio* GetAudio();
		File* GetFile();
		bool RequestNewAudio();

		float CurrentSPB();
		void AddBPMFlag(Flags::BeatChangeFlag* flag);
		void ApplyFlags();



	private:
		static GCR* Instance;
		Audio* audioSource = NULL;
		File* file = NULL;
		std::vector < Flags::BeatChangeFlag* > flags;


	};
}



#endif