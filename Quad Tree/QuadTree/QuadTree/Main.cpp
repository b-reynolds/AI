#include <SFML/Graphics.hpp>
#include "QuadTree.h"
#include <iostream>

int main()
{

	sf::RenderWindow window(sf::VideoMode(640, 640), "Quad Tree");

	QuadTree quadTree(BoundingBox(320, 320, 320));



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
				quadTree.insert(Coordinate(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
			}
		}

		window.clear();

		quadTree.draw(&window);

		window.display();

	}

	return 0;
}
