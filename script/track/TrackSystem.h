#ifndef TRACK_SYSTEM_H
#define TRACK_SYSTEM_H

#include <vector>
#include "Track.h"
#include "..\script\File\GCR.h"
#include "..\script\drawing\BeatLine.h"

namespace Track
{
	class TrackSystem
	{
	public:
		static TrackSystem* Get();
		void Render();


	private:
		float GetLatestLine();
		float GetEarliestLine();
		std::vector<Track*> tracks;
		std::vector<Drawing::BeatLine*> beatLines;
		static TrackSystem* Instance;

	};
	
}



#endif
