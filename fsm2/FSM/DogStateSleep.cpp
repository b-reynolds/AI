#include "DogStateSleep.h"

void DogStateSleep::Enter(Dog* _Dog) {
	
}

void DogStateSleep::Update(Dog* _Dog) {
	std::cout << "Sleeping" << std::endl;
	_Dog->Energy += 25;
	if (_Dog->Energy >= 100) {
		_Dog->Change_State(_Dog->Walk);
	}
}

void DogStateSleep::Exit(Dog* _Dog) {
	
}