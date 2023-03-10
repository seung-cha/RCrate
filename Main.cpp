#include "src\imgui\imgui.h"
#include "src\imgui\imgui_impl_glfw.h"
#include "src\imgui\imgui_impl_opengl3.h"

#include <iostream>
#include "dep\include\glad\glad.h"
#include "dep\include\glfw\glfw3.h"

#include "dep\include\irrKlang\irrKlang.h"

#include "script\UI\UI.h"
#include "script\UI\MenuBar.h"
#include <vector>

#include "script\UI\UIComponents\PlaybackComponent.h"
#include "script\UI\UIComponents\MetronomeComponent.h"
#include "script\UI\UIComponents\FileInfoComponent.h"
#include "script\UI\UIComponents\AudioInfoComponent.h"

#include "script\File\GCR.h"





void OnWindowSizeChanged(GLFWwindow* window, int width, int height);
int screenWidth = 1920;
int screenHeight = 1080;

float width_half = screenWidth / (float)2;
float height_half = screenHeight / (float)2;

float width_quarter = width_half / 2;
float height_quarter = height_half / 2;

std::vector<UI::UI> UIs;


int main()
{

	std::cout << "hello world!" << std::endl;
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "Hello World", NULL, NULL);

	if (!window)
	{
		std::cout << "An error occurred!" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//glViewport(1920 / 4., 1080 / 4., 1920 / 4., 1080 / 4.);

	glfwSetWindowSizeCallback(window, OnWindowSizeChanged);

	//IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	// Setup Platform/Renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");
	// Setup Dear ImGui style
	ImGui::StyleColorsDark();

	//GCR::GCR::Get()->TempSetAudio("exclude/test.mp3");
	
	UIs.push_back
	(
		UI::UI("Track Settings",
		ImVec2(0, height_half),
		ImVec2(width_quarter/2, height_half),
		ImVec2(0, 0.5f)
		)
	);

	UIs.push_back
	(
		UI::UI("Playback Options",
			ImVec2(width_half, screenHeight),
			ImVec2(width_quarter, height_quarter/2),
			ImVec2(0.5f, 1),
			new UIComponent::PlaybackComponent
		)
	);

	UIs.push_back
	(
		UI::UI("File Info",
			ImVec2(screenWidth, height_half),
			ImVec2(width_quarter / 2, height_quarter),
			ImVec2(1, 0.5f),
			new UIComponent::FileInfoComponent
		)
	);

	
	UIs.push_back
	(
		UI::UI("Audio Info",
			ImVec2(screenWidth, height_half + height_quarter),
			ImVec2(width_quarter / 2, height_quarter),
			ImVec2(1, 0.5f),
			new UIComponent::AudioInfoComponent
		)
	);

	UIs.push_back
	(
		UI::UI("Metronome",
			ImVec2(screenWidth, 20),
			ImVec2(width_quarter, height_quarter / 2),
			ImVec2(1, 0),
			new UIComponent::MetronomeComponent
		)
	);



	
	UI::MenuBar menu;

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		menu.Render();

		for (int i = 0; i < UIs.size(); i++)
		{
			UIs[i].Render();

		}

		// Render dear imgui into screen
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());




		if(glfwGetKey(window, GLFW_KEY_ESCAPE))
		{
			glfwSetWindowShouldClose(window, true);
		}


		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	return 0;
}


void OnWindowSizeChanged(GLFWwindow* window, int width, int height)
{
	
	glfwSetWindowSize(window, width, height);


	float xRatio = width / (float)screenWidth;
	float yRatio = height / (float)screenHeight;

	screenWidth = width;
	screenHeight = height;

	for (int i = 0; i < UIs.size(); i++)
	{
		UIs[i].WindowResize(xRatio, yRatio);
	}

}