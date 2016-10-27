#include "Object.h"

Object::Object(sf::Texture* texture)
{
	sprite.setTexture(*texture);
}

void Object::draw(sf::RenderWindow* window) const
{
	window->draw(sprite);
}
