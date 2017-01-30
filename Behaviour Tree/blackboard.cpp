#include <iostream>
#include <map>

class BlackboardBaseType
{
public:
	BlackboardBaseType() {};
	virtual ~BlackboardBaseType() {};
};

typedef std::map<const char*, BlackboardBaseType*> Blackboard;

class BlackboardBoolType : public BlackboardBaseType
{
public:
	explicit BlackboardBoolType(const bool &value) : value(value) {};
	bool getValue() const { return value; }
	void setValue(const bool &value) { this->value = value; }
private:
	bool value;
};

class BlackboardIntType : public BlackboardBaseType
{
public:
	explicit BlackboardIntType(const int &value) : value(value) {};
	int getValue() const { return value; }
	void setValue(const int &value) { this->value = value; }
private:
	int value;
};

class BlackboardFloatType : public BlackboardBaseType
{
public:
	explicit BlackboardFloatType(const float &value) : value(value) {};
	int getValue() const { return value; }
	void setValue(const float &value) { this->value = value; }
private:
	float value;
};

struct Player
{
	bool alive = true;
	int health = 100;
	float speed = 187.5f;
};

void foo(Blackboard* blackboard)
{
	bool alive = false;

	auto search = blackboard->find("isAlive");
	if (search != blackboard->end())
	{	
		auto boolType = reinterpret_cast<BlackboardBoolType*>(search->second);
		alive = boolType->getValue();
	}

	printf("Alive: %s\n", alive ? "True" : "False");

	int health = 0;
	search = blackboard->find("playerHealth");
	if (search != blackboard->end())
	{
		auto intType = reinterpret_cast<BlackboardIntType*>(search->second);
		health = intType->getValue();
	}

	printf("Health: %d\n", health);

	float speed = 0.0f;
	search = blackboard->find("playerSpeed");
	if (search != blackboard->end())
	{
		auto floatType = reinterpret_cast<BlackboardFloatType*>(search->second);
		speed = floatType->getValue();
	}

	printf("Speed: %f\n", speed);
}

int main()
{
	Player player;

	std::map<const char*, BlackboardBaseType*> blackboard;

	blackboard.insert(std::pair<const char*, BlackboardBaseType*>("isAlive", new BlackboardBoolType(player.alive)));
	blackboard.insert(std::pair<const char*, BlackboardBaseType*>("playerHealth", new BlackboardIntType(player.health)));
	blackboard.insert(std::pair<const char*, BlackboardBaseType*>("playerSpeed", new BlackboardFloatType(player.speed)));
	
	foo(&blackboard);

	getchar();

	return 0;
}