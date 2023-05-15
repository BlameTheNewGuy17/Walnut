#pragma once




class GameLoopCore
{
public:
	void GameLoop();
private:
	int GameLoopCount = 0;
	char MyGameString1[20]= "This is a string";

};

void InitGameLoop(GameLoopCore& GLInstanceRef);




