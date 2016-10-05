#include "DogStateWalk.h"

void DogStateWalk::Enter(Dog* _Dog) {
	std::cout << "Started walking" << std::endl;
}

void DogStateWalk::Update(Dog* _Dog) {
	_Dog->Energy = _Dog->Energy - 25 >= 0 ? _Dog->Energy - 25 : 0;
	_Dog->Hunger = _Dog->Hunger + 25 <= 100 ? _Dog->Hunger + 25 : 100;
	std::cout << "Walking... (Energy: " << _Dog->Energy << ", Hunger: " << _Dog->Hunger << ")" << std::endl;
	if(_Dog->Hunger >= 100) {
		_Dog->Change_State(_Dog->Eat);
	}
	else if(_Dog->Energy <= 0) {
		_Dog->Change_State(_Dog->Sleep);
	}
}

void DogStateWalk::Exit(Dog* _Dog) {
	std::cout << "Stopped walking" << std::endl;
}
