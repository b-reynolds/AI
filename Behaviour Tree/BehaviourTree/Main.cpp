#include <cstdio>
#include "Node.h"
#include "Sequence.h"
#include "Selector.h"
#include "Windows.h"
#include "Blackboard.h"
#include "BlackboardInt.h"
#include "BlackboardBool.h"
#include "BlackboardVectorList.h"

class IsLightOn : public Node
{

public:

	explicit IsLightOn(Blackboard* blackboard) : Node("IsLightOn"), blackboard(blackboard) {}

	Status tick() override
	{
		output();
		bool lightState = false;	
		if(!blackboard->getValue("lightState", lightState))
		{
			return ERR;
		}
		return lightState ? SUCCESS : FAILURE;
	}

private:

	Blackboard* blackboard = nullptr;

};

class TurnLightOn : public Node
{

public:

	explicit TurnLightOn(Blackboard* blackboard) : Node("TurnLightOn"), blackboard(blackboard) {}

	Status tick() override
	{
		output();

		int lightPower = 0;
		if (!blackboard->getValue("lightPower", lightPower))
		{
			return ERR;
		}

		if (lightPower >= 0)
		{
			if (!blackboard->setValue("lightState", true))
			{
				return ERR;
			}
			return SUCCESS;
		}

		return FAILURE;
	}

private:

	Blackboard* blackboard = nullptr;

};

class ShineLight : public Node
{

public:

	explicit ShineLight(Blackboard* blackboard) : Node("ShineLight"), blackboard(blackboard) {}

	Status tick() override
	{
		output();

		int lightPower = 0;
		if (!blackboard->getValue("lightPower", lightPower))
		{
			return ERR;
		}

		if(lightPower > 0)
		{
			lightPower -= 25;
			if (!blackboard->setValue("lightPower", lightPower))
			{
				return ERR;
			}
			return SUCCESS;
		}
		return FAILURE;
	}

private:

	Blackboard* blackboard = nullptr;

};

int main()
{
	Blackboard blackboard;


	blackboard.insert("enemyPositions", new BlackboardVectorList(Vector2<float>(1.0f, 2.0f), Vector2<float>(2.0f, 3.0f)));

	//blackboard.insert("lightPower", new BlackboardInt(100));
	//blackboard.insert("lightState", new BlackboardBool(false));

	//Sequence rootNode("Sequence");
	//Selector checkLight;
	//
	//IsLightOn isLightOn(&blackboard);
	//TurnLightOn turnLightOn(&blackboard);
	//
	//checkLight.addChild(&isLightOn);
	//checkLight.addChild(&turnLightOn);
	//
	//rootNode.addChild(&checkLight);
	//
	//ShineLight shineLight(&blackboard);
	//
	//rootNode.addChild(&shineLight);
	//
	//printf("====================\n");
	//printf("Blackboard\n");
	//printf("====================\n");

	//blackboard.dump();

	//printf("====================\n");
	//while (rootNode.tick() == Node::SUCCESS)
	//{
	//	printf("====================\n");
	//}
	//printf("====================\n");

	//printf("Finished.\n");
	getchar();

	return 0;
}