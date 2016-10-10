#pragma once
#include "DogState.h"

class DogStateWalk : public DogState {

public:

	void Eat() override;
	void Walk() override;
	void Sleep() override;

};