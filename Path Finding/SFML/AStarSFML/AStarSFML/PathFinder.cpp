#include "PathFinder.h"

void PathFinder::sortByLowestF(std::deque<Node>& deque) const
{
	LessThanByF sortMethod;
	std::sort(deque.begin(), deque.end(), sortMethod);
}

int PathFinder::getManhattanDistance(const sf::Vector2i& start, const sf::Vector2i& end) const
{
	return abs(end.x - start.x) + abs(end.y - start.y);
}

int PathFinder::getMovementCost(const sf::Vector2i &start, const sf::Vector2i &end) const
{
	return start.x != end.x && start.y != end.y ? COST_DIAGONAL : COST_NONDIAGONAL;
}

std::vector<Node> PathFinder::getNeighbours(const Node &node, Map &map)
{
	std::vector<Node> neighbours;

	sf::Vector2i parentPos = node.getPosition();
	sf::Vector2i nodePos(0, 0);

	sf::Vector2i mapSize = map.getSize();

	if (parentPos.y - 1 >= 0)
	{
		nodePos = sf::Vector2i(parentPos.x, parentPos.y - 1);
		neighbours.push_back(Node(nodePos, map.getValue(nodePos), nullptr)); // North
		if (parentPos.x + 1 < mapSize.x)
		{
			nodePos = sf::Vector2i(parentPos.x + 1, parentPos.y - 1);
			neighbours.push_back(Node(nodePos, map.getValue(nodePos), nullptr)); // North East
		}
		if (parentPos.x - 1 >= 0)
		{
			nodePos = sf::Vector2i(parentPos.x - 1, parentPos.y - 1);
			neighbours.push_back(Node(nodePos, map.getValue(nodePos), nullptr)); // North West
		}
	}

	if (parentPos.x + 1 < mapSize.x)
	{
		nodePos = sf::Vector2i(parentPos.x + 1, parentPos.y);
		neighbours.push_back(Node(nodePos, map.getValue(nodePos), nullptr)); // East
	}

	if (parentPos.x - 1 >= 0)
	{
		nodePos = sf::Vector2i(parentPos.x - 1, parentPos.y);
		neighbours.push_back(Node(nodePos, map.getValue(nodePos), nullptr)); // West
	}

	if (parentPos.y + 1 < mapSize.y)
	{
		nodePos = sf::Vector2i(parentPos.x, parentPos.y + 1);
		neighbours.push_back(Node(nodePos, map.getValue(nodePos), nullptr)); // South
		if (parentPos.x + 1 < mapSize.x)
		{
			nodePos = sf::Vector2i(parentPos.x + 1, parentPos.y + 1);
			neighbours.push_back(Node(nodePos, map.getValue(nodePos), nullptr)); // South East
		}
		if (parentPos.x - 1 >= 0)
		{
			nodePos = sf::Vector2i(parentPos.x - 1, parentPos.y + 1);
			neighbours.push_back(Node(nodePos, map.getValue(nodePos), nullptr)); // South West
		}
	}

	return neighbours;
}

bool PathFinder::isOnList(const Node &node, const std::deque<Node> &list)
{
	return std::find(list.begin(), list.end(), node) != list.end();
}

std::stack<sf::Vector2i> PathFinder::findPath(Map &map, const sf::Vector2i &start, const sf::Vector2i &end)
{
	std::stack<sf::Vector2i> path;
	std::deque<Node> openList;
	std::deque<Node> closedList;

	if (start == end)
	{
		return path;
	}

	if (map.getValue(end) == 0)
	{
		return path;
	}

	openList.push_front(Node(start, map.getValue(start), nullptr));

	while (openList.size() > 0)
	{
		sortByLowestF(openList);

		Node* currentNode = new Node(openList.front());
		openList.pop_front();
		closedList.push_back(*currentNode);

		if (currentNode->getPosition() == end)
		{
			break;
		}

		std::vector<Node> neighbours = getNeighbours(*currentNode, map);

		for (auto& neighbour : neighbours)
		{
			if (!neighbour.isTraversable() || isOnList(neighbour, closedList))
			{
				continue;
			}

			if(isOnList(neighbour, openList))
			{
				float newG = currentNode->getG() + getMovementCost(currentNode->getPosition(), neighbour.getPosition());
				if (newG < neighbour.getG())
				{
					neighbour.setG(newG);
					neighbour.setParent(currentNode);
				}
			}
			else
			{
				neighbour.setParent(currentNode);
				neighbour.setH(getManhattanDistance(neighbour.getPosition(), end)* 10);
				neighbour.setG(currentNode->getG() + getMovementCost(currentNode->getPosition(), neighbour.getPosition()));
				openList.push_front(neighbour);
				map.setValue(neighbour.getPosition(), map.TILE_VISITED);
			}		
		}
	}

	Node* pathNode = &closedList.back();
	while (pathNode != nullptr)
	{
		path.push(pathNode->getPosition());
		pathNode = pathNode->getParent();
	}

	return path;
}

PathFinder::PathFinder()
{
}


PathFinder::~PathFinder()
{
}
