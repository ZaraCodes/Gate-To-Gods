#include "Monster.h"

/// <summary>Empty constructor, do not use</summary>
Monster::Monster() : Creature(nullptr, 0, 0, 0, 0, 's')
{
}

/// <summary>
/// Constructor of the monster class
/// </summary>
/// <param name="messageBox">Reference to the messagebox</param>
/// <param name="healthpoints">The healthpoints for this monster</param>
/// <param name="attackPower">The attack power of this monster</param>
/// <param name="accuracy">Propability of hitting the player</param>
/// <param name="critPropability">Propability of critical hits</param>
/// <param name="name">Name of the monster</param>
Monster::Monster(MessageBox* messageBox, int healthpoints, int attackPower, float accuracy, float critPropability, std::string name) : Creature(messageBox, healthpoints, attackPower, accuracy, critPropability, 'p')
{
	this->name = name;
}

/// <summary>
/// Adds a damage message to the messagebox
/// </summary>
/// <param name="damage">the damage points the monster receiced</param>
void Monster::PushTakeDamageMessage(int damage)
{
	messageBox->InsertNewMessage("You attack the \x1b[0;92m" + name + "\x1b[0m with \x1b[0;91m" + std::to_string(damage) + "\x1b[0m damage! They have \x1b[0;91m" + std::to_string(healthPoints) + "\x1b[0m HP left.");
}

/// <summary>
/// Pushes a death message for the monster to the messagebox
/// </summary>
void Monster::PushDeathMessage()
{
	messageBox->InsertNewMessage("The \x1b[0;92m" + name + "\x1b[0m collapsed on the ground.");
}

/// <summary>
/// Moves the monster to the next specified tile
/// </summary>
/// <param name="nextTile"></param>
/// <param name="currentTile"></param>
void Monster::Move(GridTile* nextTile, GridTile* currentTile)
{
	if (nextTile->GetWalkable()) {
		currentTile->SetMonster(nullptr);
		nextTile->SetMonster(this);
		SetPosition(nextTile->GetPosition());
	}
}
