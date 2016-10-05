#include "DogStateEat.h"

void DogStateEat::Enter(Dog* _Dog) {
	std::cout << "Started eating" << std::endl;
}

void DogStateEat::Update(Dog* _Dog) {
	_Dog->Hunger = _Dog->Hunger - 25 >= 0 ? _Dog->Hunger - 25 : 0;
	std::cout << "Eating... (Hunger: " << _Dog->Hunger << ")" << std::endl;
	if(_Dog->Hunger == 0) {
		_Dog->Change_State(_Dog->Walk);
	}
}

void DogStateEat::Exit(Dog* _Dog) {
	std::cout << "Stopped eating" << std::endl;
}