#pragma once
#include <iostream>

class Lumberjack;

class State {

public:

	virtual void Enter(Lumberjack* _LJ) = 0;
	virtual void Update(Lumberjack* _LJ) = 0;
	virtual void Exit(Lumberjack* _LJ) = 0;
	
};