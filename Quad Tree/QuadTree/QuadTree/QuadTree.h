#pragma once
#include "BoundingBox.h"

class QuadTree
{

private:

	QuadTree* northWest;
	QuadTree* northEast;
	QuadTree* southWest;
	QuadTree* southEast;

	unsigned int nodeCapacity = 0;

	BoundingBox boundary;
	std::vector<Point> points;

	void subdivide();
	std::vector<Point> queryRange(BoundingBox range);

public:

	QuadTree(BoundingBox boundary, int nodeCapacity);
	~QuadTree();

	bool insert(Point Point);
	void draw(sf::RenderWindow *window);

};

