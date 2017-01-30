#pragma once
#include <map>

class BlackboardType;

class Blackboard
{

public:

	~Blackboard();

	void insert(const char* name, BlackboardType* item);
	void remove(const char* name);

	bool getValue(const char* name, int &out);
	bool getValue(const char* name, float &out);
	bool getValue(const char* name, double &out);
	bool getValue(const char* name, char &out);
	bool getValue(const char* name, std::string &out);

	bool setValue(const char* name, const int &value);
	bool setValue(const char* name, const float &value);
	bool setValue(const char* name, const double &value);
	bool setValue(const char* name, const char &value);
	bool setValue(const char* name, const std::string &value);

	// TODO:: Add setters! that reinterpet cast appropriately  

	BlackboardType* getPointer(const char* name);

	void dump();

private:

	std::map<const char*, BlackboardType*> map;

};
