#include "Shape.h"

Shape::Shape(Vector2f _Position, Vector2f _Size, Colour _Colour) {

	Position = _Position;
	Size = _Size;
	Color = _Colour;

}

void Shape::Set_Colour(Colour _Colour) {
	Color = _Colour;
}

void Shape::Move(Vector2f _Velocity) {
	Position = Vector2f::Add(Position, _Velocity);
}
