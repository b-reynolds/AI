#pragma once
#include <map>

class BlackboardType;

class Blackboard
{

public:

	~Blackboard();

	void insert(std::string &name, BlackboardType* item);
	void remove(std::string &name);

	bool getValue(std::string &name, int &out);
	bool getValue(std::string &name, float &out);
	bool getValue(std::string &name, double &out);
	bool getValue(std::string &name, char &out);
	bool getValue(std::string &name, std::string &out);

	bool setValue(std::string &name, const int &value);
	bool setValue(std::string &name, const float &value);
	bool setValue(std::string &name, const double &value);
	bool setValue(std::string &name, const char &value);
	bool setValue(std::string &name, const std::string &value);

	BlackboardType* getPointer(std::string &name);

	void dump();

private:

	std::map<std::string, BlackboardType*> map;

};
