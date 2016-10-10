#include "StateGreen.h"

void StateGreen::Enter(TrafficLight* _TL) {

	system("Color 2");

}

void StateGreen::Update(TrafficLight* _TL) {

	std::cout << "Green" << std::endl;
	Sleep(_TL->Interval);
	_TL->Change_State(_TL->Amber);

}

void StateGreen::Exit(TrafficLight* _TL) {

	_TL->Prev_State = _TL->Green;
	system("cls");

}
