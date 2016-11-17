#include <stdio.h>
#include <vector>
#include "Node.h"
#include "Map.h"
#include <stack>
#include <math.h>

const Point mapSize(10, 10);

bool isOnList(Node node, std::deque<Node> list)
{
	return std::find(list.begin(), list.end(), node) != list.end();
}

std::vector<Node> getNeighbours(Node* node, Map* map)
{
	std::vector<Node> neighbours;

	Point parentPos = node->getPosition();
	Point nodePos = Point(0, 0);

	if(parentPos.y - 1 >= 0)
	{
		nodePos = Point(parentPos.x, parentPos.y - 1);
		neighbours.push_back(Node(nodePos, map->getValue(nodePos), node)); // North
		if(parentPos.x + 1 < mapSize.x)
		{
			nodePos = Point(parentPos.x + 1, parentPos.y - 1);
			neighbours.push_back(Node(nodePos, map->getValue(nodePos), node)); // North East
		}
		if(parentPos.x - 1 >= 0)
		{
			nodePos = Point(parentPos.x - 1, parentPos.y - 1);
			neighbours.push_back(Node(nodePos, map->getValue(nodePos), node)); // North West
		}
	}

	if(parentPos.x + 1 < mapSize.x)
	{
		nodePos = Point(parentPos.x + 1, parentPos.y);
		neighbours.push_back(Node(nodePos, map->getValue(nodePos), node)); // East
	}

	if(parentPos.x - 1 >= 0)
	{
		nodePos = Point(parentPos.x - 1, parentPos.y);
		neighbours.push_back(Node(nodePos, map->getValue(nodePos), node)); // West
	}

	if(parentPos.y + 1 < mapSize.y)
	{
		nodePos = Point(parentPos.x, parentPos.y + 1);
		neighbours.push_back(Node(nodePos, map->getValue(nodePos), node)); // South
		if(parentPos.x + 1 < mapSize.x)
		{
			nodePos = Point(parentPos.x + 1, parentPos.y + 1);
			neighbours.push_back(Node(nodePos, map->getValue(nodePos), node)); // South East
		}
		if(parentPos.x - 1 >= 0)
		{
			nodePos = Point(parentPos.x - 1, parentPos.y + 1);
			neighbours.push_back(Node(nodePos, map->getValue(nodePos), node)); // South West
		}
	}

	return neighbours;
}

std::deque<Node> sortByLowestF(std::deque<Node> queue)
{
	std::deque<Node> sortedQueue;
	while (queue.size() > 0) 
	{
		int highestF = 0;
		int nodeIndex = 0;
		for (int i = 0; i < queue.size(); ++i)
		{
			if (queue[i].getF() > highestF)
			{
				highestF = queue[i].getF();
				nodeIndex = i;
			}
		}
		sortedQueue.push_back(queue[nodeIndex]);
		queue.erase(queue.begin() + nodeIndex);
	}
	return sortedQueue;
}

std::stack<Point> findPath(Map* map, Point start, Point goal)
{
	std::stack<Point> path;
	std::deque<Node> open;
	std::deque<Node> closed;

	if(start == goal)
	{
		return path; // We are already there
	}

	if(map->getValue(goal) == 0)
	{
		return path; // Target is untraversable
	}

	open.push_back(Node(start, map->getValue(start), nullptr));

	while(open.size() > 0)
	{
		open = sortByLowestF(open);

		Node* node = new Node(open.back());
		open.pop_back();

		closed.push_back(*node);

		if (node->getPosition() == goal)
		{
			break;
		}

		std::vector<Node> neighbours = getNeighbours(node, map);

		for(auto& neighbour : neighbours)
		{
			if(!isOnList(neighbour, closed) && neighbour.isTraversable())
			{
				if(!isOnList(neighbour, open))
				{
					neighbour.setParent(node);
					neighbour.setH((goal.x + goal.y) - (neighbour.getPosition().x + neighbour.getPosition().y));
					if(neighbour.getPosition().x != node->getPosition().x && neighbour.getPosition().y != node->getPosition().y)
					{
						neighbour.setG(neighbour.getParent()->getG() + 14);
					}
					else
					{
						neighbour.setG(neighbour.getParent()->getG() + 10);
					}
					open.push_back(neighbour);
				}
				else
				{
					int traversal = 0;
					
					float deltaX = neighbour.getParent()->getPosition().x - neighbour.getPosition().x;
					float deltaY = neighbour.getParent()->getPosition().y - neighbour.getPosition().y;
					traversal = sqrt(deltaX * deltaX + deltaY * deltaY);
						
					int gTemp = node->getG() + traversal;
					if(gTemp < neighbour.getG())
					{
						neighbour.setParent(node);
						neighbour.setG(gTemp);
						open.push_back(neighbour);
					}	
				}
			}
		}



	}

	Node* pathNode = &closed[closed.size() - 1];
	while(pathNode != nullptr)
	{
		path.push(pathNode->getPosition());
		pathNode = pathNode->getParent();
	}


	return path;

}

int main()
{

	Map map(mapSize);

	map.setMap(std::vector<std::vector<int>> {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 0, 1, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1 },
	});

	Point start(0, 0);
	Point end(9, 9);

	map.setValue(start, 3);
	map.setValue(end, 4);

	map.print();

	std::stack<Point> path = findPath(&map, start, end);

	while(path.size() > 0)
	{
		Point point = path.top(); 
		map.setValue(point, 2);
		path.pop();
	}

	printf("\n");

	map.print();

	getchar();

	return 0;
}