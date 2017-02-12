#pragma once
#include "CompositeNode.h"

/**
 * Returns false upon child failure, true if all succeed.
 */
class Sequence : public CompositeNode
{

public:

	explicit Sequence(const std::string &name) : CompositeNode(name) {}
	Sequence() : CompositeNode("Sequence") {}

	Status tick() override;

};

