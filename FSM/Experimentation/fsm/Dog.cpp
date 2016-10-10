#include "Dog.h"
#include "DogStateEat.h"
#include "DogStateWalk.h"
#include "DogStateSleep.h"

Dog::Dog() {
	State_Walk = new DogStateWalk;
	State_Eat = new DogStateEat;
	State_Sleep = new DogStateSleep;
	State = State_Sleep;
}

Dog::~Dog() {
	delete State_Walk;
	delete State_Eat;
	delete State_Sleep;
}

void Dog::Live() {

	if(State == State_Sleep) {
		Sleep();
		State = State_Eat;
	}
	else if(State == State_Eat) {
		Eat();
		State = State_Walk;
	}
	else if(State == State_Walk) {
		Walk();
		State = State_Sleep;
	}

}

void Dog::Eat() {
	State->Eat();
}

void Dog::Walk() {
	State->Walk();
}

void Dog::Sleep() {
	State->Sleep();
}
