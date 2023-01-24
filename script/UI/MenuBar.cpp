#include "MenuBar.h"
#include "..\src\imgui\imgui.h"
#include <iostream>


namespace UI
{

	void MenuBar::Render()
	{
		if (ImGui::BeginMainMenuBar())
		{


			if (ImGui::BeginMenu("File"))
			{
				ImGui::MenuItem("New File");
				ImGui::MenuItem("Save File");
				ImGui::MenuItem("Save File As");
				ImGui::MenuItem("Load File");
				ImGui::MenuItem("Recent Files");
				ImGui::MenuItem("Export File as Json");


				ImGui::EndMenu();
			}

			

			if(ImGui::BeginMenu("Settings"))
			{
				ImGui::EndMenu();
			}

			ImGui::EndMainMenuBar();

		}



	}


}