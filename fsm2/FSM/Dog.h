#pragma once

#include "DogStateEat.h"
#include "DogStateSleep.h"
#include "DogStateWalk.h"

class Dog {

	DogState* State_Sleep;
	DogState* State_Eat;
	DogState* State_Walk;

public:

	DogState* Current_State;
	enum States { Sleep, Eat, Walk };

	short Energy;
	short Hunger;

	Dog();
	~Dog();

	void Change_State(States _State);

};

