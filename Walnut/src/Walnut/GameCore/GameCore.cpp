#include "GameCore.h"
#include "Walnut/Application.h"
#include <iostream>
#include <string>



//Our main game loop. Currently just ticks up the counter.
void GLCore::GameLoop()
{
	GLCount = GLCount + 1;
	return;
};

//We use this to manage the rendering of multiple lines of text.
void GLCore::GameRender()
{
	for (int i = 0; i <= 23; i++) {
		std::string int_str = std::to_string(GLCount);
		GLText[i].resize(60);
		GLText[i].append(int_str);
		ImGui::TextColored(ImVec4(0, 1, 0, 0.5), "%s", GLText[i].c_str());
	}
	return;
}

// Takes an int and returns a constant char pointer.
const char* GLCore::ConvToChar(int a)
{
	std::string str = std::to_string(a);
	return(str.c_str());
};

//Private Variable Access
std::string GLCore::GetGLText()
{
	return GLText[0];
};

//Initialize our Game Loop Instance Reference, and print out a log that we have done so.
void InitGameLoop(GLCore& GLInstanceRef)
{
	GLInstanceRef = GLCore();
	std::cout << "Game Loop Instance created\n";
	return;
}