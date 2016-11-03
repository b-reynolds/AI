#include <SFML/Graphics.hpp>
#include "QuadTree.h"
#include <iostream>

int main()
{

	sf::RenderWindow window(sf::VideoMode(640, 640), "Quad Tree");

	QuadTree quadTree(BoundingBox(window.getSize().x / 2, window.getSize().y / 2, window.getSize().x / 2));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				std::cout << "MOUSE PRESSED.. inserting point.." << std::endl;
				quadTree.insert(Coordinate(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
			}
		}

		window.clear();

		quadTree.draw(&window);

		window.display();

	}

	return 0;
}
