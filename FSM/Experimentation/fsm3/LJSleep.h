#pragma once
#include "State.h"
#include "Lumberjack.h"

class LJSleep : public State {

public:

	void Enter(Lumberjack *_LJ) override;
	void Update(Lumberjack *_LJ) override;
	void Exit(Lumberjack *_LJ) override;

};

