#pragma once
#include "State.h"
#include "StateRed.h"
#include "StateAmber.h"
#include "StateGreen.h"

class TrafficLight {

	State* State_Red;
	State* State_Amber;
	State* State_Green;

	State* State;

public:

	enum States { Red, Amber, Green };
	States Prev_State;
	DWORD Interval;

	TrafficLight();

	void Change_State(States _State);
	void Update();

};

