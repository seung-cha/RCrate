#ifndef FILE_INFO_COMPONENT_H
#define FILE_INFO_COMPONENT_H

#include "script\UI\UIComponents\UIComponent.h"
#include "src\imgui\imgui.h"
#include "src\imgui\imgui_stdlib.h"
#include "script\File\GCR.h"
#include <string.h>


namespace UIComponent
{
	class FileInfoComponent : public UIComponent
	{
	public:

		void DrawComponent(float width, float height) override
		{
			ImGui::BeginChild("FileInfo");

			const char* str = GCR::GCR::Get()->GetAudio() == NULL ? "Select audio to begin editing!" :
				"Audio is selected!";
		
			if (ImGui::Button(str))
			{
				std::cout << "New File Reqeusted" << std::endl;

				if (GCR::GCR::Get()->GetAudio() != NULL)
				{
					GCR::GCR::Get()->GetAudio()->Pause();
				}

				GCR::GCR::Get()->RequestNewAudio();
			}

			if (GCR::GCR::Get()->GetAudio() == NULL)
			{
				ImGui::EndChild();
				return;
			}


			if (ImGui::InputText("Artist Name", &artName))
			{
				GCR::GCR::Get()->GetFile()->SetArtistName(artName);
			}

			if (ImGui::InputText("Song Name", &songName))
			{
				GCR::GCR::Get()->GetFile()->SetSongName(songName);
			}

			//Debug:
			if (ImGui::Button("Debug; output fields data"))
			{
				std::cout << GCR::GCR::Get()->GetFile()->GetArtistName() << std::endl;
				std::cout << GCR::GCR::Get()->GetFile()->GetSongName() << std::endl;
			}

			if (ImGui::Button("Debug; clear data"))
			{
				artName.clear();
				songName.clear();
				GCR::GCR::Get()->GetFile()->ClearArtistName();
				GCR::GCR::Get()->GetFile()->ClearSongName();
			}


			ImGui::EndChild();

		}





		void WindowResize(float dx, float dy) override
		{

		}


	private:
		std::string artName;
		std::string songName;
	};

}



#endif
