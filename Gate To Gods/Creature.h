#pragma once
#include "Vector2.h"
#include "MessageBox.h"

class Creature
{
protected:
	int healthPoints;
	int maxHealthPoints;
	int attackPower;
	bool hasKey;
	float accuracy;
	float critPropability;
	MessageBox* messageBox;

public:
	Vector2 position;
	char symbol;
	
	Creature(MessageBox* messageBox, int healthPoints, int attackPower, float accuracy, float critPropability, char symbol);
	bool Attack(Creature* creature);

	int GetMaxHealthPoints();
	int GetHealthPoints();
	void SetHealthPoints(int newHealthPoints);
	int TakeDamage(int damage);

	virtual void PushTakeDamageMessage(int damage);
	virtual void PushDeathMessage();

	Vector2 GetPosition();
	void SetPosition(Vector2 position);

	bool GetHasKey();
	void SetHasKey(bool value);
};

