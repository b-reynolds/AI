#pragma once
#include "State.h"
#include "Dog.h"
#include <random>

class StateWalk : public State {

public:

	void Enter(Dog* _Dog) override;
	void Update(Dog* _Dog) override;
	void Exit(Dog* _Dog) override;

	static int Random_Number(int _Min, int _Max);
	static bool Is_Cat_Present();

};

