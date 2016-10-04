#include "DogStateWalk.h"

void DogStateWalk::Enter(Dog* _Dog) {

}

void DogStateWalk::Update(Dog* _Dog) {
	std::cout << "Walking" << std::endl;
	_Dog->Energy -= 25;
	_Dog->Hunger += 25;
	if(_Dog->Hunger >= 50) {
		_Dog->Change_State(_Dog->Eat);
	}
	else if(_Dog->Energy <= 0) {
		_Dog->Change_State(_Dog->Sleep);
	}
}

void DogStateWalk::Exit(Dog* _Dog) {

}
