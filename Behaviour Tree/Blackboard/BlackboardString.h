#pragma once
#include "BlackboardType.h"
#include <string>

class BlackboardString : public BlackboardType
{

public:

	explicit BlackboardString(const std::string &value) : value(value) {}
	~BlackboardString() {}

	std::string getValue() const { return value; }

private:

	std::string value;

};

