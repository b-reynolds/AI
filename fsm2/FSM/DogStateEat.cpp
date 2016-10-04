#include "DogStateEat.h"

void DogStateEat::Enter(Dog* _Dog) {

}

void DogStateEat::Update(Dog* _Dog) {
	std::cout << "Eating" << std::endl;
	_Dog->Hunger -= 25;
	if(_Dog->Hunger == 0) {
		_Dog->Change_State(_Dog->Walk);
	}
}

void DogStateEat::Exit(Dog* _Dog) {
	
}