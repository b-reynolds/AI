#include <SFML/Graphics.hpp>
#include <deque>
#include <stack>
#include "Map.h"
#include "Node.h"
#include "PathFinder.h"

const int TILE_SIZE = 24;
const int TILES_X = 50;
const int TILES_Y = 28;

const int WIN_X = TILES_X * TILE_SIZE;
const int WIN_Y = TILES_Y * TILE_SIZE;

bool mouseWithinWindow(sf::RenderWindow &window)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	return mousePosition.x > 0 && mousePosition.x < window.getSize().x && mousePosition.y > 0 && mousePosition.y < window.getSize().y;
}

int main()
{

	Map map(sf::Vector2i(TILES_X, TILES_Y), TILE_SIZE);
	
	sf::Vector2i startPosition(1, 1);
	sf::Vector2i destination(2, 1);

	PathFinder pf;
	
	sf::RenderWindow window(sf::VideoMode(WIN_X, WIN_Y), "A* Path Finding", sf::Style::Close);

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
			if(event.type == sf::Event::KeyPressed && mouseWithinWindow(window))
			{
				sf::Vector2i mouseToArray = sf::Vector2i(sf::Mouse::getPosition(window).x / TILE_SIZE, sf::Mouse::getPosition(window).y / TILE_SIZE);
				switch(event.key.code)
				{
					case sf::Keyboard::S:
						map.setValue(startPosition, map.TILE_EMPTY);
						map.setValue(mouseToArray, map.TILE_START);
						startPosition = mouseToArray;
						break;
					case sf::Keyboard::E:
						map.setValue(destination, map.TILE_EMPTY);
						map.setValue(mouseToArray, map.TILE_END);
						destination = mouseToArray;
						break;
					case sf::Keyboard::C:
						map.clear();
						break;
					case sf::Keyboard::Space:
						map.reset();
						std::stack<sf::Vector2i> path = pf.findPath(map, startPosition, destination);
						while (path.size() > 0)
						{
							sf::Vector2i point = path.top();
							map.setValue(point, map.TILE_PATH);
							path.pop();
						}
						map.setValue(startPosition, map.TILE_START);
						map.setValue(destination, map.TILE_END);
						break;
				}
			}
		}

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseWithinWindow(window))
		{
			sf::Vector2i mouseToArray = sf::Vector2i(sf::Mouse::getPosition(window).x / TILE_SIZE, sf::Mouse::getPosition(window).y / TILE_SIZE);
			map.setValue(mouseToArray, map.TILE_SOLID);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && mouseWithinWindow(window))
		{
			sf::Vector2i mouseToArray = sf::Vector2i(sf::Mouse::getPosition(window).x / TILE_SIZE, sf::Mouse::getPosition(window).y / TILE_SIZE);
			map.setValue(mouseToArray, map.TILE_EMPTY);
		}

		window.clear();

		map.draw(&window);

		window.display();


	}

	return 0;
}