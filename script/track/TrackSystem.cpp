#include "TrackSystem.h"



namespace Track
{
	TrackSystem* TrackSystem::Instance = NULL;

	void TrackSystem::Render()
	{
		for (int i = 0; i < tracks.size(); i++)
		{
			tracks[i]->Render();
		}

		for (int i = 0; i < beatLines.size(); i++)
		{
			beatLines[i]->Draw(0.25f, -0.25f, GCR::GCR::Get()->CurrentSPB());
		}

		//Temp:

		for (int i = 0; i < beatLines.size(); i++)
		{
			if (beatLines[i]->time - GCR::GCR::Get()->CurrentSPB() < -1)
			{
				beatLines[i]->time = GetLatestLine() + 1;
			}
		}

	}


	TrackSystem* TrackSystem::Get()
	{
		if (Instance == NULL)
		{
			Instance = new TrackSystem;
			Instance->tracks.push_back(new Track(0));
			//Instance->tracks.push_back(new Track(1));


			for (int i = 0; i < 7; i++)
			{
				Instance->beatLines.push_back(new Drawing::BeatLine( (i)));
			}

		}

		return Instance;
	}

	float TrackSystem::GetLatestLine()
	{
		float rt = beatLines[0]->time;
		for (int i = 0; i < beatLines.size(); i++)
		{
			if (beatLines[i]->time > rt)
			{
				rt = beatLines[i]->time;
			}
		}

		return rt;
	}



}