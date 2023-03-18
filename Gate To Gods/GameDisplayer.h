#pragma once
#include "Player.h"
#include "Level.h"
#include "Vector2.h"
#include <iostream>

class GameDisplayer
{
public:
	Player* player;
	Level* level;

	Vector2 screenSize;

	//Methods
	GameDisplayer();
	GameDisplayer(int x, int y, Level* level, Player* player);
	void PrintScreen();

private:
	std::string screenSeparator;

	void PrintHealth();
	void PrintSeparator();
	void PrintLevel();
};

