#include <SFML/Graphics.hpp>
#include "Object.h"
#include "QuadTree.h"

int main()
{

	sf::Texture txtObject;
	if(!txtObject.loadFromFile("sprite.png"))
	{
		return 1;
	}


	sf::RenderWindow window(sf::VideoMode(640, 640), "Quad Tree");

	std::vector<Object> objects;

	Object myObject(&txtObject);
	myObject.setPosition(sf::Vector2f(32, 32));
	objects.push_back(myObject);

	Object myOtherObject(&txtObject);
	myOtherObject.setPosition(sf::Vector2f(576, 576));
	objects.push_back(myOtherObject);

	QuadTree quadTree(window.getSize(), &objects);

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

		window.clear(sf::Color::Black);

		for(auto& object : objects)
		{
			object.draw(&window);
		}

		quadTree.draw(&window);

		window.display();

	}

	return 0;
}
