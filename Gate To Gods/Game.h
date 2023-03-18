#pragma once
#include "Player.h"
#include "Level.h"
#include "GameDisplayer.h"
class Game
{
private:
	Player player;
	Level level;
	GameDisplayer displayer;

	bool playing;

	void DoPlayerTurn();
	void DoNPCTurn();

public:
	Game();
	void DoGameLoop();
};

