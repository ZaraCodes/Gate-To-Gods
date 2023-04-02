#pragma once
#include "Creature.h"
#include "MessageBox.h"
#include "Level.h"
#include "GridTile.h"

class GridTile;

class Monster : public Creature
{
public:
	std::string name;

	Monster();
	Monster(MessageBox* messageBox, int healthpoints, int attackPower, float accuracy, float critPropability, std::string name);

	virtual void PushTakeDamageMessage(int damage);
	virtual void PushDeathMessage();

	void Move(GridTile* nextTile, GridTile* currentTile);
};

