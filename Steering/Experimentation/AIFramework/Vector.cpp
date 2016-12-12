#include "Vector.h"

sf::Vector2f Vector::Normalize(sf::Vector2f _V) {
	float Length = sqrt(_V.x * _V.x + _V.y * _V.y);
	return sf::Vector2f(_V.x / Length, _V.y / Length);
}

sf::Vector2f Vector::Limit_Magnitude(sf::Vector2f _V, float _Max) {
	if ((_V.x * _V.x) + (_V.y * _V.y) > (_Max * _Max)) {
		_V = Normalize(_V);
		_V.x *= _Max;
		_V.y *= _Max;
	}
	return _V;
}

sf::Vector2f Vector::Multiply(sf::Vector2f _V, int _Scalar) {
	return sf::Vector2f(_V.x * _Scalar, _V.y * _Scalar);
}

sf::Vector2f Vector::Multiply(sf::Vector2f _V1, sf::Vector2f _V2) {
	return sf::Vector2f(_V1.x * _V2.x, _V1.y * _V2.y);
}

sf::Vector2f Vector::Zero() {
	return sf::Vector2f(0, 0);
}

float Vector::Magnitude(sf::Vector2f _V) {
	return sqrt(_V.x * _V.x + _V.y * _V.y);
}
