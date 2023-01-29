#include "Track.h"


namespace Track
{

	Track::Track(int ID)
	{
		this->ID = ID;
	}


	void Track::Render(int trackSize)
	{
		width = 0.25f / trackSize;
		centre = ID * width * 2;

		horizontalLines[0].x1.y = centre + width;
		horizontalLines[0].x2.y = centre + width;


		horizontalLines[1].x1.y = centre - width;
		horizontalLines[1].x2.y = centre - width;


		for (int i = 0; i < 2; i++)
		{
			horizontalLines[i].Draw();
		}
	}

}