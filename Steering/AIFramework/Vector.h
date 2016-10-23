#pragma once
#include <SFML/Graphics.hpp>

class Vector {

public:

	static sf::Vector2f Normalize(sf::Vector2f _V);
	static sf::Vector2f Limit_Magnitude(sf::Vector2f _V, float _Max);
	static sf::Vector2f Multiply(sf::Vector2f _V, int _Scalar);
	static sf::Vector2f Multiply(sf::Vector2f _V1, sf::Vector2f _V2);
	static sf::Vector2f Zero();

	static float Magnitude(sf::Vector2f _V);

};

