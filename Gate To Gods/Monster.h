#pragma once
#include "Creature.h"
#include "MessageBox.h"

class Monster : public Creature
{
public:
	Monster();
	Monster(MessageBox* messageBox, int healthpoints, int attackPower, float accuracy, float critPropability);

	virtual void PushTakeDamageMessage();
	virtual void PushDeathMessage();
};

