#pragma once
#include "BlackboardType.h"

class BlackboardDouble : public BlackboardType
{

public:

	explicit BlackboardDouble(const double &value) : value(value) {}
	~BlackboardDouble() {}

	double getValue() const { return value; }
	void setValue(const double &value) { this->value = value; }

private:

	double value;

};

