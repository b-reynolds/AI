#pragma once
#include "Point.h"
#include <SFML/Graphics.hpp>

class BoundingBox
{

public:

	Point center;
	float halfDimension;

	BoundingBox();
	BoundingBox(float x, float y, float halfDimension);

	void setPosition(float x, float y);

	bool containsPoint(Point point);
	bool intersects(BoundingBox boundingBox);

	void draw(sf::RenderWindow* window);

};

