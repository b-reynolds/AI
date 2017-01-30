#pragma once
#include "BlackboardType.h"

class BlackboardBool : public BlackboardType
{

public:

	explicit BlackboardBool(const bool &value) : value(value) {}
	~BlackboardBool() {}

	bool getValue() const { return value; }
	void setValue(const bool &value) { this->value = value; }

private:

	bool value;

};

