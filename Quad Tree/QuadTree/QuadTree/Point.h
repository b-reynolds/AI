#pragma once
#include <SFML/Graphics.hpp>

class Point
{

private:

	float x;
	float y;

public:

	Point();
	Point(float x, float y);

	void setX(float x);
	float getX();

	void setY(float y);
	float getY();

	void draw(sf::RenderWindow* window);

};

