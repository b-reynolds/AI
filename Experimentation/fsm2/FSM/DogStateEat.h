#pragma once
#include "DogState.h"
#include "Dog.h"

class DogStateEat : public DogState {

public:

	void Enter(Dog* _Dog) override;
	void Update(Dog* _Dog) override;
	void Exit(Dog* _Dog) override;

};

