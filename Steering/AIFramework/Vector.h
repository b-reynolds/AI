#pragma once
#include <SFML/Graphics.hpp>

class Vector {

public:

	static sf::Vector2f Normalize(sf::Vector2f _V);
	static sf::Vector2f Limit_Magnitude(sf::Vector2f _V, float _Max);
	static sf::Vector2f Zero();

};

