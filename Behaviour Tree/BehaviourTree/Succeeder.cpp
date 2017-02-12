#include "Succeeder.h"

Node::Status Succeeder::tick()
{
	getChild()->tick();
	return SUCCESS;
}
