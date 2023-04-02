#include "Game.h"

Game::Game()
{
	messageBox = MessageBox();

	playing = true;
	player = Player(&messageBox, 20, 5, 1, 0.2f);
	player.SetPosition(Vector2(2, 5));

	level = Level(1, &messageBox);
	GridTile* startTile = level.GetTile(player.GetPosition());
	startTile->SetPlayer(&player);

	displayer = GameDisplayer(71, 19, &level, &player, &messageBox);
}


/// <summary>Executes the main game loop</summary>
void Game::DoGameLoop()
{
	while (playing)
	{
		displayer.PrintScreen();
		DoPlayerTurn();
		DoNPCTurn();
	}
}

/// <summary>Gets the player's input and executes that action</summary>
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

/// <summary>Loops through every npc and executes an action for each of them</summary>
void Game::DoNPCTurn()
{
	Monster** levelMonsters = level.GetMonsters();
	for (int i = 0; i < 1; i++) {
		Monster* monster = levelMonsters[i];
		if (monster == nullptr) continue;
		if (monster->GetHealthPoints() == 0) continue;

		Player* tilePlayer = level.GetTile(monster->position + Vector2(1, 0))->GetPlayer();
		if (tilePlayer == nullptr) {
			tilePlayer = level.GetTile(monster->position + Vector2(0, 1))->GetPlayer();
			if (tilePlayer == nullptr) {
				tilePlayer = level.GetTile(monster->position + Vector2(-1, 0))->GetPlayer();
				if (tilePlayer == nullptr) {
					tilePlayer = level.GetTile(monster->position + Vector2(0, -1))->GetPlayer();
					
					if (tilePlayer == nullptr) {
						// follow the player
						Vector2 diff = monster->position - player.position;
						GridTile* currentTile = level.GetTile(monster->position);
						if (diff.GetMagnitude() < 5) {
							Vector2 newPosition = monster->position + Vector2(1, 0);
							GridTile* nextTile = level.GetTile(newPosition);

							// move?
							monster->Move(nextTile, currentTile);
						}
						continue;
					}
				}
			}
		}
		monster->Attack(&player);
	}
}
