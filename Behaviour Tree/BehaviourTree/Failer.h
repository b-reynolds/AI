#pragma once
#include "DecoratorNode.h"

class Failer : public DecoratorNode
{

public:

	explicit Failer(const std::string &name) : DecoratorNode(name) {}
	Failer() : DecoratorNode("Failer") {}

	Status tick() override;

};

