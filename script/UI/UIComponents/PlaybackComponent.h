#ifndef UI_COMPONENT_PLAYBACK_H
#define UI_COMPONENT_PLAYBACK_H

#include "UIComponent.h"

#include "dep\include\irrKlang\irrKlang.h"

#include "script\File\GCR.h"
#include "script\File\Audio.h"

#include <sstream>
#include <iomanip>

namespace UIComponent
{
	class PlaybackComponent : public UIComponent
	{
	public:
		//To do : Make a centralised ISoundEngine to receive ISound from whenever its song ended.
	

		void DrawComponent(float width, float height) override
		{
			ImGui::BeginChild("Child");
			if (GCR::GCR::Get()->GetAudio() == NULL)
			{

				ImGui::Text("Audio file is empty!");
				ImGui::EndChild();
				return;
			}

			if (!GCR::GCR::Get()->GetAudio()->IsASafeObject())
			{
				ImGui::Text("Audio file is faulty!");
				ImGui::EndChild();
				return;
			}


			currentPlayback = GCR::GCR::Get()->GetAudio()->CurrentMillis();
			maxPlayback = GCR::GCR::Get()->GetAudio()->LengthMillis();

			bool isPaused = GCR::GCR::Get()->GetAudio()->IsPaused();

			if (GCR::GCR::Get()->GetAudio()->IsDone())
			{

				GCR::GCR::Get()->GetAudio()->Reset();
				std::cout << "Rolling back" << std::endl;

			}


	


			sliderSelected = ImGui::SliderInt(" ", &currentPlayback, 0, maxPlayback);

			ImGui::SameLine();

			std::stringstream stream;

			stream << std::setprecision(5) << GCR::GCR::Get()->GetAudio()->CurrentSeconds()
				<< " : " << GCR::GCR::Get()->GetAudio()->LengthSeconds();

			ImGui::Text(stream.str().c_str());
			
			if (sliderSelected)
			{
				std::cout << "Slider is Selected!" << std::endl;
				GCR::GCR::Get()->GetAudio()->Pause();
				GCR::GCR::Get()->GetAudio()->SetCurrent(currentPlayback);
			}


			if (ImGui::Button("Play", ImVec2(width/3 - 10 , height/3)))
			{
				if (isPaused)
				{
					GCR::GCR::Get()->GetAudio()->Play();
				}
			}

			ImGui::SameLine();

				if (ImGui::Button("Pause", ImVec2(width / 3 - 10, height/3)))
				{
					if (!isPaused)
					{
						GCR::GCR::Get()->GetAudio()->Pause();

					}
				}

				ImGui::SameLine();

				if (ImGui::Button("Reset", ImVec2(width / 3 - 10, height / 3)))
				{					
					if (!isPaused)
					{
						GCR::GCR::Get()->GetAudio()->Pause();

					}

					GCR::GCR::Get()->GetAudio()->ToStart();
					
				}


				if (ImGui::SliderFloat("Volume", &audioVolume, 0, 1))
				{
					GCR::GCR::Get()->GetAudio()->SetVolume(audioVolume);
				}


			ImGui::EndChild();

		}

		void WindowResize(float dx, float dy) override
		{


		}

	private:
		float audioVolume = 1.0f;
		bool sliderSelected;
		int currentPlayback;
		int maxPlayback;

	};

}

#endif