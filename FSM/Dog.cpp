#include "Dog.h"

Dog::Dog() {

	Energy = 100;
	Contentment = 100;
	Appetite = 0;
	Cats_Chased = 0;

	State_Chase = new StateChase;
	State_Eat = new StateEat;
	State_Play = new StatePlay;
	State_Sleep = new StateSleep;
	State_Walk = new StateWalk;

	State_Current = State_Walk;

}

Dog::~Dog() {

	delete State_Chase;
	delete State_Eat;
	delete State_Play;
	delete State_Sleep;
	delete State_Walk;

}

void Dog::Update() {

	State_Current->Update(this);

}

void Dog::Change_State(States _State) {

	State_Current->Exit(this);

	switch(_State) {
		case Chase:
			State_Current = State_Chase;
			break;
		case Eat:
			State_Current = State_Eat;
			break;
		case Play:
			State_Current = State_Play;
			break;
		case Sleep:
			State_Current = State_Sleep;
			break;
		case Walk:
			State_Current = State_Walk;
			break;
	}

	State_Current->Enter(this);

}
