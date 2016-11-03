#pragma once
#include "BoundingBox.h"
#include <iostream>

class QuadTree
{

public:

	const int NODE_CAPACITY = 4;

	BoundingBox boundary;

	std::vector<Coordinate> points;

	QuadTree* northWest;
	QuadTree* northEast;
	QuadTree* southWest;
	QuadTree* southEast;

	QuadTree(BoundingBox boundary);
	~QuadTree();

	bool insert(Coordinate coordinate);
	void subdivide();
	std::vector<Coordinate> queryRange(BoundingBox range);

	void draw(sf::RenderWindow *window);

};

