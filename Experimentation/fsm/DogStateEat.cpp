#include "DogStateEat.h"

void DogStateEat::Eat() {
	int Food = 100;
	while (Food != 0) { Food--; }
	std::cout << "Eating..." << std::endl;
}

void DogStateEat::Walk() {
}

void DogStateEat::Sleep() {
}
