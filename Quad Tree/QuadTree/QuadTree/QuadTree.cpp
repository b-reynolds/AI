#include "QuadTree.h"

QuadTree::QuadTree(BoundingBox boundary, int nodeCapacity)
{
	northWest = nullptr;
	northEast = nullptr;
	southWest = nullptr;
	southEast = nullptr;
	this->boundary = boundary;
	this->nodeCapacity = nodeCapacity;
}

QuadTree::~QuadTree()
{
	delete northWest;
	delete northEast;
	delete southWest;
	delete southEast;
}

bool QuadTree::insert(Point point)
{
	if (!boundary.containsPoint(point))
	{
		printf("Point out of bounds\n");
		return false;
	}

	if (points.size() < nodeCapacity)
	{
		points.push_back(point);
		printf("Inserted point (%i/%i)\n", points.size(), nodeCapacity);
		return true;
	}

	if (northWest == nullptr)
	{
		subdivide();
		printf("Subdivided\n");
	}

	if (northWest->insert(point))
	{
		printf("Point inserted NW\n");
		return true;
	}
	else if (northEast->insert(point))
	{
		printf("Point inserted NE\n");
		return true;
	}
	else if (southWest->insert(point))
	{
		printf("Point inserted SW\n");
		return true;
	}
	else if (southEast->insert(point))
	{
		printf("Point inserted SE\n");
		return true;
	}

	return false;
}

void QuadTree::subdivide()
{
	northWest = new QuadTree(BoundingBox(boundary.getCenter().getX() - boundary.getHalfDimension() / 2,
		boundary.getCenter().getY() - boundary.getHalfDimension() / 2, boundary.getHalfDimension() / 2), nodeCapacity);
	northEast = new QuadTree(BoundingBox(boundary.getCenter().getX() + boundary.getHalfDimension() / 2,
		boundary.getCenter().getY() - boundary.getHalfDimension() / 2, boundary.getHalfDimension() / 2), nodeCapacity);
	southWest = new QuadTree(BoundingBox(boundary.getCenter().getX() - boundary.getHalfDimension() / 2,
		boundary.getCenter().getY() + boundary.getHalfDimension() / 2, boundary.getHalfDimension() / 2), nodeCapacity);
	southEast = new QuadTree(BoundingBox(boundary.getCenter().getX() + boundary.getHalfDimension() / 2,
		boundary.getCenter().getY() + boundary.getHalfDimension() / 2, boundary.getHalfDimension() / 2), nodeCapacity);
}

std::vector<Point> QuadTree::queryRange(BoundingBox range)
{
	std::vector<Point> pointsInRange;

	if (!boundary.intersects(range))
	{
		return pointsInRange;
	}

	for (int x = 0; x < points.size(); x++)
	{
		if (range.containsPoint(points[x]))
		{
			pointsInRange.push_back(points[x]);
		}
	}

	if (northWest == nullptr)
	{
		return pointsInRange;
	}

	for (auto& point : northWest->queryRange(range))
	{
		pointsInRange.push_back(point);
	}

	for (auto& point : northEast->queryRange(range))
	{
		pointsInRange.push_back(point);
	}

	for (auto& point : southWest->queryRange(range))
	{
		pointsInRange.push_back(point);
	}

	for (auto& point : southEast->queryRange(range))
	{
		pointsInRange.push_back(point);
	}

	return pointsInRange;
}

void QuadTree::draw(sf::RenderWindow * window)
{

	boundary.draw(window);

	if (northWest != nullptr)
	{
		northWest->draw(window);
		northEast->draw(window);
		southWest->draw(window);
		southEast->draw(window);
	}

	for (auto& point : queryRange(boundary))
	{
		point.draw(window);
	}

}
