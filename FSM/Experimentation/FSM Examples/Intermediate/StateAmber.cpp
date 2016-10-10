#include "StateAmber.h"

void StateAmber::Enter(TrafficLight* _TL) {

	system("Color E");

}

void StateAmber::Update(TrafficLight* _TL) {

	std::cout << "Amber" << std::endl;
	Sleep(_TL->Interval);
	_TL->Change_State(_TL->Prev_State == _TL->Red ? _TL->Green : _TL->Red);

}

void StateAmber::Exit(TrafficLight* _TL) {

	system("cls");

}
