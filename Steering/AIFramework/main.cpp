#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

#include "BaseEntity.h"
#include "Boid.h"
#include "UtilRandom.h"

int main() {

	sf::RenderWindow Window(sf::VideoMode(800, 600), "AI Framework");
	//Window.setFramerateLimit(60);

	sf::Clock Delta_Clock;
	float Delta_Time = 0.0f;

	Boid B;
	B.setPosition(400, 300);

	while (Window.isOpen()) {

		sf::Event event;
		while (Window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				Window.close();
			}
		}

		Window.clear();

		B.Set_Target(sf::Vector2f(sf::Mouse::getPosition(Window).x, sf::Mouse::getPosition(Window).y));
		B.Think(Delta_Time);

		Window.draw(B.GetSprite(), B.getTransform());
		Window.display();

		Delta_Time = Delta_Clock.restart().asSeconds();
		std::cout << "Delta Time: " << Delta_Time << std::endl;
	}

	return 0;

}
