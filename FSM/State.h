#pragma once
#include <iostream>
#include <windows.h>

class Dog;

class State {
	
public:

	virtual void Enter(Dog* _Dog) = 0;
	virtual void Update(Dog* _Dog) = 0;
	virtual void Exit(Dog* _Dog) = 0;

};