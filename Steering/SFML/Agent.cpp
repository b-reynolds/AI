#include "Agent.h"
#include <iostream>

Agent::Agent(sf::Texture* _Texture, sf::Vector2f _Position) {

	Sprite.setTexture(*_Texture);
	Sprite.setPosition(_Position);
	Velocity = sf::Vector2f(0, 0);
	Acceleration = sf::Vector2f(0, 0);
	Max_Speed = 0.05f;
	Max_Force = 0.003f;

}

void Agent::Seek(sf::Vector2f _Target) {

	sf::Vector2f Desired_Velocity = Normalize(_Target - Sprite.getPosition()) * Max_Speed;
	sf::Vector2f Steering_Force = Desired_Velocity - Velocity;
	Steering_Force = Limit_Magnitude(Steering_Force, Max_Force);
	Apply_Force(Steering_Force);

}

void Agent::Update(sf::Vector2f _Target) { 
	
	Seek(_Target);

	Velocity = Normalize(Velocity + Acceleration) * Max_Speed;
	Rotate_Towards(Velocity);
	Sprite.move(Velocity);

	Acceleration = sf::Vector2f(0, 0);

}

void Agent::Apply_Force(sf::Vector2f _Force) {
	Acceleration += _Force;
}

void Agent::Draw(sf::RenderWindow* _Window) {
	_Window->draw(Sprite);
}

void Agent::Rotate_Towards(sf::Vector2f _Target) {
	float Rotation = atan2(_Target.y, _Target.x) * 180 / PI;
	//float Rotation = atan2(Sprite.getPosition().y - _Target.y, Sprite.getPosition().x - _Target.x) * 180 / PI;
	Sprite.setRotation(Rotation);
}

sf::Vector2f Agent::Limit_Magnitude(sf::Vector2f _V, float _Max) const {
	if((_V.x * _V.x) + (_V.y * _V.y) > (_Max * _Max)) {
		_V = Normalize(_V);
		_V.x *= _Max;
		_V.y *= _Max;
	}
	return _V;
}

sf::Vector2f Agent::Normalize(sf::Vector2f _V) const {
	float Length = sqrt(_V.x * _V.x + _V.y * _V.y);
	return Length == 0 ? _V : sf::Vector2f(_V.x / Length, _V.y / Length);
}

Agent::~Agent() {
}
