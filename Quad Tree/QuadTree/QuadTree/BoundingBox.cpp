#include "BoundingBox.h"

BoundingBox::BoundingBox()
{
	center.setX(0);
	center.setY(0);
	halfDimension = 0;
}

BoundingBox::BoundingBox(float x, float y, float halfDimension)
{
	center.setX(x);
	center.setY(y);
	this->halfDimension = halfDimension;
}

Point BoundingBox::getCenter()
{
	return center;
}

float BoundingBox::getHalfDimension()
{
	return halfDimension;
}

bool BoundingBox::containsPoint(Point point)
{
	return (center.getX() - halfDimension <= point.getX() && center.getX() + halfDimension >= point.getX()) &&
		(center.getY() - halfDimension <= point.getY() && center.getY() + halfDimension >= point.getY());
}

bool BoundingBox::intersects(BoundingBox boundingBox)
{
	return (center.getX() - halfDimension < boundingBox.center.getX() + boundingBox.halfDimension) &&
		(center.getX() + halfDimension > boundingBox.center.getX() - boundingBox.halfDimension) &&
		(center.getY() - halfDimension < boundingBox.center.getY() + boundingBox.halfDimension) &&
		(center.getY() + halfDimension > boundingBox.center.getY() - boundingBox.halfDimension);
}

void BoundingBox::draw(sf::RenderWindow * window)
{
	sf::RectangleShape shape;
	shape.setPosition(sf::Vector2f(center.getX() - halfDimension, center.getY() - halfDimension));
	shape.setSize(sf::Vector2f(halfDimension * 2, halfDimension * 2));
	shape.setFillColor(sf::Color(0, 0, 0, 25.0f));
	shape.setOutlineColor(sf::Color(0, 0, 0, 50.0f));
	shape.setOutlineThickness(1);
	window->draw(shape);
}
