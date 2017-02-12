#pragma once

template <typename T>
class Vector2
{
public:

	T x;
	T y;

	Vector2(const T &x, const T &y) : x(x), y(y) {}
	Vector2() : x(0), y(0) {}
};