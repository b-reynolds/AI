#pragma once

/**
 * Base class for each node in the behaviour tree
 */
class Node
{

public:

	enum Status { ERROR, FAILURE, SUCCESS, RUNNING };

	virtual ~Node() {}
	virtual Status tick() = 0;

};

