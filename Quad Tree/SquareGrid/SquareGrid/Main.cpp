#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Object.h"

int main()
{

	sf::Texture txtObject;
	if (!txtObject.loadFromFile("sprite.png"))
	{
		return 1;
	}

	Grid grid;
	std::vector<Object> objects;

	sf::RenderWindow window(sf::VideoMode(640, 640), "Square Grid");

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if(event.type == sf::Event::MouseButtonPressed)
			{
				Object newObject(&txtObject);
				newObject.setPosition(sf::Vector2f(sf::Mouse::getPosition(window).x - newObject.getSize().x / 2, sf::Mouse::getPosition(window).y - newObject.getSize().y / 2));
				objects.push_back(newObject);
				grid.update(&objects);
			}
			else if(event.type == sf::Event::KeyPressed)
			{
				objects.clear();
				grid.update(&objects);
			}
		}

		window.clear(sf::Color::Black);

		grid.draw(&window);

		for(auto& object : objects)
		{
			object.draw(&window);
		}

		window.display();

	}

	return 0;
}
