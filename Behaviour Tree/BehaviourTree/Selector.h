#pragma once
#include "CompositeNode.h"

/**
* Returns true upon child success, false if all fail.
*/
class Selector : public CompositeNode
{

public:

	explicit Selector(const std::string &name) : CompositeNode(name) {}
	Selector() : CompositeNode("Selector") {}

	Status tick() override;

};

