#pragma once
#include <iostream>

class DogState {

public:

	virtual void Eat() = 0;
	virtual void Walk() = 0;
	virtual void Sleep() = 0;

};

