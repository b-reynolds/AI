#pragma once
#include "BlackboardType.h"

class BlackboardFloat : public BlackboardType 
{

public:

	explicit BlackboardFloat(const float &value) : value(value) {}
	~BlackboardFloat() {}

	float getValue() const { return value; }

private:

	float value;

};

