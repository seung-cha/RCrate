#ifndef DRAWING_H
#define DRAWING_H

#include "..\dep\include\glad\glad.h"
#include "..\dep\include\glfw\glfw3.h"

#include "..\src\glm\glm.hpp"

#include <iostream>

namespace Drawing
{
	struct Line
	{
		glm::vec2 x1, x2;
		unsigned int VAO, VBO;



		Line()
		{
			
			x1.x = -1;
			x1.y = 0;
			x2.x = 1;
			x2.y = 0;

			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);
		

		}


		Line(glm::vec2 x1_, glm::vec2 x2_)
		{
			x1 = x1_;
			x2 = x2_;

			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);

			

		}


		void Draw()
		{


			float arr[4] = { x1.x, x1.y, x2.x, x2.y };

			glBindVertexArray(VAO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(arr), arr, GL_STATIC_DRAW);

			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);
			glEnableVertexAttribArray(0);
			glDrawArrays(GL_LINES, 0, 2);


			glBindVertexArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			




		}


	};


}


#endif
