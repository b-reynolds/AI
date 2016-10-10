#include "StateEat.h"

void StateEat::Enter(Dog* _Dog) {
	std::cout << "Started Eating" << std::endl;
}

void StateEat::Update(Dog* _Dog) {

	if(_Dog->Appetite == 0) {
		_Dog->Change_State(_Dog->Walk);
	}
	else {
		std::cout << "Eating" << std::endl;
		_Dog->Appetite -= 10;
	}

}

void StateEat::Exit(Dog* _Dog) {
	std::cout << "Stopped Eating" << std::endl;
}
