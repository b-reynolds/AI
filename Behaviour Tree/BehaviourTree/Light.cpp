//#include <cstdio>
//#include <Windows.h>
//#include "Node.h"
//#include "Sequence.h"
//#include "Selector.h"
//
//class Light
//{
//
//public:
//
//	const int MAX_POWER = 10;
//	const int MIN_POWER = 1;
//
//	Light() : state(false), power(MAX_POWER) {}
//
//	bool turnOn() { if (power > 0) state = true; return state; }
//	bool shine() { power -= 1; if (power < MIN_POWER) state = false; return state; }
//
//	bool getState() const { return state; }
//	int getPower() const { return power; }
//
//private:
//
//	bool state;
//	int power;
//
//};
//
//class IsLightOn : public Node
//{
//
//public:
//
//	explicit IsLightOn(Light* light) : light(light) {}
//
//	bool run() override
//	{
//		bool lightState = light->getState();
//		printf("IsLightOn: %s\n", lightState ? "Yes" : "No");
//		return lightState;
//	}
//
//private:
//
//	Light* light;
//
//};
//
//class TurnLightOn : public Node
//{
//
//public:
//
//	explicit TurnLightOn(Light* light) : light(light) {}
//
//	bool run() override
//	{
//		bool lightState = light->turnOn();
//		printf("TurnLightOn: %s\n", lightState ? "Success" : "Fail");
//		return lightState;
//	}
//
//private:
//
//	Light* light;
//
//};
//
//class ShineLight : public Node
//{
//
//public:
//
//	explicit ShineLight(Light* light) : light(light) {}
//
//	bool run() override
//	{
//		bool lightState = light->shine();
//		int lightPower = light->getPower();
//		printf("Light Power: %d, State: %s\n", lightPower, lightState ? "On" : "Off");
//		return lightState;
//	}
//
//private:
//
//	Light* light;
//
//};
//
//int main()
//{
//	Light light;
//
//	Sequence rootNode;
//	Sequence mainSequence;
//	Selector checkLight;
//
//	IsLightOn isLightOn(&light);
//	TurnLightOn turnLightOn(&light);
//
//	checkLight.addChild(&isLightOn);
//	checkLight.addChild(&turnLightOn);
//
//	mainSequence.addChild(&checkLight);
//
//	ShineLight shineLight(&light);
//
//	mainSequence.addChild(&shineLight);
//
//	rootNode.addChild(&mainSequence);
//
//	while (mainSequence.run()) { Sleep(500); }
//
//	getchar();
//	return 0;
//}