#include "Boid.h"

void Boid::Apply_Force(sf::Vector2f _Force) {
	Acceleration += _Force;
}

void Boid::Move(sf::Vector2f _Velocity) {
	setPosition(getPosition() + _Velocity);
}

void Boid::Set_Target(sf::Vector2f _Target) {
	Target = _Target;
}

void Boid::Rotate_Towards(sf::Vector2f _Target) {
	setRotation(atan2(_Target.y, _Target.x) * 180 / M_PI);
}

void Boid::Think(float _Delta_Time) {

	//Evade(Target);

	Seek(Target);

	Velocity = (Vector::Normalize(Velocity + Acceleration) * 0.5f);
	std::cout << Velocity.x << ", " << Velocity.y << std::endl;

	Rotate_Towards(Velocity);
	Move(Velocity);

	Acceleration = Vector::Zero();

}

void Boid::Seek(sf::Vector2f _Target) {
	
	sf::Vector2f Desired_Velocity = Vector::Normalize(_Target - getPosition());
	sf::Vector2f Steering_Force = Desired_Velocity - Velocity;
	Apply_Force(Steering_Force);

}

void Boid::Evade(sf::Vector2f _Target) {

	sf::Vector2f Desired_Velocity = Vector::Normalize(getPosition() - Target);
	sf::Vector2f Steering_Force = Desired_Velocity - Velocity;
	Apply_Force(Steering_Force);
	
}
