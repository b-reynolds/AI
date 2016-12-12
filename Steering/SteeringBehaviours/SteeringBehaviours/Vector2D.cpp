#pragma once
#define _USE_MATH_DEFINES
#include "Vector2D.h"
#include <math.h>

sf::Vector2f Vector2D::normalize(const sf::Vector2f& vector)
{
	float length = (float)sqrt(vector.x * vector.x + vector.y * vector.y);
	return length != 0 ? sf::Vector2f(vector.x / length, vector.y / length) : vector;
}

sf::Vector2f Vector2D::limit(const sf::Vector2f& vector, const float& maxLength)
{
	float lengthSquared = vector.x * vector.x + vector.y * vector.y;
	if(lengthSquared > maxLength * maxLength && lengthSquared > 0)
	{
		float ratio = maxLength / (float)sqrt(lengthSquared);
		return sf::Vector2f(vector.x * ratio, vector.y * ratio);
	}
	return sf::Vector2f(0, 0);
}

sf::Vector2f Vector2D::rotate(const sf::Vector2f& vector, const float& degrees)
{
	float radians = degrees * (float)(M_PI / 180);
	float cosAngle = cos(radians);
	float sinAngle = sin(radians);
	return sf::Vector2f(vector.x * cosAngle -vector.y * sinAngle, vector.x * sinAngle + vector.y * cosAngle);
}

float Vector2D::magnitude(const sf::Vector2f& vector)
{
	return (float)sqrt(vector.x * vector.x + vector.y * vector.y);
}

float Vector2D::map(const float& value, const float& aStart, const float& aStop, const float& bStart, const float& bStop)
{
	return (bStop - bStart) * ((value - aStart) / (aStop - aStart));
}

float Vector2D::distance(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
	return (float)fabs(magnitude(v2 - v1));
}
