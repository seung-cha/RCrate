#ifndef TRACK_H
#define TRACK_H

#include "..\script\drawing\Drawing.h"
#include "..\src\glm\glm.hpp"

namespace Track
{
	class Track
	{
	public:
		Track();

		void Render(); 



	private:
		Drawing::Line horizontalLines[2];
		float width, centre;


	};
}


#endif
