#include "GameCore.h"
#include <iostream>



void InitGameLoop(GameLoopCore& GLInstanceRef)
{
	GLInstanceRef = GameLoopCore();
	std::cout << "Game Loop Instance created\n";
	return;
};

void GameLoopCore::GameLoop() 
{
	GameLoopCount = GameLoopCount + 1;
	return;
};

