#pragma once
class Vector2
{
public:
	float x;
	float y;

	Vector2();
	Vector2(float x, float y);

	Vector2 operator+(Vector2 b);
	Vector2 operator-(Vector2 b);
	Vector2 operator*(float scalar);
	Vector2 operator/(float scalar);
	bool operator==(Vector2 b);

	float GetMagnitude();
	float GetSquareMagnitude();
	float GetDistance(Vector2 b);
};

