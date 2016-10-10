#include "StateRed.h"

void StateRed::Enter(TrafficLight* _TL) {

	system("Color 4");

}

void StateRed::Update(TrafficLight* _TL) {

	std::cout << "Red" << std::endl;
	Sleep(_TL->Interval);
	_TL->Change_State(_TL->Amber);

}

void StateRed::Exit(TrafficLight* _TL) {

	_TL->Prev_State = _TL->Red;
	system("cls");

}
