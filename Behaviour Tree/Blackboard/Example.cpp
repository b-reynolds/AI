#include <cstdio>
#include "Blackboard.h"
#include "BlackboardInt.h"
#include "BlackboardFloat.h"
#include "BlackboardString.h"

int main()
{
	Blackboard myBlackboard;

	myBlackboard.insert("Name", new BlackboardString("John Smith"));
	myBlackboard.insert("Age", new BlackboardInt(50));
	myBlackboard.insert("Balance", new BlackboardFloat(2500.0f));

	std::string name = "";
	myBlackboard.get("Name", name);

	int age = 0;
	myBlackboard.get("Age", age);

	float balance = 0.0f;
	myBlackboard.update("Balance", new BlackboardFloat(5000.0f));
	myBlackboard.get("Balance", balance);

	printf("Name: %s\nAge: %d\nBalance: %f", name.c_str(), age, balance);

	// --------------------
	// Output
	// --------------------
	// Name: John Smith
	// Age: 50
	// Balance: 5000.000000
	// --------------------

	getchar();
	return 0;
}