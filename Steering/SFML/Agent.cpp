#include "Agent.h"
#include <iostream>

Agent::Agent(sf::Texture* _Texture, sf::Vector2f _Position) {
	Sprite.setTexture(*_Texture);
	Position = _Position;
	Velocity = sf::Vector2f(0, 0);
	Acceleration = sf::Vector2f(0, 0);
	Max_Speed = 0.1f;
	Max_Force = 5;
}

void Agent::Seek(sf::Vector2f _Target) {
	sf::Vector2f Desired = _Target - Sprite.getPosition();
	Desired = Normalize(Desired) * Max_Speed;
	sf::Vector2f Steering = Desired - Velocity; 
	Apply_Force(Steering);
}

void Agent::Update(sf::Vector2f _Target) { 

	float DX = Sprite.getPosition().x - _Target.x;
	float DY = Sprite.getPosition().y - _Target.y;
	float Rotation = (atan2(DY, DX) * 180 / PI);
	Sprite.setRotation(Rotation);


	Seek(_Target);

	Velocity = Normalize(Velocity + Acceleration) * Max_Speed;
	Sprite.move(Velocity);
	Acceleration = sf::Vector2f(0, 0);
}

void Agent::Apply_Force(sf::Vector2f _Force) {
	Acceleration += _Force;
}

void Agent::Draw(sf::RenderWindow* _Window) {
	_Window->draw(Sprite);
}

sf::Vector2f Agent::Normalize(sf::Vector2f _V) const {
	float Length = sqrt(_V.x * _V.x + _V.y * _V.y);
	return Length == 0 ? _V : sf::Vector2f(_V.x / Length, _V.y / Length);
}

Agent::~Agent() {
}
