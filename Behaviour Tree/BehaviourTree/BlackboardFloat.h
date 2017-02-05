#pragma once
#include "BlackboardType.h"

class BlackboardFloat : public BlackboardType 
{

public:

	explicit BlackboardFloat(const float &value) : value(value) {}
	~BlackboardFloat() {}

	float getValue() const { return value; }
	void setValue(const float &value) { this->value = value; }

private:

	float value;

};

