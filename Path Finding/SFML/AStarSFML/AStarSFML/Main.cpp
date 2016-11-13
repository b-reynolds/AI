#include <SFML/Graphics.hpp>
#include <deque>
#include <stack>
#include "Map.h"
#include "Node.h"

const int TILE_SIZE = 64;
const int TILES_X = 10;
const int TILES_Y = 10;

const int WIN_X = TILES_X * TILE_SIZE;
const int WIN_Y = TILES_Y * TILE_SIZE;

bool isOnList(Node node, std::deque<Node> list)
{
	return std::find(list.begin(), list.end(), node) != list.end();
}

std::vector<Node> getNeighbours(Node* node, Map* map)
{
	std::vector<Node> neighbours;

	sf::Vector2i parentPos = node->getPosition();
	sf::Vector2i nodePos(0, 0);

	if (parentPos.y - 1 >= 0)
	{
		nodePos = sf::Vector2i(parentPos.x, parentPos.y - 1);
		neighbours.push_back(Node(nodePos, map->getValue(nodePos), node)); // North
		if (parentPos.x + 1 < TILES_X)
		{
			nodePos = sf::Vector2i(parentPos.x + 1, parentPos.y - 1);
			neighbours.push_back(Node(nodePos, map->getValue(nodePos), node)); // North East
		}
		if (parentPos.x - 1 >= 0)
		{
			nodePos = sf::Vector2i(parentPos.x - 1, parentPos.y - 1);
			neighbours.push_back(Node(nodePos, map->getValue(nodePos), node)); // North West
		}
	}

	if (parentPos.x + 1 < TILES_X)
	{
		nodePos = sf::Vector2i(parentPos.x + 1, parentPos.y);
		neighbours.push_back(Node(nodePos, map->getValue(nodePos), node)); // East
	}

	if (parentPos.x - 1 >= 0)
	{
		nodePos = sf::Vector2i(parentPos.x - 1, parentPos.y);
		neighbours.push_back(Node(nodePos, map->getValue(nodePos), node)); // West
	}

	if (parentPos.y + 1 < TILES_Y)
	{
		nodePos = sf::Vector2i(parentPos.x, parentPos.y + 1);
		neighbours.push_back(Node(nodePos, map->getValue(nodePos), node)); // South
		if (parentPos.x + 1 < TILES_X)
		{
			nodePos = sf::Vector2i(parentPos.x + 1, parentPos.y + 1);
			neighbours.push_back(Node(nodePos, map->getValue(nodePos), node)); // South East
		}
		if (parentPos.x - 1 >= 0)
		{
			nodePos = sf::Vector2i(parentPos.x - 1, parentPos.y + 1);
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

std::stack<sf::Vector2i> findPath(Map* map, sf::Vector2i start, sf::Vector2i goal)
{
	std::stack<sf::Vector2i> path;
	std::deque<Node> open;
	std::deque<Node> closed;

	if (start == goal)
	{
		return path; // We are already there
	}

	if (map->getValue(goal) == 0)
	{
		return path; // Target is untraversable
	}

	open.push_back(Node(start, map->getValue(start), nullptr));

	while (open.size() > 0)
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

		for (auto& neighbour : neighbours)
		{
			if (!isOnList(neighbour, closed) && neighbour.isTraversable())
			{
				if (!isOnList(neighbour, open))
				{
					neighbour.setParent(node);
					neighbour.setH((goal.x + goal.y) - (neighbour.getPosition().x + neighbour.getPosition().y));
					if (neighbour.getPosition().x != node->getPosition().x && neighbour.getPosition().y != node->getPosition().y)
					{
						neighbour.setG(neighbour.getParent()->getG() + 14);
					}
					else
					{
						neighbour.setG(neighbour.getParent()->getG() + 10);
					}
					open.push_back(neighbour);
					map->setValue(neighbour.getPosition(), 4);
				}
				else
				{
					int traversal = 0;

					float deltaX = neighbour.getParent()->getPosition().x - neighbour.getPosition().x;
					float deltaY = neighbour.getParent()->getPosition().y - neighbour.getPosition().y;
					traversal = sqrt(deltaX * deltaX + deltaY * deltaY);

					int gTemp = node->getG() + traversal;
					if (gTemp < neighbour.getG())
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
	while (pathNode != nullptr)
	{
		path.push(pathNode->getPosition());
		pathNode = pathNode->getParent();
	}

	return path;

}

int main()
{

	Map map(sf::Vector2i(TILES_X, TILES_Y), TILE_SIZE);

	map.setMap(std::vector<std::vector<int>> {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 2, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 1, 1, 0, 1, 1, 1, 1, 0 },
		{ 0, 1, 0, 1, 0, 1, 1, 1, 1, 0 },
		{ 0, 1, 0, 1, 0, 1, 0, 1, 1, 0 },
		{ 0, 1, 0, 1, 0, 1, 0, 1, 1, 0 },
		{ 0, 1, 0, 1, 0, 1, 1, 1, 1, 0 },
		{ 0, 1, 1, 1, 0, 1, 1, 1, 1, 0 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 3, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	});
	
	sf::Vector2i startPosition(0, 0);
	sf::Vector2i destination(0, 0);

	for (int x = 0; x < TILES_X; ++x)
	{
		for (int y = 0; y < TILES_Y; ++y)
		{
			if (map.getValue(sf::Vector2i(x, y)) == 2)
			{
				startPosition = sf::Vector2i(x, y);
			}
			else if (map.getValue(sf::Vector2i(x, y)) == 3)
			{
				destination = sf::Vector2i(x, y);
			}
		}
	}

	std::stack<sf::Vector2i> path = findPath(&map, startPosition, destination);

	while (path.size() > 0)
	{
		sf::Vector2i point = path.top();
		map.setValue(point, 2);
		path.pop();
	}

	map.setValue(startPosition, 3);
	map.setValue(destination, 5);

		
	sf::RenderWindow window(sf::VideoMode(WIN_X, WIN_Y), "A* Path Finding", sf::Style::Close);

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();

		map.draw(&window);

		window.display();

	}

	return 0;
}