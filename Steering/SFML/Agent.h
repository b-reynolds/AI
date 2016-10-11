#pragma once
#include <SFML/Graphics.hpp>

class Agent {

	sf::Vector2f Velocity, Acceleration;
	sf::Vector2f Position;
	sf::Sprite Sprite;
	float Max_Speed, Max_Force;
	const float PI = 3.14159265;

public:



	Agent(sf::Texture* _Texture, sf::Vector2f _Position);

	void Seek(sf::Vector2f _Target);
	void Update(sf::Vector2f _Target);
	void Apply_Force(sf::Vector2f _Force);
	void Draw(sf::RenderWindow* _Window);

	sf::Vector2f Normalize(sf::Vector2f _V) const;

	~Agent();
};

