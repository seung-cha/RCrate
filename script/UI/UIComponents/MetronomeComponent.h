#ifndef METRONOME_H
#define METRONOME_H

#include "script\File\GCR.h"
#include "script\UI\UIComponents\UIComponent.h"
#include "script\File\Audio.h"
#include "src\imgui\imgui.h"

#include "dep\include\glad\glad.h"
#include "dep\include\glfw\glfw3.h"


namespace UIComponent
{
	class MetronomeComponent : public UIComponent
	{
	public:

		MetronomeComponent()
		{
			tick1 = new GCR::Audio("sound/tick0.ogg");
			tick1->AutoReset(true);
			tick1->SetVolume(0.5f);
			tick2 = new GCR::Audio("sound/tick1.ogg");
			tick2->AutoReset(true);
			tick2->SetVolume(0.5f);
			play = false;
			playAlong = false;

			//Temp
			bpm = 120;
			spb = 60 / (float)bpm;

		}

		void DrawComponent(float width, float height) override
		{
			if (play || playAlong)
			{

				if (playAlong && playFlag)
				{
					GCR::GCR::Get()->GetAudio()->ToStart();
					GCR::GCR::Get()->GetAudio()->Play();
					playFlag = false;
				}

				// ISSUE: While window being dragged metronome pauses while the music keeps playing.
				double elapsed = glfwGetTime() - time;
				tickTime = elapsed / spb;
				if (tickTime >= 1)
				{
					if (count++ % 4 == 3)
					{
						tick2->Play();
					}
					else
						tick1->Play();

					time = glfwGetTime();
				}

			}
			else
				time = glfwGetTime();


			ImGui::BeginChild("Child");

			if (ImGui::Button("Play") && !playAlong)
				play = !play;

			if (GCR::GCR::Get()->GetAudio() != NULL)
			{
				if (GCR::GCR::Get()->GetAudio()->IsASafeObject())
				{
					if (ImGui::Button("Play With Audio") && !play)
					{
						playAlong = !playAlong;
						playFlag = true;
					}
				}
			}


			if (ImGui::SliderInt("BPM", &bpm, 1, 500, "%d", ImGuiSliderFlags_AlwaysClamp))
			{
				spb = 60 / (float)bpm;
				std::cout << spb << std::endl;
			}


			ImGui::EndChild();




		}


		void WindowResize(float dx, float dy) override
		{

		}


	private:
		int count = 0;
		double time;
		double tickTime;
		int bpm;
		float spb;
		bool play;
		bool playAlong;
		bool playFlag;
		GCR::Audio* tick1;
		GCR::Audio* tick2;

	};
}


#endif