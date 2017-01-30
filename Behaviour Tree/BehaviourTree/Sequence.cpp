#include "Sequence.h"

/**
* Run each child in prioritive order, return false upon failure, true if all succeed.
*/
Node::Status Sequence::tick()
{
	for(Node* child : getChildren())
	{
		if(child->tick() == FAILURE)
		{
			return FAILURE;
		}
	}
	return SUCCESS;
}
