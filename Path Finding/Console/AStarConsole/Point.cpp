#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

bool Point::operator==(Point point)
{
	return this->x == point.x && this->y == point.y;
}

Point::~Point()
{
}
