#pragma once
#include <conio.h>
#include "Player.h"
#include "Level.h"
#include "GameDisplayer.h"
class Game
{
private:
	Player* player;
	Level* level;
	GameDisplayer* displayer;
	MessageBox* messageBox;

	bool playing;

	void DoPlayerTurn();
	void DoNPCTurn();

public:
	Game();
	~Game();
	void DoGameLoop();
};

