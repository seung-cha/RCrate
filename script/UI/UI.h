#ifndef UI_H
#define UI_H

#include "..\src\imgui\imgui.h"
#include "UIComponents\UIComponent.h"
namespace UI
{
	

	class UI
	{
	public:
		UI(const char* title, ImVec2 position, ImVec2 size, ImVec2 pivot, UIComponent::UIComponent* component = NULL);

		 void Render();
		 void WindowResize(float dx, float dy);


	private:
		const char* title;
		ImVec2 position;
		ImVec2 size;
		ImVec2 pivot;
		UIComponent::UIComponent* component;
		bool firstInit;



	};

}


#endif