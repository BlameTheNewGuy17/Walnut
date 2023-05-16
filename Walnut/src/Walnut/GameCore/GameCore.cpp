#include "GameCore.h"
#include <iostream>
#include <string>



//Our main game loop. Currently just ticks up the counter.
void GLCore::GameLoop()
{
	GLCount = GLCount + 1;
	std::string int_str = std::to_string(GLCount);
	GLText.resize(10);
	GLText.append(int_str);
	return;
};

// Takes an int and returns a constant char pointer.
const char* GLCore::ConvToChar(int a)
{
	std::string str = std::to_string(a);
	return(str.c_str());
};

std::string GLCore::GetGLText()
{
	return GLText;
};



//Initialize our Game Loop Instance Reference, and print out a log that we have done so.
void InitGameLoop(GLCore& GLInstanceRef)
{
	GLInstanceRef = GLCore();
	std::cout << "Game Loop Instance created\n";
	return;
}