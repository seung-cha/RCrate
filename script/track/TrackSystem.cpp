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
	}


	TrackSystem* TrackSystem::Get()
	{
		if (Instance == NULL)
		{
			Instance = new TrackSystem;
			Instance->tracks.push_back(new Track(0));
			Instance->tracks.push_back(new Track(1));
		}

		return Instance;
	}



}