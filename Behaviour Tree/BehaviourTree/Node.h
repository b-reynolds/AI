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
		auto depth = 0;
		auto parent = getParent();
		while(parent != nullptr)
		{
			parent = parent->getParent();
			depth++;
		}
		printf("%s> %s\n", std::string(3 * depth, '-').c_str(), getNodeType().c_str());
	}

private:

	std::string nodeType = "Node";
	Node* parent = nullptr;

};

