#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"

#include "Walnut/Image.h"
#include "Walnut/GameCore/GameCore.h"

//Global Game Loop Instance Ref
GLCore GLInstance;


class ExampleLayer : public Walnut::Layer
{
public:
	virtual void OnUIRender() override
	{	
		GLInstance.GameLoop(); // Tick the game loop
		GLInstance.GameRender(); // Display the text, handles both text and map
	}
};

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "Game Name";
	//Ok so we know this runs once at startup
	InitGameLoop(GLInstance);
	Walnut::Application* app = new Walnut::Application(spec);
	app->PushLayer<ExampleLayer>();
	app->SetMenubarCallback([app]()
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				app->Close();
			}
			ImGui::EndMenu();
		}
	});
	return app;
}