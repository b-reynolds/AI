#pragma once

#include "DogStateEat.h"
#include "DogStateSleep.h"
#include "DogStateWalk.h"

class Dog {

	DogState* State_Sleep;
	DogState* State_Eat;
	DogState* State_Walk;

	DogState* Current_State;

public:

	enum States { Sleep, Eat, Walk };

	short Energy;
	short Hunger;

	Dog();
	~Dog();

	void Update();

	void Change_State(States _State);

};

