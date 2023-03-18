#pragma once
#include <string>
#include "Vector2.h"
#include "GridTile.h"

class Level
{
private:
	// std::map<std::string, GridTile> tiles;
	GridTile* tiles;
	GridTile voidTile;

public:
	Level();

	GridTile* GetTile(Vector2 position);
};
