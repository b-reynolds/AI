#pragma once
#include "DogState.h"

class DogStateEat : public DogState {

public:

	void Eat() override;
	void Walk() override;
	void Sleep() override;

};

