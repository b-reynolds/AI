#include "Coordinate.h"

Coordinate::Coordinate()
{
	x = 0.0f;
	y = 0.0f;
}

Coordinate::Coordinate(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Coordinate::draw(sf::RenderWindow * window)
{
	sf::Vertex vertex(sf::Vector2f(x, y));
	window->draw(&vertex, 1, sf::Points);
}
