#pragma once
#include <vector>
#include "SFML/Graphics.hpp"

class Map
{

private:

	int tileSize;
	sf::Vector2i size;
	std::vector<std::vector<int>> map;

public:

	const int TILE_EMPTY = 1;
	const int TILE_SOLID = 0;
	const int TILE_START = 3;
	const int TILE_VISITED = 4;
	const int TILE_END = 5;
	const int TILE_PATH = 2;

	explicit Map(sf::Vector2i size, int tileSize);


	void draw(sf::RenderWindow* window);

	void reset();

	void setMap(std::vector<std::vector<int>> map);
	void setValue(sf::Vector2i position, int value);
	int getValue(sf::Vector2i position);

	~Map();

};