#include "Creature.h"

/// <summary>General constructor for all creatures</summary>
/// <param name="messageBox">Reference to the messagebox for pushing messages</param>
/// <param name="healthPoints">Health Points of the creature</param>
/// <param name="attackPower">Attack Points of the creature</param>
/// <param name="accuracy">Propability of hitting the target</param>
/// <param name="critPropability">Propability of landing a critical hit</param>
/// <param name="symbol">The symbol that's shown on the tile this creature is on</param>
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

/// <summary>Attacks a creature</summary>
/// <param name="creature">The creature to attack</param>
/// <returns>unused value</returns>
bool Creature::Attack(Creature* creature)
{
	creature->TakeDamage(attackPower);
	return true;
}

/// <summary>Gets the max amount of hp for the creature</summary>
/// <returns>max hp</returns>
int Creature::GetMaxHealthPoints()
{
	return maxHealthPoints;
}

/// <summary>Get the current amount of hp for the creature</summary>
/// <returns>the current hp</returns>
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
		damage = healthPoints;
		SetHealthPoints(0);
		PushTakeDamageMessage(damage);
		//Print Death Message
		PushDeathMessage();
		//TODO: Destruct Instance
	}
	else {
		SetHealthPoints(healthPoints - damage);
		//Print Damage
		PushTakeDamageMessage(damage);
	}
	return 0;
}

void Creature::PushTakeDamageMessage(int damage)
{
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
