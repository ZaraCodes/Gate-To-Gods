#pragma once
#include "Creature.h"
#include "Vector2.h"
#include "Level.h"
#include "GridTile.h"

class Level;
class GridTile;

class Player : public Creature
{
public:
    Player();
    ~Player();
    Player(MessageBox* messageBox, int healthpoints, int attackPower, float accuracy, float critPropability);
    void DoAction(Level* level, Vector2 direction, bool* isPlaying);
    void PickUp(GridTile* tile);
    void Drop(GridTile* tile);

    virtual void PushTakeDamageMessage(int damage);
    virtual void PushDeathMessage();
};