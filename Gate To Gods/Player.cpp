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
		else if (nextTile->GetRequiresKey()) {
			if (GetHasKey()) {
				messageBox->InsertNewMessage("u did it widepeepoHappy");
			}
			else {
				messageBox->InsertNewMessage("The entrance to the temple is locked. You have to find a key first.");
			}
		}
	}
}

/// <summary>Picks up an item if there is one on the tile</summary>
/// <param name="tile">Reference to the tile that is being interacted with</param>
void Player::PickUp(GridTile* tile)
{
	if (tile != nullptr) {
		if (tile->GetHasKey()) {
			if (GetHasKey()) {
				messageBox->InsertNewMessage("Your inventory is full, you can't pick up any more keys.");
			}
			else {
				SetHasKey(true);
				tile->SetHasKey(false);
				messageBox->InsertNewMessage("You picked up a key.");
			}
		}
		else {
			messageBox->InsertNewMessage("There is nothing to pick up...");
		}
	}
}


void Player::Drop(GridTile* tile)
{
	if (tile != nullptr) {
		if (!tile->GetHasKey() && GetHasKey()) {
			SetHasKey(false);
			tile->SetHasKey(true);
			messageBox->InsertNewMessage("You dropped a key.");
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
