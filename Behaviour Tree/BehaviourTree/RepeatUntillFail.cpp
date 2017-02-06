#include "RepeatUntillFail.h"

Node::Status RepeatUntillFail::tick()
{
	while (getChild()->tick() != FAILURE) {}
	return SUCCESS;
}
