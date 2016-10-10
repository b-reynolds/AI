#pragma once
#include <glut.h>

class Vector2f {

public:

	GLfloat X, Y;

	Vector2f(GLfloat _X, GLfloat _Y);

	static Vector2f Add(Vector2f _V1, Vector2f _V2);
	static Vector2f Subtract(Vector2f _V1, Vector2f _V2);
	static Vector2f Multiply(Vector2f _V1, Vector2f _V2);
	static Vector2f Multiply(Vector2f _V1, GLfloat _Scalar);
	static Vector2f Zero();

};

