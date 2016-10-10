#include "DogStateWalk.h"

void DogStateWalk::Eat() {
}

void DogStateWalk::Walk() {
	bool Tired = false;
	for (int Steps = 0; !Tired; Steps++)
		Tired = Steps >= 1000;
	std::cout << "Walking..." << std::endl;
}

void DogStateWalk::Sleep() {
}
