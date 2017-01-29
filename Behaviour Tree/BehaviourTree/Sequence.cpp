#include "Sequence.h"

/**
* Run each child in prioritive order, return false upon failure, true if all succeed.
*/
bool Sequence::run()
{
	for(Node* child : getChildren())
	{
		if(!child->run())
		{
			return false;
		}
	}
	return true;
}
