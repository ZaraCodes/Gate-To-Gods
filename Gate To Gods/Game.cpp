#include "Game.h"

Game::Game()
{
	messageBox = MessageBox();

	playing = true;
	player = Player(&messageBox, 20, 5, 1, 0.2f);
	player.SetPosition(Vector2(2, 5));

	level = Level(2, &messageBox);
	GridTile* startTile = level.GetTile(player.GetPosition());
	startTile->SetPlayer(&player);

	displayer = GameDisplayer(71, 19, &level, &player, &messageBox);
}

void Game::DoGameLoop()
{
	while (playing)
	{
		displayer.PrintScreen();
		DoPlayerTurn();
	}
}

void Game::DoPlayerTurn()
{
	int input = _getch();
	switch (input) {
	case 'x':
		playing = false;
		break;
	case 'w':
		player.DoAction(&level, Vector2(0, -1));
		break;
	case 'a':
		player.DoAction(&level, Vector2(-1, 0));
		break;
	case 's':
		player.DoAction(&level, Vector2(0, 1));
		break;
	case 'd':
		player.DoAction(&level, Vector2(1, 0));
		break;
	default:
		break;
	}
}

void Game::DoNPCTurn()
{

}
