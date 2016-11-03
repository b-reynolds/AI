#pragma once
#include "Coordinate.h"
#include <SFML/Graphics.hpp>

class BoundingBox
{

public:

	Coordinate center;
	float halfDimension;

	BoundingBox();
	BoundingBox(float x, float y, float halfDimension);

	void setPosition(float x, float y);

	bool containsPoint(Coordinate point);
	bool intersects(BoundingBox boundingBox);

	void draw(sf::RenderWindow* window);

};

