#include "Node.h"

void Node::setParent(Node* parent)
{
	this->parent = parent;
}

void Node::setState(NodeState state)
{
	this->state = state;
}

Point Node::getPosition() const
{
	return position;
}

Node* Node::getParent() const
{
	return parent;
}

NodeState Node::getState() const
{
	return state;
}

void Node::setH(int h)
{
	this->h = h;
	f = h + g;
}

void Node::setG(int g)
{
	this->g = g;
	f = h + g;
}

int Node::getH() const
{
	return h;
}

int Node::getG() const
{
	return g;
}

int Node::getF() const
{
	return f;
}

bool Node::isTraversable() const
{
	return traversable;
}

bool Node::operator==(Node node)
{
	return this->position == node.getPosition();
}

Node::Node(Point position, bool traversable, Node* parent)
{
	this->position = position;
	this->parent = parent;
	this->traversable = traversable;
	state = Untested;
	h = 0;
	g = 0;
	f = 0;
}

Node::~Node()
{
}
