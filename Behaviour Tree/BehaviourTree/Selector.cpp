#include "Selector.h"

/**
* Run each child in prioritive order, return true upon success, false if all fail.
*/
Node::Status Selector::tick()
{
	output();
	for(Node* child : getChildren())
	{
		if(child->tick() == SUCCESS)
		{
			return SUCCESS;
		}
	}
	return FAILURE;
}
