#include "Monster.h"

Monster::Monster() : Creature(nullptr, 0, 0, 0, 0, 's')
{
}

Monster::Monster(MessageBox* messageBox, int healthpoints, int attackPower, float accuracy, float critPropability, std::string name) : Creature(messageBox, healthpoints, attackPower, accuracy, critPropability, 'p')
{
	this->name = name;
}

void Monster::PushTakeDamageMessage(int damage)
{
	messageBox->InsertNewMessage("You attack the \x1b[0;92m" + name + "\x1b[0m with \x1b[0;91m" + std::to_string(damage) + "\x1b[0m damage! They have \x1b[0;91m" + std::to_string(healthPoints) + "\x1b[0m HP left.");
}

void Monster::PushDeathMessage()
{
	messageBox->InsertNewMessage("The \x1b[0;92m" + name + "\x1b[0m collapsed on the ground.");
}
