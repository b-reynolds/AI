#include "BoundingBox.h"

BoundingBox::BoundingBox(float x, float y, float halfDimension)
{
	center.x = x;
	center.y = y;
	this->halfDimension = halfDimension;
}

void BoundingBox::setPosition(float x, float y)
{
	center.x = x;
	center.y = y;
}

bool BoundingBox::containsPoint(Coordinate point)
{
	return (center.x - halfDimension <= point.x && center.x + halfDimension >= point.x) &&
		(center.y - halfDimension <= point.y && center.y + halfDimension >= point.y);
}

bool BoundingBox::intersects(BoundingBox boundingBox)
{
	return (center.x - halfDimension < boundingBox.center.x + boundingBox.halfDimension) &&
		(center.x + halfDimension > boundingBox.center.x - boundingBox.halfDimension) &&
		(center.y - halfDimension < boundingBox.center.y + boundingBox.halfDimension) &&
		(center.y + halfDimension > boundingBox.center.y - boundingBox.halfDimension);
}

void BoundingBox::draw(sf::RenderWindow * window)
{
	sf::RectangleShape shape;
	shape.setPosition(sf::Vector2f(center.x - halfDimension, center.y - halfDimension));
	shape.setSize(sf::Vector2f(halfDimension * 2, halfDimension * 2));
	window->draw(shape);
}
