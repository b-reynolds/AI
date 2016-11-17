#pragma once
#include <vector>
#include "Point.h"

class Map
{

private:

	Point size;
	std::vector<std::vector<int>> map;

public:

	explicit Map(Point size);

	void print();

	void setMap(std::vector<std::vector<int>> map);
	void setValue(Point position, int value);
	int getValue(Point position);

	~Map();

};

