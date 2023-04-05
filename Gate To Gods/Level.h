#pragma once
#include <string>
#include "Vector2.h"
#include "GridTile.h"

class GridTile;
class Monster;

class Level
{
private:
    int monsterAmount;
    GridTile* tiles;
    GridTile* voidTile;
   
    Monster** monsters;

public:
    Level();
    ~Level();
    Level(int monsterAmount, MessageBox* messageBox);

    GridTile* GetTile(Vector2 position);
    Monster** GetMonsters();
};
