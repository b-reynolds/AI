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

	explicit Map(sf::Vector2i size, int tileSize);


	void draw(sf::RenderWindow* window);

	void setMap(std::vector<std::vector<int>> map);
	void setValue(sf::Vector2i position, int value);
	int getValue(sf::Vector2i position);

	~Map();

};