#pragma once
#include <map>

class BlackboardType;

class Blackboard
{

public:

	~Blackboard();

	void insert(const char* name, BlackboardType* item);
	bool update(const char* name, BlackboardType* item);	
	void remove(const char* name);

	bool get(const char* name, int &out);
	bool get(const char* name, float &out);
	bool get(const char* name, std::string &out);

	void dump();

private:

	std::map<const char*, BlackboardType*> map;

};
