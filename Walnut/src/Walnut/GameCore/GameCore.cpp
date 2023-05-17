#include "GameCore.h"
#include "Walnut/Application.h"
#include <iostream>
#include <string>
#include <sstream>



//Our main game loop. Currently just ticks up the counter.
void GLCore::GameLoop()
{
	GLCount = GLCount + 1;
};

//We use this to manage what we want to render.
void GLCore::GameRender()
{
	RenderText();
	RenderMap();
}

//We use this to manage the rendering of the text adventure
void GLCore::RenderText() 
{
	//This will be mega complicated, but for now, this is just an empty tab
	ImGui::Begin("Adventure");
	ImGui::Text("This is the adventure.");
	ImGui::End();
};

// We use this to manage rendering the map with multiple colors. 
void GLCore::RenderMap() 
{
	ImGui::Begin("Map");
	for (int yi = 0; yi <= 23; yi++) 
	{
		std::string CurrentLine = GLMap[yi];
		for (int xi = 0; xi <= 59; xi++)
		{
			char CurrentChar = CurrentLine.front();

			// Remove first char of line
			CurrentLine = CurrentLine.substr(1, CurrentLine.npos);

			// Extract the color code and convert to int
			char ColorChar = CurrentLine.front();
			std::stringstream ss;
			ss << ColorChar;
			int ColorID;
			ss >> ColorID;

			// Remove first char of line
			CurrentLine = CurrentLine.substr(1, CurrentLine.npos);

			// Make Color Vector with data from MapColors
			ImVec4 TempColor = ImVec4
			(
				MapColors[(ColorID * 4) + 0], 
				MapColors[(ColorID * 4) + 1], 
				MapColors[(ColorID * 4) + 2], 
				MapColors[(ColorID * 4) + 3]
			);

			// Actually output the char to the screen with the color for it
			ImGui::TextColored(TempColor, "%c", CurrentChar);

			// If we're at the end of the row, end line
			if (xi < 59)
			{
				ImGui::SameLine(0, 0);
			}
		}
	}
	ImGui::End();
}

//Initialize our Game Loop Instance Reference, and print out a log that we have done so.
void InitGameLoop(GLCore& GLInstanceRef)
{
	GLInstanceRef = GLCore();
	std::cout << "Game Loop Instance created\n";
}