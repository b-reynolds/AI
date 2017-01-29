#include "DecoratorNode.h"

DecoratorNode::DecoratorNode()
{
	child = nullptr;
}

void DecoratorNode::setChild(Node* child)
{
	this->child = child;
}

Node* DecoratorNode::getChild() const
{
	return child;
}
