#pragma once
#include <map>

class BlackboardType;

class Blackboard
{

public:

	~Blackboard();

	void insert(const std::string &name, BlackboardType* item);
	void remove(const std::string &name);

	bool getValue(const std::string &name, int &out);
	bool getValue(const std::string &name, float &out);
	bool getValue(const std::string &name, double &out);
	bool getValue(const std::string &name, char &out);
	bool getValue(const std::string &name, std::string &out);
	bool getValue(const std::string &name, bool &out);

	bool setValue(const std::string &name, const int &value);
	bool setValue(const std::string &name, const float &value);
	bool setValue(const std::string &name, const double &value);
	bool setValue(const std::string &name, const char &value);
	bool setValue(const std::string &name, const std::string &value);
	bool setValue(const std::string &name, const bool &value);

	BlackboardType* getPointer(const std::string &name);

	void dump();

private:

	std::map<std::string, BlackboardType*> map;

};
