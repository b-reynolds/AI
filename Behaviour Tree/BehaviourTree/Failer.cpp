#include "Failer.h"

Node::Status Failer::tick()
{
	getChild()->tick();
	return FAILURE;
}
