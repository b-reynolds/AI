#pragma once

/**
 * Base class for each node in the behaviour tree
 */
class Node
{

public:

	virtual ~Node() {}
	virtual bool run() = 0;

};

