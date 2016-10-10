#include "StateChase.h"

void StateChase::Enter(Dog* _Dog) {
	std::cout << "Started Chasing" << std::endl;
}

void StateChase::Update(Dog* _Dog) {

	std::cout << "Chasing a cat" << std::endl;
	_Dog->Contentment = 100;
	_Dog->Cats_Chased += 1;
	_Dog->Change_State(_Dog->Walk);

}

void StateChase::Exit(Dog* _Dog) {
	std::cout << "Stopped Chasing" << std::endl;
}
