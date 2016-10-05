#include "DogStateSleep.h"

void DogStateSleep::Enter(Dog* _Dog) {

	std::cout << "Started sleeping" << std::endl;

}

void DogStateSleep::Update(Dog* _Dog) {

	_Dog->Energy = _Dog->Energy + 25 <= 100 ? _Dog->Energy + 25 : 100;
	std::cout << "Sleeping... (Energy: " << _Dog->Energy << ")" << std::endl;
	if (_Dog->Energy >= 100) {
		_Dog->Change_State(_Dog->Walk);
	}

}

void DogStateSleep::Exit(Dog* _Dog) {

	std::cout << "Stopped sleeping" << std::endl;

}