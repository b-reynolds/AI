#pragma once
#include "State.h"
#include "Lumberjack.h"

class LJHarvest : public State {

	void Enter(Lumberjack* _LJ) override;
	void Update(Lumberjack* _LJ) override;
	void Exit(Lumberjack* _LJ) override;

};

