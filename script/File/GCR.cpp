#include "GCR.h"

namespace GCR
{

	GCR* GCR::Instance = NULL;

	GCR* GCR::Get()
	{


		if (Instance == NULL)
		{

			std::cout << "New GCR is created!" << std::endl;
			Instance = new GCR();
		}

		return Instance;
	}

	Audio* GCR::GetAudio()
	{
		return audioSource;
	}

	bool GCR::RequestNewAudio()
	{
		wchar_t file[1024];
		*file = NULL;

		OPENFILENAME ofn;
		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.hwndOwner = NULL;
		ofn.lpstrFilter = L"Audio Files(.mp3, .ogg, .wav)\0*.MP3;*.OGG;*.WAV\0";
		ofn.nMaxFile = sizeof(char)* 1024;
		ofn.lpstrFile = &file[0];

		if (!GetOpenFileName(&ofn))
			return false;
		
		//42852
		std::stringstream str;
		for (int i = 0; i < 1024; i++)
		{
			if (file[i] == 52428)
			{
				std::cout << "Fileread; terminated" << std::endl;
				break;
			}

			str << char(file[i]);
		}

		Audio* temp = new Audio(str.str().c_str());

		if (!temp->IsASafeObject())
		{
			delete temp;
			return false;
		}

		
		float vol = audioSource != NULL ? audioSource->GetVolume() : 1;

		delete audioSource;
		audioSource = temp;
		audioSource->SetVolume(vol);

		return true;
	}



	File* GCR::GetFile()
	{
		if (file == NULL)
		{
			std::cout << "New File is created!" << std::endl;
			file = new File;
		}

		return file;
	}
}

