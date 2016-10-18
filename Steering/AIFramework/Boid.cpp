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
			Seek(Target);
			break;
		case States::StPursue:
			Pursue(Target);
			break;
		case States::StArrive:
			Arrive(Target);
			break;
		case States::StEvade:
			Evade(Target);
			break;

	}

	Velocity = (Vector::Normalize(Velocity + Acceleration) * SPEED);

	std::cout << "Velocity (" << Velocity.x << ", " << Velocity.y << ")" << std::endl;

	Rotate_Towards(Velocity);
	Move(Velocity);

	Acceleration = Vector::Zero();

}

void Boid::Arrive(sf::Vector2f _Target) {

	sf::Vector2f Desired_Velocity = _Target - getPosition();
	float Distance = Vector::Magnitude(Desired_Velocity);
	Desired_Velocity = Vector::Normalize(Desired_Velocity);

	if(Distance < 100) {
		float M = SPEED * (Distance / 100);
		Desired_Velocity = Desired_Velocity * M;
	}
	else {
		Desired_Velocity = Desired_Velocity * SPEED;
	}

	sf::Vector2f Steering_Force = Desired_Velocity - Velocity;

	Steering_Force = Vector::Limit_Magnitude(Steering_Force, MAX_FORCE);

	Apply_Force(Steering_Force);

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
