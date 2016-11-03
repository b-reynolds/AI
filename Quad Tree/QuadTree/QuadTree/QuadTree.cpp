#include "QuadTree.h"

QuadTree::QuadTree(BoundingBox boundary)
{
	northWest = nullptr;
	northEast = nullptr;
	southWest = nullptr;
	southEast = nullptr;
	this->boundary = boundary;
}

QuadTree::~QuadTree()
{
	delete northWest;
	delete northEast;
	delete southWest;
	delete southEast;
}

bool QuadTree::insert(Coordinate coordinate)
{
	if (!boundary.containsPoint(coordinate))
	{
		return false;
	}

	if (points.size() < NODE_CAPACITY)
	{
		points.push_back(coordinate);
		return true;
	}

	if (northWest == nullptr)
	{
		subdivide();
	}

	if (northWest->insert(coordinate))
	{
		return true;
	}
	else if (northEast->insert(coordinate))
	{
		return true;
	}
	else if (southWest->insert(coordinate))
	{
		return true;
	}
	else if (southEast->insert(coordinate))
	{
		return true;
	}

	return false;
}

void QuadTree::subdivide()
{
	Coordinate center = Coordinate(boundary.center.x - boundary.halfDimension, boundary.center.y - boundary.halfDimension);
	northWest = new QuadTree(BoundingBox(center.x, center.y, boundary.halfDimension));

	center = Coordinate(boundary.center.x + boundary.halfDimension, boundary.center.y - boundary.halfDimension);
	northEast = new QuadTree(BoundingBox(center.x, center.y, boundary.halfDimension));

	center = Coordinate(boundary.center.x - boundary.halfDimension, boundary.center.y + boundary.halfDimension);
	southWest = new QuadTree(BoundingBox(center.x, center.y, boundary.halfDimension));

	center = Coordinate(boundary.center.x + boundary.halfDimension, boundary.center.y + boundary.halfDimension);
	southEast = new QuadTree(BoundingBox(center.x, center.y, boundary.halfDimension));
}

std::vector<Coordinate> QuadTree::queryRange(BoundingBox range)
{
	std::vector<Coordinate> pointsInRange;

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

	for (auto& point : northWest->queryRange(range))
	{
		pointsInRange.push_back(point);
	}

	for (auto& point : northWest->queryRange(range))
	{
		pointsInRange.push_back(point);
	}

	for (auto& point : northWest->queryRange(range))
	{
		pointsInRange.push_back(point);
	}

}

void QuadTree::draw(sf::RenderWindow * window)
{

	for (auto& point : points) {
		point.draw(window);
	}

	boundary.draw(window);

	if (northWest != nullptr)
	{
		northWest->draw(window);
	}

	if (northEast != nullptr)
	{
		northEast->draw(window);
	}

	if (southWest != nullptr)
	{
		southWest->draw(window);
	}

	if (southEast != nullptr)
	{
		southEast->draw(window);
	}

}
