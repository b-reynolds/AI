#include "DogStateSleep.h"

void DogStateSleep::Eat() {
}

void DogStateSleep::Walk() {
}

void DogStateSleep::Sleep() {
	int Sheep = 100;
	for (int Counted = 0; Counted < Sheep; Counted++);
	std::cout << "Sleeping..." << std::endl;
}
