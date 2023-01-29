#include "TrackSystem.h"



namespace Track
{
	TrackSystem* TrackSystem::Instance = NULL;

	void TrackSystem::Render()
	{
		for (int i = 0; i < tracks.size(); i++)
		{
			tracks[i]->Render(tracks.size());
		}

		for (int i = 0; i < beatLines.size(); i++)
		{
			//WE NEED TO OPTIMISE THIS!!
			beatLines[i]->Draw( (0.25f/ tracks.size()) + (((0.25f / tracks.size()) * (tracks.size()-1)) * 2), -0.25f / tracks.size(), GCR::GCR::Get()->CurrentSPB());
		}

		//Temp:

		for (int i = 0; i < beatLines.size(); i++)
		{
			if (beatLines[i]->time - GCR::GCR::Get()->CurrentSPB() < -5)
			{
				beatLines[i]->time = GetLatestLine() + 1;
			}

			if (beatLines[i]->time - GCR::GCR::Get()->CurrentSPB() > 5)
			{
				beatLines[i]->time = GetEarliestLine() - 1;
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
			//Instance->tracks.push_back(new Track(2));
			//Instance->tracks.push_back(new Track(3));


			for (int i = 0; i < 10; i++)
			{
				
				Instance->beatLines.push_back(new Drawing::BeatLine( (i-5)));
			}

		}

		return Instance;
	}

	float TrackSystem::GetLatestLine()
	{
		float rt = beatLines[0]->time;
		for (int i = 1; i < beatLines.size(); i++)
		{
			if (beatLines[i]->time > rt)
			{
				rt = beatLines[i]->time;
			}
		}

		return rt;
	}

	float TrackSystem::GetEarliestLine()
	{
		float rt = beatLines[0]->time;
		for (int i = 1; i < beatLines.size(); i++)
		{
			if (beatLines[i]->time < rt)
			{
				rt = beatLines[i]->time;
			}
		}

		return rt;
	}


	void TrackSystem::AddTrack()
	{
		if (tracks.size() == 4)
		{
			std::cout << "Cannot Add Tracks Anymore!" << std::endl;
			return;
		}
		tracks.push_back(new Track(tracks.size()));
		return;
	}

	void TrackSystem::RemoveTrack()
	{
		if (tracks.size() == 1)
		{
			std::cout << "Cannot Remove Tracks Anymore!" << std::endl;
			return;
		}
		tracks.pop_back();
		return;
	}



}