#ifndef TRACK_SETTINGS_COMPONENT_H
#define TRACK_SETTINGS_COMPONENT_H

#include "UIComponent.h"
#include "..\src\imgui\imgui.h"
#include "..\script\File\GCR.h"
//#include "..\script\File\Flag.h"

namespace UIComponent
{
	class TrackSettingsComponent : public UIComponent
	{
	public:
		void DrawComponent(float width, float height) override
		{
			ImGui::BeginChild("TrackComponent");


			if (GCR::GCR::Get()->GetAudio() == NULL)
			{
				ImGui::Text("Select audio to begin");
				ImGui::EndChild();

				return;
			}

			if (!GCR::GCR::Get()->GetAudio()->IsASafeObject())
			{
				ImGui::Text("Select a valid audio to begin");
				ImGui::EndChild();
				return;
			}

			if (GCR::GCR::Get()->GetFile() == NULL)
			{
				ImGui::Text("ERROR: FILE IS NULL");
				ImGui::EndChild();
				return;
			}

			if (ImGui::SliderFloat("BPM", &bpm, 60, 500, "%.1f", ImGuiSliderFlags_AlwaysClamp))
			{

			}

			if (ImGui::Button("DEBUG: add bpm flag"))
			{
				GCR::GCR::Get()->AddBPMFlag(new Flags::BeatChangeFlag(bpm
					, GCR::GCR::Get()->GetAudio()->CurrentMillis()));
			}



			ImGui::EndChild();
		}


		void WindowResize(float dx, float dy) override
		{

		}

	private:
		float bpm = 60;
	};
}


#endif
