#pragma once
#include "Node.h"
#include <vector>

/**
 * Controls the flow of logic
 */
class CompositeNode : public Node
{

public:

	explicit CompositeNode(const std::string &name) : Node(name) {}
	CompositeNode() : Node(nodeType) {}

	void addChild(Node* child);
	std::vector<Node*>& getChildren();

private:

	std::string nodeType = "Composite";

	std::vector<Node*> children;

};

