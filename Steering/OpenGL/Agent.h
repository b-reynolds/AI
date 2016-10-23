#pragma once
#include "Vector2f.h"
#include "Colour.h"
#include <glut.h>

class Agent {

public:

	Vector2f Location, Size;
	Vector2f Velocity, Acceleration;
	GLfloat Max_Speed, Max_Force;
	Colour Color;

	Agent(Vector2f _Location, Vector2f _Size, Colour _Colour);

	void Draw();
	void Seek(Vector2f _Target);
	void Update();
	void Add_Force(Vector2f _Force);

};


