#ifndef FLAG_H
#define FLAG_H

#include "File.h"
#include "Audio.h"

namespace Flags
{

	struct Flag
	{
		virtual void Apply(GCR::Audio* audio, GCR::File* file) = 0;
	};

	struct BeatChangeFlag : public Flag
	{
		BeatChangeFlag(float bpm, int time);

		BeatChangeFlag(float bpm);

		void Apply(GCR::Audio* audio, GCR::File* file) override;




		float bpm;
		unsigned int time;
	};


}



#endif 
