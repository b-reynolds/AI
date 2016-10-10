#pragma once
#include "State.h"
#include "TrafficLight.h"

class StateAmber : public State {

public:

	void Enter(TrafficLight* _TL) override;
	void Update(TrafficLight* _TL) override;
	void Exit(TrafficLight* _TL) override;

};

