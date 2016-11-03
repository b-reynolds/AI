#include "Point.h"

Point::Point()
{
	x = 0.0f;
	y = 0.0f;
}

Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Point::draw(sf::RenderWindow * window)
{
	sf::Vertex vertex(sf::Vector2f(x, y));
	window->draw(&vertex, 1, sf::Points);
}
