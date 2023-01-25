#ifndef SHADER_DEF_H
#define SHADER_DEF_H


//To do: probably get rid of this and actually IO shader files, lol.
namespace Shader
{
	namespace ShaderDefinitions
	{


		const char* vertexShader =
			"#version 330 core\n"
			"layout (location = 0) in vec2 pointVec;\n"
			"void main() {\n"
			"gl_Position = vec4(pointVec,0,1);}\n";


		const char* fragmentShader =
			"#version 330 core\n"
			"out vec4 fragColour;\n"
			"void main(){\n"
			"fragColour = vec4(0);}\n";
	}


}




#endif
