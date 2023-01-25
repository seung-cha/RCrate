#include "Flag.h"



namespace Flags
{
	BeatChangeFlag::BeatChangeFlag(float bpm, int time)
	{
		this->bpm = bpm;
		this->time = time;
	}

	BeatChangeFlag::BeatChangeFlag(float bpm)
	{
		this->bpm = bpm;
		time = 0;
	}
}

	void Flags::BeatChangeFlag::Apply(GCR::Audio* audio, GCR::File* file) 
	{

		if (audio == NULL)
		{
			std::cout << "ERROR WHILE APPLYING BEAT CHANGE FLAG: AUDIO DOES NOT EXIST!" << std::endl;
			return;
		}

		if (!audio->IsASafeObject())
		{
			std::cout << "ERROR WHILE APPLYING BEAT CHANGE FLAG: AUDIO IS CORRUPTED" << std::endl;
			return;
		}

		if (audio->CurrentMillis() >= time)
		{
			file->SetBPM(bpm);
		}



	}

