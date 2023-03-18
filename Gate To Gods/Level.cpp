#include "Level.h"

Level::Level()
{
	voidTile = GridTile();
	voidTile.SetWalkable(false);
	voidTile.SetSymbol(' ');


	const int limit = 10;
	tiles = new GridTile[limit * limit];
	for (int i = 0; i < limit; i++) {
		for (int j = 0; j < limit; j++) {
			Vector2 v(i, j);
			GridTile gridTile;

			if (i == 0 || j == 0 || i == limit - 1 || j == limit - 1) {
				gridTile.SetWalkable(false);
				gridTile.SetSymbol('#');
			}
			tiles[j * limit + i] = gridTile;
		}
	}
}

GridTile* Level::GetTile(Vector2 position)
{
	if (position.y >= 0 && position.y < 10 && position.x >= 0 && position.x < 10) {
		return &tiles[(int) position.y * 10 + (int) position.x];
	}
	else return &voidTile;
}
