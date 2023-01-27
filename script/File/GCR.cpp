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
		return NULL;
	}
	
	
	void GCR::AddBPMFlag(Flags::BeatChangeFlag* flag)
	{

		if (beatFlags.size() == 0 && flag->time != 0)
		{
			std::cout << "An initial flag is set" << std::endl;
			beatFlags.push_back(new Flags::BeatChangeFlag(flag->bpm));
		}

		int pos = 0;

		for (int i = 0; i < beatFlags.size(); i++)
		{

			if (beatFlags[i]->time == flag->time)
			{
				beatFlags[i]->bpm = flag->bpm;
				std::cout << "Beat Change Flag Insertion: A Flag exists at " << flag->time <<", overriding BPM" << std::endl;
				return;
			}

			if (flag->time > beatFlags[i]->time)
			{
				pos = i+1;
			}

		}

		if (pos >= beatFlags.size())
			beatFlags.push_back(flag);
		else
			beatFlags.insert(beatFlags.begin() + pos, flag);


		std::cout << "A flag is set at time: " << flag->time << ", BPM: " << flag->bpm << std::endl;

		std::cout << std::endl << std::endl;
		std::cout << "DEBUG : FLAG ITERATION: " << std::endl;

		for (int i = 0; i < beatFlags.size(); i++)
		{
			std::cout << "Location: " << i;
			std::cout << " Time: " << beatFlags[i]->time << "; BPM: " << beatFlags[i]->bpm << std::endl;
		}


	}

	void GCR::ApplyFlags()
	{
		for (int i = 0; i < beatFlags.size(); i++)
		{
			beatFlags[i]->Apply(Get()->GetAudio(), Get()->GetFile());
		}

	}

	float GCR::CurrentSPB()
	{
		if (audioSource == NULL || file == NULL)
			return 0;

		if (file->GetSPB() == 0)
			return 0;


		float time = 0;
		float dist = 0;

		for (int i = 0; i < beatFlags.size(); i++)
		{
			if (beatFlags[i]->time >= audioSource->CurrentMillis())
			{
				return time;
			}


			if (i == beatFlags.size() - 1)
			{
				dist = Audio::ToSeconds(audioSource->CurrentMillis() - beatFlags[i]->time);
			}
			else if (audioSource->CurrentMillis() < beatFlags[i+1]->time)
			{
				dist = Audio::ToSeconds(audioSource->CurrentMillis() - beatFlags[i]->time);
			}
			else
			dist = Audio::ToSeconds(beatFlags[i+1]->time - beatFlags[i]->time);


			time += (dist) / (60 / beatFlags[i]->bpm);
		}
		return time;
	}
	


}

