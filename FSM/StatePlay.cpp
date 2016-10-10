#include "StatePlay.h"

void StatePlay::Enter(Dog* _Dog) {
	std::cout << "Started Playing" << std::endl;
}

void StatePlay::Update(Dog* _Dog) {
	
	if(_Dog->Energy == 0) {
		_Dog->Change_State(_Dog->Sleep);
	}
	else if(_Dog->Contentment == 100) {
		_Dog->Change_State(_Dog->Walk);
	}
	else {
		std::cout << "Playing" << std::endl;
		_Dog->Contentment += 10;
		_Dog->Energy -= 10;
	}

}

void StatePlay::Exit(Dog* _Dog) {
	std::cout << "Stopped Playing" << std::endl;
}
