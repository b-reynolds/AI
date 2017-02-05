#include "DecoratorNode.h"

void DecoratorNode::setChild(Node* child)
{
	this->child = child;
}

Node* DecoratorNode::getChild() const
{
	return child;
}
