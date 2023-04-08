#include "Game.h"

/// <summary>Initializes the game</summary>
Game::Game()
{
	messageBox = new MessageBox();

	playing = true;
	player = new Player(messageBox, 20, 5, 1, 0.2f);
	player->SetPosition(Vector2(23, 26));

	level = new Level(4, messageBox);
	GridTile* startTile = level->GetTile(player->GetPosition());
	startTile->SetPlayer(player);

	displayer = new GameDisplayer(71, 19, level, player, messageBox);
}

/// <summary>Destructs the game</summary>
Game::~Game()
{
	if (displayer != nullptr) {
		delete displayer;
		displayer = nullptr;
	}
	if (level != nullptr) {
		delete level;
		level = nullptr;
	}
	if (player != nullptr) {
		delete player;
		player = nullptr;
	}
	if (messageBox != nullptr) {
		delete messageBox;
		messageBox = nullptr;
	}
}

/// <summary>Executes the main game loop</summary>
void Game::DoGameLoop()
{
	std::cout << "\x1b[2J";
	while (playing)
	{
		displayer->PrintScreen();
		DoPlayerTurn();
		if (playing) 
			DoNPCTurn();
		else {
			displayer->PrintScreen();
			_getch();
		}
	}
}

/// <summary>Gets the player's input and executes that action</summary>
void Game::DoPlayerTurn()
{
	int input = _getch();
	switch (input) {
	case 'x':
		playing = false;
		messageBox->InsertNewMessage("You quit the game...");
		break;
	case 'w':
		player->DoAction(level, Vector2(0, -1), &playing);
		break;
	case 'a':
		player->DoAction(level, Vector2(-1, 0), &playing);
		break;
	case 's':
		player->DoAction(level, Vector2(0, 1), &playing);
		break;
	case 'd':
		player->DoAction(level, Vector2(1, 0), &playing);
		break;
	case 'e':
		player->PickUp(level->GetTile(player->GetPosition()));
		break;
	case 'q':
		player->Drop(level->GetTile(player->GetPosition()));
		break;
	default:
		break;
	}
}

/// <summary>Loops through every npc and executes an action for each of them</summary>
void Game::DoNPCTurn()
{
	Monster* levelMonsters = level->GetMonsters();
	for (int i = 0; i < level->GetMonsterAmount(); i++) {
		Monster* monster = &levelMonsters[i];
		if (monster == nullptr) continue;
		if (monster->GetHealthPoints() == 0) {
			if (monster->GetHasKey()) {
				monster->SetHasKey(false);
				GridTile* currentTile = level->GetTile(monster->position);
				currentTile->SetHasKey(true);
			}
			continue;
		}

		if (level->GetTile(monster->position + Vector2(1, 0))->GetPlayer() == nullptr) {
			if (level->GetTile(monster->position + Vector2(0, 1))->GetPlayer() == nullptr) {
				if (level->GetTile(monster->position + Vector2(-1, 0))->GetPlayer() == nullptr) {
					if (level->GetTile(monster->position + Vector2(0, -1))->GetPlayer() == nullptr) {
						// follow the player
						Vector2 diff = monster->position - player->position;
						GridTile* currentTile = level->GetTile(monster->position);
						if (diff.GetMagnitude() < 5) {
							Vector2 newPosition = monster->position + Vector2();

							if (diff.x > 0) {
								newPosition.x -= 1;
							}
							else if (diff.x < 0) {
								newPosition.x += 1;
							}
							else if (diff.y > 0) {
								newPosition.y -= 1;
							}
							else if (diff.y < 0) {
								newPosition.y += 1;
							}
							else continue;
							
							GridTile* nextTile = level->GetTile(newPosition);

							// move?
							monster->Move(nextTile, currentTile);
						}
						continue;
					}
				}
			}
		}
		monster->Attack(player);
		if (player->GetHealthPoints() == 0) {
			playing = false;
			displayer->PrintScreen();
			int input = _getch();
		}
	}
}
