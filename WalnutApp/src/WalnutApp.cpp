#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"

#include "Walnut/Image.h"
#include "Walnut/GameCore/GameCore.h"

//Global Game Loop Instance Ref
GLCore GLInstance;

class ExampleLayer : public Walnut::Layer
{
public:
	virtual void OnAttach() override
	{
		m_Image = std::make_shared<Walnut::Image>("Dad.png");
	}

	virtual void OnUIRender() override
	{
		ImGui::Begin("Hello");
		GLInstance.GameLoop();
		ImGui::Text("%s", GLInstance.GLText.c_str());

		//ImGui::Image(m_Image->GetDescriptorSet(), { (float)m_Image->GetWidth(), (float)m_Image->GetHeight()});

		ImGui::End();

		// Uncomment to show ImGui Demo Window
		//ImGui::ShowDemoWindow();
	}
private:
	std::shared_ptr<Walnut::Image> m_Image;
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