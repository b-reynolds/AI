#include <SFML/Graphics.hpp>
#include "Boid.h"
#include "TextUtil.h"
#include "DebugUtil.h"
#include "WindowUtil.h"
#include "RandomUtil.h"

Boid* pBoid;

void update(sf::RenderWindow &window, const float &deltaTime)
{
	pBoid->update(window, deltaTime);
}

void draw(sf::RenderWindow &window, const float &deltaTime)
{
	TextUtil::getInstance()->drawText("Steering Behaviours", window, sf::Vector2f((float)WIN_X / 2, 24), 0.35f, sf::Color::White);
	DebugUtil::drawLine(window, sf::Vector2f(0, 48), sf::Vector2f((float)WIN_X, 48), sf::Color::White);
	TextUtil::getInstance()->drawText(pBoid->getBehaviourName(), window, sf::Vector2f((float)WIN_X / 2, (float)WIN_Y - 24), 0.35f, sf::Color::White);
	DebugUtil::drawLine(window, sf::Vector2f(0, (float)WIN_Y - 48), sf::Vector2f((float)WIN_X, (float)WIN_Y - 48), sf::Color::White);
	pBoid->draw(window, deltaTime);
}

int main()
{
	sf::Clock deltaClock;
	float deltaTime = 0.0f;

	pBoid = new Boid(sf::Vector2f(WIN_X / 2, WIN_Y / 2));

	sf::Sprite sprBackground;
	sf::Texture txtrBackground;

	RandomUtil::generateSeed();

	if(!txtrBackground.loadFromFile("Background.png"))
	{
		return 1;
	}
	sprBackground.setTexture(txtrBackground);

	sf::RenderWindow window(sf::VideoMode(WIN_X, WIN_Y), WIN_TITLE, sf::Style::Close);

	while (window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
			if(event.type == sf::Event::MouseButtonPressed)
			{
				switch(event.mouseButton.button)
				{
					case sf::Mouse::Left:
						pBoid->nextBehaviour();
						break;
					case sf::Mouse::Right:
						pBoid->previousBehaviour();
						break;
					default:
						break;
				}
			}
		}

		update(window, deltaTime);

		window.clear();
		window.draw(sprBackground);		

		draw(window, deltaTime);

		window.display();

		deltaTime = deltaClock.restart().asSeconds();

	}

	delete pBoid;

	return 0;
}