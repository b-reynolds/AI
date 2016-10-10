#include "Vector2f.h"

Vector2f::Vector2f(GLfloat _X, GLfloat _Y) {
	X = _X;
	Y = _Y;
}

Vector2f Vector2f::Add(Vector2f _V1, Vector2f _V2) {
	return Vector2f(_V1.X + _V2.X, _V1.Y + _V2.Y);
}

Vector2f Vector2f::Subtract(Vector2f _V1, Vector2f _V2) {
	return Vector2f(_V1.X - _V2.X, _V1.Y - _V2.Y);
}

Vector2f Vector2f::Multiply(Vector2f _V1, Vector2f _V2) {
	return Vector2f(_V1.X * _V2.X, _V1.Y * _V2.Y);
}

Vector2f Vector2f::Multiply(Vector2f _V1, GLfloat _Scalar) {
	return Vector2f(_V1.X * _Scalar, _V1.Y * _Scalar);
}

Vector2f Vector2f::Normalize(Vector2f _V1) {
	GLfloat M = Magnitude(_V1);
	return Vector2f(_V1.X / M, _V1.Y / M);
}

GLfloat Vector2f::Magnitude(Vector2f _V1) {
	return static_cast<GLfloat>(sqrt(_V1.X * _V1.X + _V1.Y * _V1.Y));
}

Vector2f Vector2f::Zero() {
	return Vector2f(0, 0);
}


