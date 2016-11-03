#include <SFML/Graphics.hpp>

int main()
{

	sf::Texture txtObject;
	if(!txtObject.loadFromFile("sprite.png"))
	{
		return 1;
	}

	sf::RenderWindow window(sf::VideoMode(640, 640), "Quad Tree");

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

		window.clear();

		window.display();

	}

	return 0;
}
