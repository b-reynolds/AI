#pragma once
#include "DecoratorNode.h"

class RepeatUntillFail : public DecoratorNode
{

public:

	explicit RepeatUntillFail(const std::string &name) : DecoratorNode(name) {}
	RepeatUntillFail() : DecoratorNode("Repeat Till Fail") {}

	Status tick() override;

};

