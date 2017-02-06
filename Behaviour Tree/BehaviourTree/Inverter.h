#pragma once
#include "DecoratorNode.h"

class Inverter : public DecoratorNode
{

public:

	explicit Inverter(const std::string &name) : DecoratorNode(name) {}
	Inverter() : DecoratorNode("Selector") {}

	Status tick() override;

};

