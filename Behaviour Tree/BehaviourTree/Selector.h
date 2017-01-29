#pragma once
#include "CompositeNode.h"

/**
* Returns true upon child success, false if all fail.
*/
class Selector : public CompositeNode
{

public:
	
	bool run() override;

};

