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

void Point::setX(float x)
{
	this->x = x;
}

void Point::setY(float y)
{
	this->y = y;
}

float Point::getX()
{
	return x;
}

float Point::getY()
{
	return y;
}

void Point::draw(sf::RenderWindow * window)
{
	sf::RectangleShape shape;
	shape.setPosition(x, y);
	shape.setSize(sf::Vector2f(2.0f, 2.0f));
	shape.setFillColor(sf::Color(0.0f, 0.0f, 0.0f, 125.0f));
	window->draw(shape);
}
