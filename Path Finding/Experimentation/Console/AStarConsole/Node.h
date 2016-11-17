#pragma once
#include "Point.h"

enum NodeState { Untested, Open, Closed };

class Node
{

private:

	Node* parent;

	Point position;
	NodeState state;
	bool traversable;

	int h;
	int g;
	int f;

public:

	void setParent(Node* pParent);
	void setState(NodeState state);


	Point getPosition() const;
	Node* getParent() const;
	NodeState getState() const;

	void setH(int h);
	void setG(int g);
	int getH() const;
	int getG() const;
	int getF() const;

	bool isTraversable() const;

	bool operator==(Node node);

	Node(Point position, bool traversable, Node* parent);

	~Node();

};

