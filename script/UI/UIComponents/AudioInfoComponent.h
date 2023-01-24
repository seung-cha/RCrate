#ifndef AUDIO_INFO_COMPONENT_H
#define AUDIO_INFO_COMPONENT_H

#include "script\UI\UIComponents\UIComponent.h"
#include "src\imgui\imgui.h"
#include "script\File\GCR.h"

namespace UIComponent
{
	class AudioInfoComponent : public UIComponent
	{

	public:
		void DrawComponent(float width, float height) override
		{
			ImGui::BeginChild("AudioInfo");

			if (GCR::GCR::Get()->GetAudio() == NULL)
			{
				ImGui::Text("Select audio to begin.");
				ImGui::EndChild();
				return;
			}


			if (!GCR::GCR::Get()->GetAudio()->IsASafeObject())
			{
				ImGui::Text("Select valid audio to begin.");
				ImGui::EndChild();
				return;
			}




			ImGui::EndChild();
		}

		void WindowResize(float dx, float dy) override
		{

		}

	};
}


#endif
