#include "Vector2.h"
#include <math.h>

/// <summary>Initializes the vector with 0</summary>
Vector2::Vector2()
{
	x = 0;
	y = 0;
}

/// <summary>Initializes the vector with two values</summary>
/// <param name="x">Value for the x axis</param>
/// <param name="y">Value for the y axis</param>
Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

/// <summary>Adds two vectors</summary>
/// <param name="b">The second vector</param>
/// <returns>The result of the operation</returns>
Vector2 Vector2::operator+(Vector2 b)
{
	Vector2 result = Vector2(x, y);
	result.x += b.x;
	result.y += b.y;
	return result;
}

/// <summary>Subtracts vector b from vector a</summary>
/// <param name="b">The second vector</param>
/// <returns>The result of the operation</returns>
Vector2 Vector2::operator-(Vector2 b)
{
	Vector2 result = Vector2(x, y);
	result.x -= b.x;
	result.y -= b.y;
	return result;
}

/// <summary>Multiplies a vector by a number</summary>
/// <param name="scalar">The number</param>
/// <returns>The result of the operation</returns>
Vector2 Vector2::operator*(float scalar)
{
	Vector2 result = Vector2(x, y);
	result.x *= scalar;
	result.y *= scalar;
	return result;
}

/// <summary>Divides a vector by a number</summary>
/// <param name="scalar">The number</param>
/// <returns>The result of the operation</returns>
Vector2 Vector2::operator/(float scalar)
{
	Vector2 result = Vector2(x, y);
	result.x /= scalar;
	result.y /= scalar;
	return result;
}

/// <summary>Compares two vectors</summary>
/// <param name="b">The other vector</param>
/// <returns>true if the vectors have equal values, else false</returns>
bool Vector2::operator==(Vector2 b)
{
	if (x == b.x && y == b.y) return true;
	return false;
}

/// <summary>Calculates the magnitude of the vector</summary>
/// <returns>The magnitude of the vector</returns>
float Vector2::GetMagnitude()
{
	return sqrtf(powf(x, 2) + powf(y, 2));
}

/// <summary>Calculates the square magnitude of the vector</summary>
/// <returns>The square magnitude of the vector</returns>
float Vector2::GetSquareMagnitude()
{
	return powf(x, 2) + powf(y, 2);
}

/// <summary>Calculates the distance of two vectors</summary>
/// <param name="b">The second vector</param>
/// <returns></returns>
float Vector2::GetDistance(Vector2 b)
{
	return sqrtf(powf(b.x - x, 2) + powf(b.y - y, 2));
}
