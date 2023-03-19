#pragma once
#include <string>
#include "Vector2.h"
#include "GridTile.h"

class GridTile;

class Level
{
private:
    // std::map<std::string, GridTile> tiles;
    GridTile* tiles;
    GridTile* voidTile;

    Monster** monsters;

public:
    Level();
    Level(int monsterAmount, MessageBox* messageBox);

    GridTile* GetTile(Vector2 position);
};
