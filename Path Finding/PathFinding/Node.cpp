#include "Node.h"


void Node::setParent(Node* pParent)
{
	pParent = pParent;
}

void Node::draw(sf::RenderWindow* window) const
{
	window->draw(shape);
}

Node::Node(sf::Vector2f position)
{
	this->position = position;

	pParent = nullptr;

	shape.setPosition(position.x * SIZE, position.y * SIZE);
	shape.setSize(sf::Vector2f(SIZE, SIZE));
	shape.setOutlineThickness(-1);
	shape.setFillColor(sf::Color::White);
	shape.setOutlineColor(sf::Color::Black);
}


Node::~Node()
{
}
