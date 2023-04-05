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

	const int limit = 10;
	tiles = new GridTile[limit * limit];
	monsters = new Monster*[monsterAmount];
	
	for (int i = 0; i < limit; i++) {
		for (int j = 0; j < limit; j++) {
			Vector2 v(i, j);
			GridTile gridTile;

			if (i == 0 || j == 0 || i == limit - 1 || j == limit - 1) {
				gridTile.SetWalkable(false);
				gridTile.SetSymbol('#');
			}
			gridTile.SetPosition(v);
			tiles[j * limit + i] = gridTile;
		}
	}

	Vector2 pos(2, 2);
	monsters[0] = new Monster(messageBox, 10, 4, 1, 0, "archeologist");
	monsters[0]->position = pos;
	// monsters[0]->SetHasKey(true);
	GridTile* tile = GetTile(pos);
	tile->SetMonster(monsters[0]);
}

/// <summary>Gets a tile</summary>
/// <param name="position">Position to return a tile from</param>
/// <returns>The tile at the given position or a default tile</returns>
GridTile* Level::GetTile(Vector2 position)
{
	if (position.y >= 0 && position.y < 10 && position.x >= 0 && position.x < 10) {
		return &tiles[(int) position.y * 10 + (int) position.x];
	}
	else return voidTile;
}

/// <summary>Gets the monsters array</summary>
/// <returns>Monster array</returns>
Monster** Level::GetMonsters()
{
	return monsters;
}
