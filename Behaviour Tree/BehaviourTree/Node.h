#pragma once
#include <cstdio>
#include <string>

/**
 * Base class for each node in the behaviour tree
 */
class Node
{

public:

	enum Status { ERR, FAILURE, SUCCESS, RUNNING };

	explicit Node(const std::string &name) : nodeType(name) {}
	Node() : nodeType(nodeType) {}

	virtual ~Node() {}

	virtual Status tick() = 0;

	void setParent(Node* parent) { this->parent = parent; }
	Node* getParent() const { return parent; }

	std::string getNodeType() const { return nodeType; }

	void output() const
	{
		int depth = 0;
		Node* t = getParent();
		while(t != nullptr)
		{
			depth++;
			t = t->getParent();
		}
		for(int i = 0; i < depth; ++i)
		{
			printf("----");
		}
		printf("%s\n", getNodeType().c_str());
	}

private:

	std::string nodeType = "Node";
	Node* parent = nullptr;

};

