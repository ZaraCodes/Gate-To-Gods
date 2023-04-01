#include "Player.h"


Player::Player() : Creature(nullptr, 0, 0, 0, 0, 's')
{
}

Player::Player(MessageBox* messageBox, int healthpoints, int attackPower, float accuracy, float critPropability) : Creature(messageBox, healthpoints, attackPower, accuracy, critPropability, '@')
{

}

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

void Player::PushTakeDamageMessage()
{
}

void Player::PushDeathMessage()
{
}
