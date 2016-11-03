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
		std::cout << "Boundary does not contain point..." << std::endl;
		return false;
	}

	if (points.size() < NODE_CAPACITY)
	{
		std::cout << "Inserting point (" << (points.size() + 1) << "/" << NODE_CAPACITY << ")..." << std::endl;
		points.push_back(coordinate);
		return true;
	}

	if (northWest == nullptr)
	{
		std::cout << "Subdividing..." << std::endl;
		subdivide();
	}

	if (northWest->insert(coordinate))
	{
		std::cout << "Inserting point NW..." << std::endl;
		return true;
	}
	else if (northEast->insert(coordinate))
	{
		std::cout << "Inserting point NE..." << std::endl;
		return true;
	}
	else if (southWest->insert(coordinate))
	{
		std::cout << "Inserting point SW..." << std::endl;
		return true;
	}
	else if (southEast->insert(coordinate))
	{
		std::cout << "Inserting point SE..." << std::endl;
		return true;
	}

	return false;
}

void QuadTree::subdivide()
{
	northWest = new QuadTree(BoundingBox(boundary.center.x - boundary.halfDimension,
		boundary.center.y - boundary.halfDimension, boundary.halfDimension));
	northEast = new QuadTree(BoundingBox(boundary.center.x + boundary.halfDimension,
		boundary.center.y - boundary.halfDimension, boundary.halfDimension));
	southWest = new QuadTree(BoundingBox(boundary.center.x - boundary.halfDimension,
		boundary.center.y + boundary.halfDimension, boundary.halfDimension));
	southEast = new QuadTree(BoundingBox(boundary.center.x + boundary.halfDimension,
		boundary.center.y + boundary.halfDimension, boundary.halfDimension));
	std::cout << "Subdivided..." << std::endl;
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

}
