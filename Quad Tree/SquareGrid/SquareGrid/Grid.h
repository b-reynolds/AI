#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h";

class Grid
{

	static const int GRIDX = 40;
	static const int GRIDY = 40;
	const int CELLSIZEX = 16;
	const int CELLSIZEY = 16;

	int gridSpaces[GRIDX][GRIDY] = { 0 };

public:

	Grid();

	void update(std::vector<Object>* objects);
	void draw(sf::RenderWindow* window) const;

};

