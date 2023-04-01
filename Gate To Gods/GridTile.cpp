#include "GridTile.h"

GridTile::GridTile() {
	this->position = Vector2();
	this->symbol = '.';
	this->walkable = true;
	discovered = true;
	visible = true;
	monster = nullptr;
	player = nullptr;
}

GridTile::GridTile(Vector2 position, char symbol, bool walkable) {
	this->position = position;
	this->symbol = symbol;
	this->walkable = walkable;
	discovered = true;
	visible = true;
	monster = nullptr;
	player = nullptr;
}

Vector2 GridTile::GetPosition() {
	return position;
}

char GridTile::GetSymbol() {
	if (player != nullptr) return player->symbol;
	else if (monster != nullptr) {
		if (monster->GetHealthPoints() == 0) return '%';
		return monster->symbol;
	}
	return symbol;
}

void GridTile::SetSymbol(char symbol) {
	this->symbol = symbol;
}

bool GridTile::GetWalkable() {
	if (walkable) {
		if (player != nullptr) {
			return false;
		}
		if (monster != nullptr) {
			if (monster->GetHealthPoints() == 0) {
				return walkable;
			}
			return false;
		}
		return true;
	}
	return false;
}

void GridTile::SetWalkable(bool walkable) {
	this->walkable = walkable;
}

bool GridTile::GetDiscovered() {
	return discovered;
}

void GridTile::SetDiscovered(bool discovered) {
	this->discovered = discovered;
}

bool GridTile::GetVisible() {
	return visible;
}

void GridTile::SetVisible(bool visible) {
	this->visible = visible;
}

void GridTile::SetPlayer(Player* player) {
	this->player = player;
}

void GridTile::SetMonster(Monster* monster) {
	this->monster = monster;
}

Monster* GridTile::GetMonster() {
	return monster;
}

Player* GridTile::GetPlayer() {
	return player;
}
