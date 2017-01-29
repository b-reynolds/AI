#pragma once
#include "CompositeNode.h"

/**
 * Returns false upon child failure, true if all succeed.
 */
class Sequence : public CompositeNode
{

public:

	bool run() override;

};

