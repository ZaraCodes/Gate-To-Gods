#pragma once
#include "Monster.h"
#include "Player.h"
#include "Vector2.h"

class Player;
class Monster;

class GridTile
{
private:
    Vector2 position;
    char symbol;
    bool walkable;
    bool discovered;
    bool visible;
    bool hasKey;
    Monster* monster;
    Player* player;

public:
    GridTile();
    GridTile(Vector2 position, char symbol, bool walkable);
    Vector2 GetPosition();
    void SetPosition(Vector2 position);
    char GetSymbol();
    void SetSymbol(char symbol);
    bool GetWalkable();
    void SetWalkable(bool walkable);
    bool GetDiscovered();
    void SetDiscovered(bool discovered);
    bool GetVisible();
    void SetVisible(bool visible);
    void SetPlayer(Player* player);
    void SetMonster(Monster* monster);
    Monster* GetMonster();
    Player* GetPlayer();
    bool GetHasKey();
    void SetHasKey(bool value);
};