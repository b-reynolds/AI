#include "Inverter.h"

Node::Status Inverter::tick()
{
	return getChild()->tick() ? FAILURE : SUCCESS;
}
