#pragma once
#include "BlackboardType.h"

class BlackboardChar : public BlackboardType
{

public:

	explicit BlackboardChar(const char &value) : value(value) {}
	~BlackboardChar() {}

	char getValue() const { return value; }
	void setValue(const char &value) { this->value = value; }

private:

	char value;

};

