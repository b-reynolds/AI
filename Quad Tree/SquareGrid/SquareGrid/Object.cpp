#include "Object.h"

Object::Object(sf::Texture* texture)
{
	sprite.setTexture(*texture);
}

void Object::draw(sf::RenderWindow* window) const
{
	window->draw(sprite);
}

void Object::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

sf::FloatRect Object::getRect() const
{
	return sprite.getGlobalBounds();
}

sf::Vector2f Object::getSize() const
{
	return sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
}
