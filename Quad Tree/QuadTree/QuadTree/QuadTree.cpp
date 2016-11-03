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
		std::cout << "Boundary does not contain point..." << std::endl;
		return false;
	}

	if (points.size() < nodeCapacity)
	{
		std::cout << "Inserting point (" << (points.size() + 1) << "/" << nodeCapacity << ")..." << std::endl;
		points.push_back(point);
		return true;
	}

	if (northWest == nullptr)
	{
		std::cout << "Subdividing..." << std::endl;
		subdivide();
	}

	if (northWest->insert(point))
	{
		std::cout << "Inserted point NW..." << std::endl;
		return true;
	}
	else if (northEast->insert(point))
	{
		std::cout << "Inserted point NE..." << std::endl;
		return true;
	}
	else if (southWest->insert(point))
	{
		std::cout << "Inserted point SW..." << std::endl;
		return true;
	}
	else if (southEast->insert(point))
	{
		std::cout << "Inserted point SE..." << std::endl;
		return true;
	}

	return false;
}

void QuadTree::subdivide()
{
	northWest = new QuadTree(BoundingBox(boundary.center.x - boundary.halfDimension / 2,
		boundary.center.y - boundary.halfDimension / 2, boundary.halfDimension / 2), nodeCapacity);
	northEast = new QuadTree(BoundingBox(boundary.center.x + boundary.halfDimension / 2,
		boundary.center.y - boundary.halfDimension / 2, boundary.halfDimension / 2), nodeCapacity);
	southWest = new QuadTree(BoundingBox(boundary.center.x - boundary.halfDimension / 2,
		boundary.center.y + boundary.halfDimension / 2, boundary.halfDimension / 2), nodeCapacity);
	southEast = new QuadTree(BoundingBox(boundary.center.x + boundary.halfDimension / 2,
		boundary.center.y + boundary.halfDimension / 2, boundary.halfDimension / 2), nodeCapacity);
	std::cout << "Subdivided..." << std::endl;
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

}
