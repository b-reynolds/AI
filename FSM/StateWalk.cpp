#include "StateWalk.h"

void StateWalk::Enter(Dog* _Dog) {
	std::cout << "Started Walking" << std::endl;
}

void StateWalk::Update(Dog* _Dog) {

	if(_Dog->Energy == 0) {
		_Dog->Change_State(_Dog->Sleep);
	}
	else if(_Dog->Contentment < 10) {
		_Dog->Change_State(_Dog->Play);
	}
	else if(_Dog->Appetite == 100) {
		_Dog->Change_State(_Dog->Eat);
	}
	else if(Is_Cat_Present()) {
		_Dog->Change_State(_Dog->Chase);
	}
	else {
		std::cout << "Walking" << std::endl;
		_Dog->Energy -= 10;
		_Dog->Appetite += 10;
		_Dog->Contentment -= 10;
	}

}

void StateWalk::Exit(Dog* _Dog) {
	std::cout << "Stopped Walking" << std::endl;
}

int StateWalk::Random_Number(int _Min, int _Max) {

	std::random_device Random_Device;
	std::uniform_int_distribution<int> Random_Number(_Min, _Max);
	return Random_Number(Random_Device);

}

bool StateWalk::Is_Cat_Present() {
	return Random_Number(1, 10) == 1;
}
