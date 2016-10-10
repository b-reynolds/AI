#pragma once
#include <iostream>
#include <windows.h>

class TrafficLight;

class State {
	
public:

	virtual void Enter(TrafficLight* _TL) = 0;
	virtual void Update(TrafficLight* _TL) = 0;
	virtual void Exit(TrafficLight* _TL) = 0;

};
