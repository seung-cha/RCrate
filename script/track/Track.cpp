#include "Track.h"


namespace Track
{

	Track::Track()
	{
		width = 0.25f;
		centre = 0;

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