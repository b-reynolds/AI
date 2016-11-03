#pragma once
#include "BoundingBox.h"
#include <iostream>

class QuadTree
{

private:

	unsigned int nodeCapacity = 0;


	std::vector<Point> points;

	QuadTree* northWest;
	QuadTree* northEast;
	QuadTree* southWest;
	QuadTree* southEast;

	void subdivide();

public:

	BoundingBox boundary;
	std::vector<Point> queryRange(BoundingBox range);


	QuadTree(BoundingBox boundary, int nodeCapacity);
	~QuadTree();

	bool insert(Point Point);
	void draw(sf::RenderWindow *window);

};

