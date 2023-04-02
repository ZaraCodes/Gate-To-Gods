#include "Level.h"

Level::Level()
{
}

Level::Level(int monsterAmount, MessageBox* messageBox)
{
	voidTile = new GridTile();
	voidTile->SetWalkable(false);
	voidTile->SetSymbol(' ');


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
	GridTile* tile = GetTile(pos);
	tile->SetMonster(monsters[0]);
}

GridTile* Level::GetTile(Vector2 position)
{
	if (position.y >= 0 && position.y < 10 && position.x >= 0 && position.x < 10) {
		return &tiles[(int) position.y * 10 + (int) position.x];
	}
	else return voidTile;
}

Monster** Level::GetMonsters()
{
	return monsters;
}
