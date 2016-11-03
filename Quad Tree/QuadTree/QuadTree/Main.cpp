#include <SFML/Graphics.hpp>
#include "QuadTree.h"
#include <iostream>

int main()
{
	const unsigned int RESY = sf::VideoMode::getDesktopMode().height;
	unsigned int winSize = 0;
	unsigned int nodeCapacity;

	std::cout << "==========================================" << std::endl;
	std::cout << "       SFML Quadtree Implementation       " << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "(Left Click) Add new point" << std::endl;
	std::cout << "(C) Clear Quadtree" << std::endl;
	std::cout << "(ESC) Exit" << std::endl;
	std::cout << "==========================================" << std::endl;
	printf("Size (Max: %i):", RESY);
	std::cin >> winSize;
	std::cout << "Node Capacity: ";
	std::cin >> nodeCapacity;
	std::cout << "==========================================" << std::endl;

	if (winSize > RESY || winSize <= 0)
	{
		winSize = RESY;
	}

	if (nodeCapacity <= 0) {
		nodeCapacity = 1;
	}

	sf::RenderWindow window(sf::VideoMode(winSize, winSize), "Quad Tree");

	QuadTree* quadTree = new QuadTree(BoundingBox(winSize / 2, winSize / 2, winSize / 2), nodeCapacity);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			quadTree->insert(Point(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		{
			delete quadTree;
			quadTree = new QuadTree(BoundingBox(winSize / 2, winSize / 2, winSize / 2), nodeCapacity);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		window.clear();

		quadTree->draw(&window);

		for (auto& point : quadTree->queryRange(quadTree->boundary))
		{
			point.draw(&window);
		}

		window.display();

	}

	return 0;
}
