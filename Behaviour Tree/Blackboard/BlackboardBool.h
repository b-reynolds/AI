#pragma once
#include "BlackboardType.h"

class BlackboardBool : public BlackboardType
{

public:

	explicit BlackboardBool(const bool &value) : value(value) {}
	~BlackboardBool() {}

	bool getValue() const { return value; }

private:

	bool value;

};

