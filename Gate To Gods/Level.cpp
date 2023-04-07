#include "Level.h"

/// <summary>empty constructor, do not use</summary>
Level::Level()
{
}

/// <summary>Destructor of the level</summary>
Level::~Level()
{
	if (voidTile != nullptr) {
		delete voidTile;
		voidTile = nullptr;
	}

	if (tiles != nullptr) {
		delete tiles;
		tiles = nullptr;
	}

	if (monsters != nullptr) {
		for (int i = 0; i < monsterAmount; i++) {
			if (monsters[i] != nullptr) {
				delete monsters[i];
				monsters[i] = nullptr;
			}
		}
		delete monsters;
		monsters = nullptr;
	}
}

/// <summary>Actual constructor</summary>
/// <param name="monsterAmount">The amount of monsters on the map</param>
/// <param name="messageBox">Reference to the message box instance</param>
Level::Level(int monsterAmount, MessageBox* messageBox)
{
	voidTile = new GridTile();
	voidTile->SetWalkable(false);
	voidTile->SetSymbol(' ');

	this->monsterAmount = monsterAmount;

	levelSize = 40;
	tiles = new GridTile[levelSize * levelSize];
	monsters = new Monster*[monsterAmount];
	
	for (int i = 0; i < levelSize; i++) {
		for (int j = 0; j < levelSize; j++) {
			Vector2 v(i, j);
			GridTile gridTile(v, ' ', false);

			if (i >= 0 && i < 5 && j >= 0 && j < 5) {
				gridTile.SetWalkable(true);
				gridTile.SetSymbol('.');
				if (i == 0 || j == 0 || (i == 4 && j != 2) || j == 4) {
					gridTile.SetSymbol('#');
					gridTile.SetWalkable(false);
				}
			}
			else if (i >= 4 && i < 15 && j >= 0 && j < 10 && !(i >= 10 && j == 0)) {
				gridTile.SetWalkable(true);
				gridTile.SetSymbol('.');
				if (i == 4 || (j == 0 && i < 10) || (j == 1 && i >= 9) || (i == 14 && j < 6) || (i == 11 && j > 7) || (i > 11 && j == 8) || (i == 5 && j == 9)) {
					gridTile.SetWalkable(false);
					gridTile.SetSymbol('#');
				}
			}
			else if (i >= 15 && i < 26 && j >= 5 && j < 10 && !(i >= 16 && j == 5)) {
				gridTile.SetWalkable(true);
				gridTile.SetSymbol('.');
				if (j < 7 || (i < 21 && j == 8) || (i == 20 && j == 7) || i == 24) {
					gridTile.SetWalkable(false);
					gridTile.SetSymbol('#');
				}
				else if (i == 22 && j == 7) {
					gridTile.SetSymbol('<');	// set locked tile here
					gridTile.SetRequireKey(true);
				}
			}
			else if (i >= 26 && i < 33 && j > 3 && j < 16) {
				gridTile.SetWalkable(true);
				gridTile.SetSymbol('.');
				if (j == 4 || i == 32 || (i == 26 && j < 7) || j == 15) {
					gridTile.SetWalkable(false);
					gridTile.SetSymbol('#');
				}
			}
			else if (i >= 5 && i < 26 && j >= 10 && j < 16) {
				gridTile.SetWalkable(true);
				gridTile.SetSymbol('.');
				if (i == 5 || (i == 11 && j < 13) || (i > 11 && j == 12 && i != 16) || (i == 25 && j < 12) || (i == 24 && j == 10) || (j == 15 && i < 21)) {
					gridTile.SetWalkable(false);
					gridTile.SetSymbol('#');
				}
			}
			else if (i >= 20 && i < 27 && j >= 16 && j < 30) {
				gridTile.SetWalkable(true);
				gridTile.SetSymbol('.');
				if (i == 20 || i == 26 || j == 29) {
					gridTile.SetWalkable(false);
					gridTile.SetSymbol('#');
				}
			}
			gridTile.SetPosition(v);
			tiles[j * levelSize + i] = gridTile;
		}
	}

	Vector2 pos(2, 2);
	monsters[0] = new Monster(messageBox, 10, 4, 1, 0, "archeologist");
	monsters[0]->position = pos;
	monsters[0]->SetHasKey(true);
	GridTile* tile = GetTile(pos);
	tile->SetMonster(monsters[0]);
}

/// <summary>Gets a tile</summary>
/// <param name="position">Position to return a tile from</param>
/// <returns>The tile at the given position or a default tile</returns>
GridTile* Level::GetTile(Vector2 position)
{
	if (position.y >= 0 && position.y < levelSize && position.x >= 0 && position.x < levelSize) {
		return &tiles[(int) position.y * levelSize + (int) position.x];
	}
	else return voidTile;
}

/// <summary>Gets the monsters array</summary>
/// <returns>Monster array</returns>
Monster** Level::GetMonsters()
{
	return monsters;
}
