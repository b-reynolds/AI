#pragma once
#include <SFML/Graphics.hpp>
#include "Point.h"

class BoundingBox
{

private:

	Point center;
	float halfDimension;

public:

	BoundingBox();
	BoundingBox(float x, float y, float halfDimension);

	Point getCenter();
	float getHalfDimension();

	bool containsPoint(Point point);
	bool intersects(BoundingBox boundingBox);
	void draw(sf::RenderWindow* window);

};

