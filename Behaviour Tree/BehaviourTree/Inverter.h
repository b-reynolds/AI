#pragma once
#include "DecoratorNode.h"

class Inverter : public DecoratorNode
{

private:

	bool run() override;

};

