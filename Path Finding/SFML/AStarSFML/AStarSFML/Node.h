#pragma once
#include <SFML/Graphics.hpp>

class Node
{

private:

	Node* pParent;

	sf::Vector2i position;
	bool traversable;

	int h;
	int g;
	int f;

public:

	void setParent(Node* pParent);
	void setH(int h);
	void setG(int g);

	sf::Vector2i getPosition() const;
	Node* getParent() const;
	int getH() const;
	int getG() const;
	int getF() const;

	bool isTraversable() const;

	bool operator==(Node node) const;

	Node(sf::Vector2i position, bool traversable, Node* pParent);
	~Node();

};

