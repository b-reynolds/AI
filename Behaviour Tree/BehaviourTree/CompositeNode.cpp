#include "CompositeNode.h"

/**
 * Add a child to the node 
 */
void CompositeNode::addChild(Node* child)
{
	children.push_back(child);
}

/**
 * Return a reference to to the Node's children
 */
std::vector<Node*>& CompositeNode::getChildren()
{
	return children;
}
