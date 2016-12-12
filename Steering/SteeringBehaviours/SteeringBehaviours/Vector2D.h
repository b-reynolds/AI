#pragma once
#include <SFML/System/Vector2.hpp>

class Vector2D
{

public:

	static sf::Vector2f normalize(const sf::Vector2f &vector);
	static sf::Vector2f limit(const sf::Vector2f &vector, const float &maxLength);
	static sf::Vector2f rotate(const sf::Vector2f &vector, const float &degrees);
	static float magnitude(const sf::Vector2f &vector);
	static float map(const float &value, const float &aStart, const float &aStop, const float &bStart, const float &bStop);
	static float distance(const sf::Vector2f &v1, const sf::Vector2f &v2);

};

