#ifndef TRACK_SYSTEM_H
#define TRACK_SYSTEM_H

#include <vector>
#include "Track.h"

namespace Track
{
	class TrackSystem
	{
	public:
		static TrackSystem* Get();
		void Render();


	private:
		std::vector<Track*> tracks;
		static TrackSystem* Instance;

	};
	
}



#endif
