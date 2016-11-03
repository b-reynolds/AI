#include "Grid.h"

Grid::Grid()
{
}

void Grid::update(std::vector<Object>* objects)
{

	gridSpaces[0][0] = { 0 };


	for (int y = 0; y < GRIDY; y++)
	{
		for (int x = 0; x < GRIDX; x++)
		{
			gridSpaces[x][y] = 0;
			sf::FloatRect currentCell;
			currentCell.left = x * CELLSIZEX;
			currentCell.top = y * CELLSIZEY;
			currentCell.width = CELLSIZEX;
			currentCell.height = CELLSIZEY;
			for (auto& object : *objects)
			{
				if (currentCell.intersects(object.getRect()))
				{
					gridSpaces[x][y] = 1;
					break;
				}
			}
		}
	}


}

void Grid::draw(sf::RenderWindow* window) const
{
	for(int y = 0; y < GRIDY; y++)
	{
		for(int x = 0; x < GRIDX; x++)
		{
			sf::RectangleShape currentCell;
			currentCell.setPosition(sf::Vector2f(x * CELLSIZEX, y * CELLSIZEY));
			currentCell.setSize(sf::Vector2f(CELLSIZEX, CELLSIZEY));
			currentCell.setFillColor(gridSpaces[x][y] == 1 ? sf::Color(125, 25, 25) : sf::Color(25, 25, 25));
			currentCell.setOutlineColor(sf::Color::Black);
			currentCell.setOutlineThickness(-1);
			window->draw(currentCell);
		}
	}
}
