#include "QuadTree.h"

QuadTree::QuadTree(sf::Vector2u windowSize, std::vector<Object>* objects)
{
	this->windowSize = windowSize;
	pObjects = objects;
	calculate();
}

void QuadTree::calculate()
{

	sf::FloatRect gridFace;

	gridFace.left = 0;
	gridFace.top = 0;
	gridFace.width = windowSize.x;
	gridFace.height = windowSize.y;

	gridFaces.push_back(gridFace);

	for(int i = 0; i < pObjects->size(); i++)
	{
		if(pObjects->at(i).getRect().intersects(gridFace))
		{
			std::cout << "Moo" << std::endl;
		}
	}
	


}

void QuadTree::draw(sf::RenderWindow* window)
{
	for(auto& gridFace : gridFaces)
	{
		window->draw(getRectangle(gridFace));
	}
}

sf::RectangleShape QuadTree::getRectangle(sf::FloatRect floatRect)
{
	sf::RectangleShape rectangle;
	rectangle.setPosition(sf::Vector2f(floatRect.left, floatRect.top));
	rectangle.setSize(sf::Vector2f(floatRect.width, floatRect.height));
	rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setOutlineThickness(-5);
	return rectangle;
}