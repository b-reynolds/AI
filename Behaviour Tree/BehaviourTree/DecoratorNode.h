#pragma once
#include "Node.h"

class DecoratorNode : public Node
{

public:

	DecoratorNode();
	void setChild(Node* child);

protected:

	Node* getChild() const;

private:
		
	Node* child;

};

