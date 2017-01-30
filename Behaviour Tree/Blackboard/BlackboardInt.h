#pragma once
#include "BlackboardType.h"

class BlackboardInt : public BlackboardType
{

public:
	
	explicit BlackboardInt(const int &value) : value(value) {}
	~BlackboardInt() {}

	int getValue() const { return value; }

private:
	
	int value;
};

