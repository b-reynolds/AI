#pragma once
#include "Shape.h"

class Quad : public Shape {

public:

	Quad(Vector2f _Position, Vector2f _Size, Colour _Colour) : Shape(_Position, _Size, _Colour) {};

	void Draw() override;

};

