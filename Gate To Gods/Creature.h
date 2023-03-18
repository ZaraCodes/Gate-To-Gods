#pragma once
#include "Vector2.h"

class Creature
{
private:
	int healthPoints;
	int maxHealthPoints;
	int attackPower;
	float accuracy;
	float critPropability;
	

public:
	Vector2 position;
	char symbol;

	
	Creature(int healthPoints, int attackPower, float accuracy, float critPropability, char symbol);
	bool Attack(Creature creature);

	int GetMaxHealthPoints();
	int GetHealthPoints();
	void SetHealthPoints(int newHealthPoints);

	Vector2 GetPosition();
	void SetPosition(Vector2 position);
};

