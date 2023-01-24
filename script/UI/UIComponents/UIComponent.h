#ifndef UI_COMPONENT_H
#define UI_COMPONENT_H

#include "..\src\imgui\imgui.h"

namespace UIComponent
{
	class UIComponent
	{
	public:
		virtual void DrawComponent(float width, float height) = 0;
		virtual void WindowResize(float dx, float dy) = 0;


	};

}




#endif
