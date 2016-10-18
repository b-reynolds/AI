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

sf::Vector2f Vector::Zero() {
	return sf::Vector2f(0, 0);
}