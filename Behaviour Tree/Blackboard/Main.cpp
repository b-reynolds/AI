#include <cstdio>
#include "Blackboard.h"
#include "BlackboardInt.h"
#include "BlackboardChar.h"
#include <string>
#include "BlackboardString.h"

int main()
{
	Blackboard myBlackboard;

	for(int i = 0; i < 10; ++i)
	{
		myBlackboard.insert(std::to_string(i), new BlackboardInt(i));
	}

	myBlackboard.insert("My Thing", new BlackboardInt(100));
	myBlackboard.insert("My OtherThing", new BlackboardString("Hey"));

	std::string myString;
	if (!myBlackboard.getValue("My Other Thing", myString))
		printf("Value doesn't exist!\n");


	myBlackboard.dump();

	getchar();
	return 0;
}
