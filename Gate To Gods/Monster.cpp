#include "Monster.h"

Monster::Monster() : Creature(nullptr, 0, 0, 0, 0, 's')
{
}

Monster::Monster(MessageBox* messageBox, int healthpoints, int attackPower, float accuracy, float critPropability) : Creature(messageBox, healthpoints, attackPower, accuracy, critPropability, 'p')
{
}

void Monster::PushTakeDamageMessage()
{
	messageBox->InsertNewMessage("Oh nyo! I took damage!");
}

void Monster::PushDeathMessage()
{
	messageBox->InsertNewMessage("Me ded :(");
}
