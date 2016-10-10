#pragma once
#include "DogState.h"

class DogStateSleep : public DogState {

public:

	void Eat() override;
	void Walk() override;
	void Sleep() override;

};

