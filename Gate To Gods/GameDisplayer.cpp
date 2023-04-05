#include "GameDisplayer.h"

/// <summary>Empty constructor, do not use</summary>
GameDisplayer::GameDisplayer() { }

/// <summary>Destructor of the game displayer class</summary>
GameDisplayer::~GameDisplayer() { }

/// <summary>Initializes the game displayer</summary>
/// <param name="x">width of the visible area</param>
/// <param name="y">height of the visible area</param>
/// <param name="level">reference to the level</param>
/// <param name="player">reference to the player</param>
/// <param name="messageBox">reference to the messagebox</param>
GameDisplayer::GameDisplayer(int x, int y, Level* level, Player* player, MessageBox* messageBox)
{
	screenSize = Vector2((float) x, (float) y);

	this->level = level;
	this->player = player;
	this->messageBox = messageBox;

	screenSeparator = "";
	for (int i = 0; i < x; i++) {
		screenSeparator += "-";
	}
}

/// <summary>Prints the current game state into the console</summary>
void GameDisplayer::PrintScreen()
{
	PrintHealth();
	PrintSeparator();
	PrintLevel();
	PrintSeparator();
	PrintTileContent();
	PrintMessages();
}

/// <summary>Prints the health line</summary>
void GameDisplayer::PrintHealth()
{
	std::cout << "\x1b[0;0HHP: \x1b[0;91m" << player->GetHealthPoints() << '/' << player->GetMaxHealthPoints() << "\x1b[0m   " << std::endl;
}

/// <summary>Prints the separation line</summary>
void GameDisplayer::PrintSeparator()
{
	std::cout << screenSeparator << std::endl;
}

/// <summary>Prints the visible playground</summary>
void GameDisplayer::PrintLevel()
{
	for (int y = player->position.y - ((screenSize.y - 1) / 2); y < player->position.y + ((screenSize.y) / 2); y++) {
		for (int x = player->position.x - ((screenSize.x - 1) / 2); x < player->position.x + ((screenSize.x) / 2); x++) {
			Vector2 position(x, y);
			GridTile* tile = level->GetTile(position);

			char symbol = tile->GetSymbol();
			std::string color = "";

			if (tile->GetVisible()) {
				color = "\x1b[0m";
			}
			else if (tile->GetDiscovered()) {
				color = "\x1b[0;90m";
			}

			std::cout << color << symbol;
		}
		std::cout << std::endl;
	}
}

/// <summary>Prints the messagebox content</summary>
void GameDisplayer::PrintMessages()
{
	for (int i = 0; i < messageBox->maxAmount; i++) {
		std::cout << "\x1b[2K" << messageBox->GetMessage(i) << std::endl;
	}
}

/// <summary>Prints the content of a tile if necessary</summary>
void GameDisplayer::PrintTileContent()
{
	GridTile* tile = level->GetTile(player->position);
	Monster* tileMonster = tile->GetMonster();
	if (tileMonster != nullptr) {
		std::cout << "\x1b[1A[" << tileMonster->name << "][empty]" << std::endl;
	}
}
