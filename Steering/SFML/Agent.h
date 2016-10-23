#pragma once
#include <SFML/Graphics.hpp>

class Agent {

	sf::Vector2f Velocity, Acceleration;
	sf::Sprite Sprite;
	float Max_Speed, Max_Force;
	const float PI = 3.14159265;

public:

	Agent(sf::Texture* _Texture, sf::Vector2f _Position);

	void Seek(sf::Vector2f _Target);
	void Update(sf::Vector2f _Target);
	void Apply_Force(sf::Vector2f _Force);
	void Draw(sf::RenderWindow* _Window);
	void Rotate_Towards(sf::Vector2f _Target);
	sf::Vector2f Limit_Magnitude(sf::Vector2f _V, float _Max) const;

	sf::Vector2f Normalize(sf::Vector2f _V) const;

	~Agent();
};

