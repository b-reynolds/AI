#pragma once
#include <glut.h>
#include "Vector2f.h"
#include "Colour.h"

class Shape {

public:

	Vector2f Position, Size;
	Colour Color;

	Shape(Vector2f _Position, Vector2f _Size, Colour _Colour);

	virtual void Draw() = 0;

	void Set_Colour(Colour _Colour);
	void Move(Vector2f _Velocity);

};

