#pragma once
class Point
{

public:

	int x;
	int y;

	Point();
	Point(int x, int y);

	bool operator== (Point point);

	~Point();

};

