#pragma once
#include "Node.h"
#include <vector>

/**
 * Controls the flow of logic
 */
class CompositeNode : public Node
{

public:

	void addChild(Node* child);
	std::vector<Node*>& getChildren();

private:

	std::vector<Node*> children;

};

