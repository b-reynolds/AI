#pragma once
#include "DecoratorNode.h"

class RepeatUntillSuccess : public DecoratorNode
{

public:

	explicit RepeatUntillSuccess(const std::string &name) : DecoratorNode(name) {}
	RepeatUntillSuccess() : DecoratorNode("Repeat Till Succeed") {}

	Status tick() override;

};

