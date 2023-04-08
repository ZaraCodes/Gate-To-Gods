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
	this->hasKey = false;
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

/// <summary>Sets the creature's health points</summary>
/// <param name="newHealthPoints">The new hp</param>
void Creature::SetHealthPoints(int newHealthPoints)
{
	healthPoints = newHealthPoints;
}

/// <summary>Applies damage to this creature</summary>
/// <param name="damage">the amount of hp lost</param>
/// <returns>unused value</returns>
int Creature::TakeDamage(int damage)
{
	if (healthPoints - damage <= 0) {
		damage = healthPoints;
		SetHealthPoints(0);
		PushTakeDamageMessage(damage);
		//Print Death Message
		PushDeathMessage();
		return 1;
	}
	else {
		SetHealthPoints(healthPoints - damage);
		//Print Damage
		PushTakeDamageMessage(damage);
	}
	return 0;
}

/// <summary>Pushes the take damage message to the messagebox</summary>
/// <param name="damage">the amount of damage</param>
void Creature::PushTakeDamageMessage(int damage)
{
}

/// <summary>Pushes the death message to the messagebox</summary>
void Creature::PushDeathMessage()
{
}

/// <summary>Returns the creature's position</summary>
/// <returns>The creature's position</returns>
Vector2 Creature::GetPosition()
{
	return position;
}

/// <summary>Sets the creature's position</summary>
/// <param name="position">The new position</param>
void Creature::SetPosition(Vector2 position)
{
	this->position = position;
}

/// <summary>Returns if the creature currently has a key</summary>
/// <returns>true if the creature has a key</returns>
bool Creature::GetHasKey()
{
	return hasKey;
}

/// <summary>Sets if the creature has a key</summary>
/// <param name="value">boolean that sets if the creature will have a key</param>
void Creature::SetHasKey(bool value)
{
	hasKey = value;
}
