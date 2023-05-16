#pragma once
#include <string>



class GLCore
{
public:
	void GameLoop();
	const char* ConvToChar(int);
	std::string GetGLText();
	std::string GLText = "Ur mom is ";
	int GLCount = 0;
};

void InitGameLoop(GLCore& GLInstanceRef);



