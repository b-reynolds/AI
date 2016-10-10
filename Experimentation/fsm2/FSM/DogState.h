#pragma once
#include <iostream>

class Dog;

class DogState {

public:

	virtual void Enter(Dog* _Dog) = 0;
	virtual void Update(Dog* _Dog) = 0;
	virtual void Exit(Dog* _Dog) = 0;

};
