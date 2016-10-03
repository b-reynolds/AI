#pragma once
#include "DogState.h"
#include <string>

class Dog {

	DogState* State_Eat;
	DogState* State_Walk;
	DogState* State_Sleep;

	DogState* State;

	std::string Name;

public:

	Dog();

	void Live();

	void Eat();
	void Walk();
	void Sleep();

};

