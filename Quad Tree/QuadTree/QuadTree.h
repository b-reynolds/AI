#pragma once
#include <SFML/System/Vector2.hpp>
#include "Object.h"
#include <iostream>

class QuadTree
{

	sf::Vector2u windowSize;
	std::vector<Object>* pObjects = nullptr;

	std::vector<sf::FloatRect> gridFaces;

public:

	QuadTree(sf::Vector2u windowSize, std::vector<Object>* objects);

	void calculate();
	void draw(sf::RenderWindow* window);

	sf::RectangleShape getRectangle(sf::FloatRect floatRect);

};

