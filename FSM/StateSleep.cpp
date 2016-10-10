#include "StateSleep.h"

void StateSleep::Enter(Dog* _Dog) {
	std::cout << "Started Sleeping" << std::endl;
}

void StateSleep::Update(Dog* _Dog) {

	if(_Dog->Energy == 100) {
		_Dog->Change_State(_Dog->Walk);
	}
	else {
		std::cout << "Sleeping" << std::endl;
		_Dog->Energy += 10;
	}

}

void StateSleep::Exit(Dog* _Dog) {
	std::cout << "Stopped Sleeping" << std::endl;
}
