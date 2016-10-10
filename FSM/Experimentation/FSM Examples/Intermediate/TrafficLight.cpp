#include "TrafficLight.h"

TrafficLight::TrafficLight() {

	State_Red = new StateRed;
	State_Amber = new StateAmber;
	State_Green = new StateGreen;
	State = State_Red;

	Interval = 1000;

	State->Enter(this);

}

void TrafficLight::Change_State(States _State) {

	State->Exit(this);

	switch(_State) {
		case Red:
			State = State_Red;
			break;
		case Amber:
			State = State_Amber;
			break;
		case Green:
			State = State_Green;
			break;
	default: break;
	}

	State->Enter(this);

}

void TrafficLight::Update() {

	State->Update(this);

}