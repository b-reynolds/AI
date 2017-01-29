#include "Selector.h"

/**
* Run each child in prioritive order, return true upon success, false if all fail.
*/
bool Selector::run()
{
	for(Node* child : getChildren())
	{
		if(child->run())
		{
			return true;
		}
	}
	return false;
}
