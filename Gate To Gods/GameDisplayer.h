#pragma once
#include "Player.h"
#include "Level.h"
#include "Vector2.h"
#include "MessageBox.h"
#include <iostream>

class GameDisplayer
{
public:
	Player* player;
	Level* level;
	MessageBox* messageBox;

	Vector2 screenSize;

	//Methods
	GameDisplayer();
	~GameDisplayer();
	GameDisplayer(int x, int y, Level* level, Player* player, MessageBox* messageBox);
	void PrintScreen();

private:
	std::string screenSeparator;

	void PrintHealth();
	void PrintSeparator();
	void PrintLevel();
	void PrintMessages();
	void PrintTileContent();

	std::string GetTileItem(GridTile* tile);
};

