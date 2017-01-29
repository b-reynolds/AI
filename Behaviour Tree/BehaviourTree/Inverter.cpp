#include "Inverter.h"

bool Inverter::run()
{
	return !getChild()->run();
}
