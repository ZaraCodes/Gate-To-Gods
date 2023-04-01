#include "Monster.h"

Monster::Monster() : Creature(nullptr, 0, 0, 0, 0, 's')
{
}

Monster::Monster(MessageBox* messageBox, int healthpoints, int attackPower, float accuracy, float critPropability) : Creature(messageBox, healthpoints, attackPower, accuracy, critPropability, 'p')
{
}

void Monster::PushTakeDamageMessage(int damage)
{
	messageBox->InsertNewMessage("Oh nyo! I took \x1b[0;91m" + std::to_string(damage) + "\x1b[0m damage! I hav \x1b[0;91m" + std::to_string(healthPoints) + "\x1b[0m HP left.");
}

void Monster::PushDeathMessage()
{
	messageBox->InsertNewMessage("Me ded :(");
}
