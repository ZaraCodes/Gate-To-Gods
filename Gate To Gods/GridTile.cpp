#include "GridTile.h"

/// <summary>Constructor for a default tile</summary>
GridTile::GridTile() {
	this->position = Vector2();
	this->symbol = '.';
	this->walkable = true;
	discovered = true;
	visible = true;
	monster = nullptr;
	player = nullptr;
}

/// <summary>Constructor for a grid tile</summary>
/// <param name="position">Position in the level</param>
/// <param name="symbol">Symbol that gets displayed</param>
/// <param name="walkable">Can monsters and the player walk here?</param>
GridTile::GridTile(Vector2 position, char symbol, bool walkable) {
	this->position = position;
	this->symbol = symbol;
	this->walkable = walkable;
	discovered = true;
	visible = true;
	monster = nullptr;
	player = nullptr;
}

/// <summary>Returns the position of the tile</summary>
/// <returns></returns>
Vector2 GridTile::GetPosition() {
	return position;
}

/// <summary>Sets the position of the tile</summary>
/// <param name="position">The position</param>
void GridTile::SetPosition(Vector2 position)
{
	this->position = position;
}

/// <summary>Gets the symbol to display</summary>
/// <returns></returns>
char GridTile::GetSymbol() {
	if (player != nullptr) return player->symbol;
	else if (monster != nullptr) {
		if (monster->GetHealthPoints() == 0) return '%';
		return monster->symbol;
	}
	return symbol;
}

/// <summary>Sets the tile symbol</summary>
/// <param name="symbol">The symbol that should be displayed</param>
void GridTile::SetSymbol(char symbol) {
	this->symbol = symbol;
}

/// <summary>Checks if the tile is walkable</summary>
/// <returns>Result of that check</returns>
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

/// <summary>Sets if creatures can walk on this tile</summary>
/// <param name="walkable"></param>
void GridTile::SetWalkable(bool walkable) {
	this->walkable = walkable;
}

/// <summary>
/// Checks if the player has discovered this tile
/// </summary>
/// <returns>The result of that check</returns>
bool GridTile::GetDiscovered() {
	return discovered;
}

/// <summary>Sets the discovery state of this tile</summary>
/// <param name="discovered">the discovery state of this tile</param>
void GridTile::SetDiscovered(bool discovered) {
	this->discovered = discovered;
}

/// <summary>Checks if this tile is visible</summary>
/// <returns>Result of that check</returns>
bool GridTile::GetVisible() {
	return visible;
}

/// <summary>Sets the visibility state of this tile</summary>
/// <param name="visible">the result of this check</param>
void GridTile::SetVisible(bool visible) {
	this->visible = visible;
}

/// <summary>Sets the player to this tile</summary>
/// <param name="player">the reference to the player</param>
void GridTile::SetPlayer(Player* player) {
	this->player = player;
}

/// <summary>Sets the monster that is on this tile</summary>
/// <param name="monster">The reference to that monster</param>
void GridTile::SetMonster(Monster* monster) {
	this->monster = monster;
}

/// <summary>Gets the monster on this tile</summary>
/// <returns>The monster on this tile or nullptr if no monster is on this tile</returns>
Monster* GridTile::GetMonster() {
	return monster;
}

/// <summary>Gets the reference to the player</summary>
/// <returns>reference to the player or null if they're not on this tile</returns>
Player* GridTile::GetPlayer() {
	return player;
}
