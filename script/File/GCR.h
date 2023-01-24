#ifndef GCR_H
#define GCR_H

#include "Audio.h"
#include "File.h"
#include <string>
#include <windows.h>
#include <iostream>
#include <sstream>


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


	private:
		static GCR* Instance;
		Audio* audioSource = NULL;
		File* file = NULL;


	};
}



#endif