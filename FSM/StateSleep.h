#pragma once
#include "State.h"
#include "Dog.h"

class StateSleep : public State {

public:

	void Enter(Dog* _Dog) override;
	void Update(Dog* _Dog) override;
	void Exit(Dog* _Dog) override;

};

