#pragma once
#include <SFML/Graphics.hpp>

class Point
{

public:

	float x;
	float y;

	Point();
	Point(float x, float y);

	void draw(sf::RenderWindow* window);

};

