#ifndef SHADER_H
#define SHADER_H

#include "..\dep\include\glad\glad.h"
#include "..\dep\include\glfw\glfw3.h"

#include "ShaderDefinition.h"

namespace Shader
{
	namespace ShaderDefinitions
	{
		struct Shader
		{
			const char* vertexShader;
			const char* fragmentShader;

			unsigned int vertObj, fragObj, prog;


			Shader(const char* vertShader, const char* fragShader)
			{
				
				vertexShader = vertShader;
				fragmentShader = fragShader;


				vertObj = glCreateShader(GL_VERTEX_SHADER);
				fragObj = glCreateShader(GL_FRAGMENT_SHADER);
				prog = glCreateProgram();

				glShaderSource(vertObj, 1, &vertexShader, NULL);
				glShaderSource(fragObj, 1, &fragmentShader, NULL);

				glCompileShader(vertObj);
				glCompileShader(fragObj);

				glAttachShader(prog, vertObj);
				glAttachShader(prog, fragObj);


				glLinkProgram(prog);

				glDeleteShader(vertObj);
				glDeleteShader(fragObj);
			}


			void Use()
			{
				glUseProgram(prog);
			}
		};

	}


}



#endif
