#include <SFML/Graphics.hpp>
#include "QuadTree.h"

int main()
{

	const unsigned int RESY = sf::VideoMode::getDesktopMode().height;

	unsigned int winSize = 0;
	unsigned int nodeCapacity;

	printf("==========================================\n");
	printf("       SFML Quadtree Implementation       \n");
	printf("==========================================\n");
	printf(" (Left Click) Add point\n");
	printf(" (C) Clear Quadtree\n");
	printf(" (ESC) Exit\n");
	printf("==========================================\n");
	printf(" Window Size (128-%i): ", RESY);
	scanf_s("%u", &winSize);
	printf(" Node Capacity (1-16): ");
	scanf_s("%u", &nodeCapacity);
	printf("==========================================\n");

	if (winSize > RESY || winSize < 128)
	{
		winSize = RESY;
	}

	if (nodeCapacity <= 0 || nodeCapacity > 16)
	{
		nodeCapacity = 1;
	}

	sf::RenderWindow window(sf::VideoMode(winSize, winSize), "Quad Tree", sf::Style::Close);

	QuadTree* quadTree = new QuadTree(BoundingBox(winSize / 2, winSize / 2, winSize / 2), nodeCapacity);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
			{
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::C)
			{
				delete quadTree;
				quadTree = new QuadTree(BoundingBox(winSize / 2, winSize / 2, winSize / 2), nodeCapacity);
			}
			else if (event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				quadTree->insert(Point(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
			}
			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				quadTree->insert(Point(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
			}
		}

		window.clear(sf::Color(220, 220, 220));

		quadTree->draw(&window);

		window.display();

	}

	return 0;

}
