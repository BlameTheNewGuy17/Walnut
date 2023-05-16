#pragma once
#include <string>



class GLCore
{
public:
	void GameLoop();

	void GameRender();

	const char* ConvToChar(int);

	std::string GetGLText();


private:
	std::string GLText[24] = 
	{
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000"
	};

	int GLCount = 0;
};

void InitGameLoop(GLCore& GLInstanceRef);