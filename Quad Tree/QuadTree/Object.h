#pragma once
#include <SFML/Graphics.hpp>

class Object
{

	sf::Sprite sprite;

public:

	explicit Object(sf::Texture* texture);

	void draw(sf::RenderWindow* window) const;

};

