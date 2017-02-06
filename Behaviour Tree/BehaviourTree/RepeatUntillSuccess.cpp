#include "RepeatUntillSuccess.h"

Node::Status RepeatUntillSuccess::tick()
{
	while(getChild()->tick() != SUCCESS) {}
	return SUCCESS;
}
