#pragma once
#include <SFML/Graphics.hpp>

class Coordinate
{

public:

	float x;
	float y;

	Coordinate();
	Coordinate(float x, float y);

	void draw(sf::RenderWindow* window);

};

