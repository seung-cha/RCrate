#include "UI.h"
#include <iostream>



UI::UI::UI(const char* title, ImVec2 position, ImVec2 size, ImVec2 pivot, UIComponent::UIComponent* component)
{
	this->title = title;
	this->position = position;
	this->size = size;
	this->pivot = pivot;
	firstInit = true;
	this->component = component;
}


void UI::UI::UI::Render()
{
	if (firstInit)
	{
		ImGui::SetNextWindowSize(size);
		ImGui::SetNextWindowPos(position, 0, pivot);
		
		firstInit = false;
	}


	ImGui::Begin(title);
	size = ImGui::GetWindowSize();

	if (component != NULL)
	{
		component->DrawComponent(size.x, size.y);
	}


	ImGui::End();



}


//To do: Fix position change issue
void UI::UI::UI::WindowResize(float dx, float dy)
{

	if (component != NULL)
		component->WindowResize(dx, dy);

	position.x *= dx;
	position.y *= dy;

	
	size.x *= dx;
	size.y *= dy;

	firstInit = true;


}

