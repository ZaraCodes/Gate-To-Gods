#include "GameDisplayer.h"

GameDisplayer::GameDisplayer()
{

}

GameDisplayer::GameDisplayer(int x, int y, Level* level, Player* player)
{
	screenSize = Vector2((float) x, (float) y);

	this->level = level;
	this->player = player;

	screenSeparator = "";
	for (int i = 0; i < x; i++) {
		screenSeparator += "-";
	}
}

void GameDisplayer::PrintScreen()
{
	PrintHealth();
	PrintSeparator();
	PrintLevel();
	PrintSeparator();
}

void GameDisplayer::PrintHealth()
{
	std::cout << "\x1b[0;0HHP: \x1b[0;91m" << player->GetHealthPoints() << '/' << player->GetMaxHealthPoints() << "\x1b[0m" << std::endl;
}

void GameDisplayer::PrintSeparator()
{
	std::cout << screenSeparator << std::endl;
}

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
