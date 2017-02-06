#pragma once
#include "DecoratorNode.h"

class Succeeder : public DecoratorNode
{

public:

	explicit Succeeder(const std::string &name) : DecoratorNode(name) {}
	Succeeder() : DecoratorNode("Succeeder") {}

	Status tick() override;

};

