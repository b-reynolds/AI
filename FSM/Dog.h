#pragma once
#include "State.h"
#include "StateChase.h"
#include "StateEat.h"
#include "StatePlay.h"
#include "StateSleep.h"
#include "StateWalk.h"

class Dog {

	State* State_Chase;
	State* State_Eat;
	State* State_Play;
	State* State_Sleep;
	State* State_Walk;

	State* State_Current;

public:

	enum States { Chase, Eat, Play, Sleep, Walk };
	short Energy, Appetite, Contentment;
	int Cats_Chased;

	Dog();
	~Dog();

	void Update();
	void Change_State(States _State);

};

