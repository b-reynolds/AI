#pragma once
#include "DecoratorNode.h"

class Inverter : public DecoratorNode
{

private:

	Status tick() override;

};

