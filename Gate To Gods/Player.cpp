#include "Player.h"


Player::Player() : Creature(0, 0, 0, 0, 's')
{
}

Player::Player(int healthpoints, int attackPower, float accuracy, float critPropability) : Creature(healthpoints, attackPower, accuracy, critPropability, '@')
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
}
