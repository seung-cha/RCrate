#include "Drawing.h"

namespace Drawing
{
	struct BeatLine
	{
		BeatLine(int time)
		{
			this->time = time;
			line = new Line;
		}
		Line* line;
		int time;
		void Draw(float upperbound, float lowerbound, float spbPos)
		{
			line->x1.y = upperbound;
			line->x2.y = lowerbound;

			line->x1.x = (time - spbPos) * 0.25f;
			line->x2.x = (time - spbPos) * 0.25f;

			line->Draw();
		}
	};
}