#pragma once
#include <SFML/Graphics.hpp>

class Object
{

	sf::Sprite sprite;

public:

	explicit Object(sf::Texture* texture);

	void draw(sf::RenderWindow* window) const;
	void setPosition(sf::Vector2f position);

	sf::FloatRect getRect() const;
	sf::Vector2f getSize() const;

};

