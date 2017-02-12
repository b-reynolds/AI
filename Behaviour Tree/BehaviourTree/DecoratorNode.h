#pragma once
#include "Node.h"

class DecoratorNode : public Node
{

public:

	explicit DecoratorNode(const std::string &name) : Node(name) {}
	DecoratorNode() : Node(nodeType) {}

	void setChild(Node* child);

protected:

	Node* getChild() const;

private:
		
	std::string nodeType = "Decorator";

	Node* child = nullptr;

};

