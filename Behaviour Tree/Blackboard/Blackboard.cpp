#include "Blackboard.h"
#include "BlackboardInt.h"
#include "BlackboardFloat.h"
#include "BlackboardString.h"
#include "BlackboardDouble.h"
#include "BlackboardChar.h"

/** Destructor
 * @brief Free allocated memory 
 */
Blackboard::~Blackboard()
{
	for(auto &item : map)
	{
		delete item.second;
	}
}

/** 
 * @brief Insert a new item into the blackboard
 * @param name The key/name used for future reference
 * @param item The item to store
 * @return void
 */
void Blackboard::insert(const char* name, BlackboardType* item)
{
	map.insert(std::pair<const char*, BlackboardType*>(name, item));
}

/**
 * @brief Update an item in the blackboard
 * @param name The key/name of the item to update
 * @param item The item to store
 * @return bool
 */
[[deprecated]] // TODO: Remove/Revamp (Dangling pointer potential)
bool Blackboard::update(const char* name, BlackboardType* item) 
{
	auto result = map.find(name);
	if(result != map.end())
	{
		delete result->second;
		result->second = item;
		return true;
	}
	return false;
}

/**
 * @brief Remove all items with the specified key from the blackboard
 * @param name The key/name of the item(s) to delete
 * @return void
 */
void Blackboard::remove(const char* name)
{
	std::map<const char*, BlackboardType*>::iterator iterator = map.begin();
	while(iterator != map.end())
	{
		if(iterator->first == name)
		{
			delete iterator->second;
			iterator = map.erase(iterator);
		}
		else
		{
			++iterator;
		}
	}
}

/**
 * @brief Search for and retrieve an int from the blackboard
 * @param name The key to search the blackboard for
 * @param out The output variable to store the value in
 * @return bool
 */
bool Blackboard::getValue(const char* name, int &out)
{
	auto result = map.find(name);
	if(result != map.end())
	{
		out = reinterpret_cast<BlackboardInt*>(result->second)->getValue();
		return true;
	}
	return false;
}

/**
* @brief Search for and retrieve a float from the blackboard
* @param name The key to search the blackboard for
* @param out The output variable to store the value in
* @return bool
*/
bool Blackboard::getValue(const char* name, float &out)
{
	auto result = map.find(name);
	if (result != map.end())
	{
		out = reinterpret_cast<BlackboardFloat*>(result->second)->getValue();
		return true;
	}
	return false;
}

/**
* @brief Search for and retrieve a double from the blackboard
* @param name The key to search the blackboard for
* @param out The output variable to store the value in
* @return bool
*/
bool Blackboard::getValue(const char* name, double &out)
{
	auto result = map.find(name);
	if (result != map.end())
	{
		out = reinterpret_cast<BlackboardDouble*>(result->second)->getValue();
		return true;
	}
	return false;
}

/**
* @brief Search for and retrieve a char from the blackboard
* @param name The key to search the blackboard for
* @param out The output variable to store the value in
* @return bool
*/
bool Blackboard::getValue(const char* name, char &out)
{
	auto result = map.find(name);
	if (result != map.end())
	{
		out = reinterpret_cast<BlackboardChar*>(result->second)->getValue();
		return true;
	}
	return false;
}

/**
* @brief Search for and retrieve a string from the blackboard
* @param name The key to search the blackboard for
* @param out The output variable to store the value in
* @return bool
*/
bool Blackboard::getValue(const char* name, std::string &out)
{
	auto result = map.find(name);
	if (result != map.end())
	{
		out = reinterpret_cast<BlackboardString*>(result->second)->getValue();
		return true;
	}
	return false;
}

/**
 * @brief Search for and returns a pointer to an item in the blackboard
 * @param name The key to search the blackboard for
 * @return BlackboardType*
 */
BlackboardType* Blackboard::getPointer(const char* name)
{
	auto result = map.find(name);
	if (result != map.end())
	{
		return result->second;
	}
	return nullptr;
}

/**
 * @brief Output the contents of the blackboard to the console
 * @return void
 */
void Blackboard::dump()
{
	int count = 0;
	for(auto &item : map)
	{
		printf("[%d] \"%s\" (%p)\n", count++, item.first, item.second);
	}
}
