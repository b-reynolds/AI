#include <SFML/Graphics.hpp>
#include "Agent.h"

int main() {

	sf::Texture Txtr_Agent;
	if (!Txtr_Agent.loadFromFile("Agent.png")) {
		return 1;
	}

	Agent A(&Txtr_Agent, sf::Vector2f(0, 0));

	sf::RenderWindow Window(sf::VideoMode(800, 600), "Steering Behaviours");

	while (Window.isOpen()) {

		sf::Event Event;
		while (Window.pollEvent(Event)) {
			if (Event.type == sf::Event::Closed) {
				Window.close();
			}
		}

		Window.clear(sf::Color::White);

		A.Update(sf::Vector2f(sf::Mouse::getPosition(Window).x, sf::Mouse::getPosition(Window).y));
		A.Draw(&Window);

		Window.display();

	}

	return 0;

}