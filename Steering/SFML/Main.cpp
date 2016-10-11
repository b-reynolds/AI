#include <SFML/Graphics.hpp>
#include "Agent.h"
#include <iostream>

int main() {

	sf::Texture Txtr_Agent;
	if (!Txtr_Agent.loadFromFile("Agent.png")) {
		return 1;
	}

	std::vector<Agent> Agents;

	for(auto i = 1; i <= 1; ++i) {
		Agent T(&Txtr_Agent, sf::Vector2f(-64 * i, i * 64));
		Agents.push_back(T);
	}

	sf::RenderWindow Window(sf::VideoMode(800, 600), "Steering Behaviours");

	while (Window.isOpen()) {

		sf::Event Event;
		while (Window.pollEvent(Event)) {
			if (Event.type == sf::Event::Closed) {
				Window.close();
			}
		}

		Window.clear(sf::Color::White);

		for (auto i = 0; i < Agents.size(); ++i) {
			Agents[i].Update(sf::Vector2f(sf::Mouse::getPosition(Window).x, sf::Mouse::getPosition(Window).y));
			Agents[i].Draw(&Window);
		}

		Window.display();

	}

	return 0;

}
