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

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
		State = States::StSeek;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
		State = States::StPursue;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
		State = States::StArrive;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
		State = States::StEvade;
	}

	switch(State) {
		case States::StSeek:
			std::cout << "State: Seeking" << std::endl;
			Seek(Target);
			break;
		case States::StPursue:
			std::cout << "State: Pursuing" << std::endl;
			Pursue(Target);
			break;
		case States::StArrive:
			std::cout << "State: Arriving" << std::endl;
			Arrive(Target);
			break;
		case States::StEvade:
			std::cout << "State: Evading" << std::endl;
			Evade(Target);
			break;

	}

	std::cout << "Velocity (" << Velocity.x << ", " << Velocity.y << ")" << std::endl;
	std::cout << "Acceleration (" << Acceleration.x << ", " << Acceleration.y << ")" << std::endl;

	Velocity = (Vector::Normalize(Velocity + Acceleration));



	Rotate_Towards(Velocity);
	Move(Velocity);

	Acceleration = Vector::Zero();


	system("cls");

}

void Boid::Arrive(sf::Vector2f _Target) {

	sf::Vector2f Desired_Velocity = _Target - getPosition();
	float Distance = Vector::Magnitude(Desired_Velocity);
	Desired_Velocity = Vector::Normalize(Desired_Velocity);

	std::cout << "Distance: " << Distance << std::endl;

	if (Distance > 2.5f) {

		if (Distance < 100) {
			float M = SPEED * (Distance / 100);
			Desired_Velocity = Desired_Velocity * M;
		} else {
			Desired_Velocity = Desired_Velocity * SPEED;
		}

		sf::Vector2f Steering_Force = Desired_Velocity - Velocity;

		Steering_Force = Vector::Limit_Magnitude(Steering_Force, MAX_FORCE);

		std::cout << "Steering Force: " << Steering_Force.x << ", " << Steering_Force.y << std::endl;

		Apply_Force(Steering_Force);

	}

}

void Boid::Pursue(sf::Vector2f _Target) {

	float T = 3;
	sf::Vector2f Desired_Velocity = Vector::Normalize(_Target - getPosition()) * T * SPEED;
	sf::Vector2f Steering_Force = Desired_Velocity - Velocity;
	Apply_Force(Steering_Force);

}

void Boid::Seek(sf::Vector2f _Target) {
	
	sf::Vector2f Desired_Velocity = Vector::Normalize(_Target - getPosition()) * SPEED;
	sf::Vector2f Steering_Force = Desired_Velocity - Velocity;
	Apply_Force(Steering_Force);

}

void Boid::Evade(sf::Vector2f _Target) {

	sf::Vector2f Desired_Velocity = Vector::Normalize(getPosition() - Target) * SPEED;
	sf::Vector2f Steering_Force = Desired_Velocity - Velocity;
	Apply_Force(Steering_Force);
	
}
