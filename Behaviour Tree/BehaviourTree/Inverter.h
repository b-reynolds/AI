#pragma once
#include "DecoratorNode.h"

class Inverter : public DecoratorNode
{

public:

	explicit Inverter(const std::string &name) : DecoratorNode(name) {}
	Inverter() : DecoratorNode(nodeType) {}

	Status tick() override;

private:

	std::string nodeType = "Selector";

};

