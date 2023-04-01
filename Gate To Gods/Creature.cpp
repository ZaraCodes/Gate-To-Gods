#include "Creature.h"

Creature::Creature(MessageBox* messageBox, int healthPoints, int attackPower, float accuracy, float critPropability, char symbol)
{
	this->healthPoints = healthPoints;
	this->maxHealthPoints = healthPoints;
	this->attackPower = attackPower;
	this->accuracy = accuracy;
	this->critPropability = critPropability;
	this->symbol = symbol;
	this->position = Vector2();
	this->messageBox = messageBox;
}

bool Creature::Attack(Creature creature)
{
	creature.SetHealthPoints(creature.GetHealthPoints() - attackPower);
	return true;
}

int Creature::GetMaxHealthPoints()
{
	return maxHealthPoints;
}

int Creature::GetHealthPoints()
{
	return healthPoints;
}

void Creature::SetHealthPoints(int newHealthPoints)
{
	healthPoints = newHealthPoints;
}

int Creature::TakeDamage(int damage)
{
	if (healthPoints - damage <= 0) {
		SetHealthPoints(0);
		//Print Death Message
		PushDeathMessage();
		//TODO: Destruct Instance
	}
	else {
		SetHealthPoints(healthPoints - damage);
		//Print Damage
		PushTakeDamageMessage();
	}
	return 0;
}

void Creature::PushTakeDamageMessage()
{
	messageBox->InsertNewMessage("meow");
}

void Creature::PushDeathMessage()
{
}

Vector2 Creature::GetPosition()
{
	return position;
}

void Creature::SetPosition(Vector2 position)
{
	this->position = position;
}
