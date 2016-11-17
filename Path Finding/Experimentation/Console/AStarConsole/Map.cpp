#include "Map.h"

Map::Map(Point size)
{
	this->size = size;
	map.resize(this->size.x, std::vector<int>(this->size.y, true));
}

void Map::print()
{
	for (int y = 0; y < size.y; ++y)
	{
		for (int x = 0; x < size.x; ++x)
		{
			switch (getValue(Point(y, x)))
			{
				case 0:
					printf(" # ");
					break;
				case 1:
					printf(" . ");
					break;
				case 2:
					printf(" X ");
					break;
				case 3:
					printf(" S ");
					break;
				case 4:
					printf(" E ");
					break;

			}
		}
		printf("\n");
	}
}

void Map::setMap(std::vector<std::vector<int>> map)
{
	for(int y = 0; y < size.y; ++y)
	{
		for(int x = 0; x < size.x; ++x)
		{
			this->map[y][x] = map[y][x];
		}
	}
}

void Map::setValue(Point position, int value)
{
	map[position.y][position.x] = value;
}

int Map::getValue(Point position)
{
	return map[position.x][position.y];
}

Map::~Map()
{
}
