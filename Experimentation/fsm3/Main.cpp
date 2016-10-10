#include <SFML/Graphics.hpp>
#include "Lumberjack.h"

int main() {

	sf::Font Fnt_Default;
	if (!Fnt_Default.loadFromFile("NotoSans-Regular.ttf")) {
		return 1;
	}

	sf::Texture Txtr_Character;
	if (!Txtr_Character.loadFromFile("Character.png")) {
		return 1;
	}

	Lumberjack Lumberjack(&Txtr_Character, &Fnt_Default);

	sf::Texture Txtr_Background;
	if(!Txtr_Background.loadFromFile("Background.png")) {
		return 1;
	}

	sf::Sprite Spr_Background;
	Spr_Background.setTexture(Txtr_Background);

	sf::RenderWindow Window(sf::VideoMode(640, 360), "Lumberjack (FSM)");

	sf::Clock Delta_Clock;
	sf::Time Delta_Time;

	while (Window.isOpen()) {

		sf::Event Event;
		while (Window.pollEvent(Event)) {
			if (Event.type == sf::Event::Closed) {
				Window.close();
			}
		}

		Window.clear();

		Window.draw(Spr_Background);

		Lumberjack.Update(&Delta_Time);
		Lumberjack.Draw(&Window);

		Window.display();

		Delta_Time = Delta_Clock.restart();

	}

	return 0;
}