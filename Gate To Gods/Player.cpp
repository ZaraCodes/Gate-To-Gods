#include "Player.h"

/// <summary>Empty Constructor, do not use :)</summary>
Player::Player() : Creature(nullptr, 0, 0, 0, 0, 's') { }

/// <summary>Destructor of the player class</summary>
Player::~Player() { }

/// <summary>Constructor for the player class</summary>
/// <param name="messageBox">Reference to the messagebox instance</param>
/// <param name="healthpoints">The player's health points</param>
/// <param name="attackPower">The attack points of the player</param>
/// <param name="accuracy">The propability of hitting an attack</param>
/// <param name="critPropability">The propability of landing a critical hit</param>
Player::Player(MessageBox* messageBox, int healthpoints, int attackPower, float accuracy, float critPropability) : Creature(messageBox, healthpoints, attackPower, accuracy, critPropability, '@') { }

/// <summary>Executes an action for the player</summary>
/// <param name="level">Reference to the level</param>
/// <param name="direction">The direction in which an action will get executed</param>
void Player::DoAction(Level* level, Vector2 direction)
{
	GridTile* nextTile = level->GetTile(position + direction);
	GridTile* currentTile = level->GetTile(position);
	if (nextTile->GetWalkable()) {
		currentTile->SetPlayer(nullptr);
		nextTile->SetPlayer(this);
		position = position + direction;
	} 
	else {
		Monster* monster = nextTile->GetMonster();
		if (monster != nullptr) {
			monster->TakeDamage(attackPower);
		}
		else {
			messageBox->InsertNewMessage("U hit a wall");
		}
	}
}

/// <summary>Pushes a damage message for the player to the messagebox</summary>
/// <param name="damage">The amount of damage taken</param>
void Player::PushTakeDamageMessage(int damage)
{
	messageBox->InsertNewMessage("You take \x1b[0;91m" + std::to_string(damage) + "\x1b[0m damage. You have \x1b[0;91m" + std::to_string(healthPoints) + "\x1b[0m HP left.");
}

/// <summary>Pushes a death message for the player to the messagebox</summary>
void Player::PushDeathMessage()
{
	messageBox->InsertNewMessage("\x1b[0;91mYou got overpowered.\x1b[0m Press any key to exit.");
}
