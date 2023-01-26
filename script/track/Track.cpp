#include "Track.h"


namespace Track
{

	Track::Track(int ID)
	{
		this->ID = ID;
		width = 0.25f;
		centre = ID * width*2;

		horizontalLines[0].x1.y = centre + width;
		horizontalLines[0].x2.y = centre + width;


		horizontalLines[1].x1.y = centre - width;
		horizontalLines[1].x2.y = centre - width;
	}


	void Track::Render()
	{
		for (int i = 0; i < 2; i++)
		{
			horizontalLines[i].Draw();
		}
	}

}