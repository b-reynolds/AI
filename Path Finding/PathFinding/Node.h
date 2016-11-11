#pragma once
#include <SFML/Graphics.hpp>

class Node
{

	const int SIZE = 64;

	Node* pParent;

	sf::RectangleShape shape;

	sf::Vector2f position;
	
public:

	void setParent(Node* pParent);

	void draw(sf::RenderWindow* window) const;

	explicit Node(sf::Vector2f position);
	~Node();

};

