#pragma once




class GLCore
{
public:
	void GameLoop();
	const char* ConvToChar(int);
private:
	int GameLoopCount = 0;
};

void InitGameLoop(GLCore& GLInstanceRef);



