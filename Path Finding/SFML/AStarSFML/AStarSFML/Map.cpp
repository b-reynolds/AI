#include "Map.h"

Map::Map(sf::Vector2i size, int tileSize)
{
	this->size = size;
	this->tileSize = tileSize;
	map.resize(size.x, std::vector<int>(size.y, true));
}

void Map::draw(sf::RenderWindow* window)
{
	for(int x = 0; x < size.x; ++x)
	{
		for(int y = 0; y < size.y; ++y)
		{
			sf::RectangleShape shape;
			shape.setPosition(y * tileSize, x * tileSize);
			shape.setSize(sf::Vector2f(tileSize, tileSize));
			shape.setOutlineColor(sf::Color::Black);
			shape.setOutlineThickness(-1);
			switch(getValue(sf::Vector2i(x, y)))
			{
				case 0:
					shape.setFillColor(sf::Color(5, 5, 5));
					break;
				case 1:
					shape.setFillColor(sf::Color(75, 75, 75));
					break;
				case 2:
					shape.setFillColor(sf::Color(200, 200, 200));
					break;
				case 3:
					shape.setFillColor(sf::Color(0, 43, 11));;
					break;
				case 4:
					shape.setFillColor(sf::Color(50, 50, 50));
					break;
				case 5:
					shape.setFillColor(sf::Color(43, 0, 0));
					break;
			}
			window->draw(shape);
		}
	}
}

void Map::setMap(std::vector<std::vector<int>> map)
{
	for (int x = 0; x < size.x; ++x)
	{
		for (int y = 0; y < size.y; ++y)
		{
			this->map[x][y] = map[x][y];
		}
	}
}

void Map::setValue(sf::Vector2i position, int value)
{
	map[position.x][position.y] = value;
}

int Map::getValue(sf::Vector2i position)
{
	return map[position.x][position.y];
}

Map::~Map()
{
}
