#pragma once
#include "BaseEntity.h"
#include "Vector.h"

class Boid : public BaseEntity {

public:

	using BaseEntity::BaseEntity;

	sf::Vector2f Target, Acceleration;

	enum States { StEvade, StSeek, StPursue, StArrive };
	enum States State;

	const float SPEED = 0.1f;
	const float MAX_FORCE = 0.1f;

	void Apply_Force(sf::Vector2f _Force);
	void Move(sf::Vector2f _Velocity);
	void Set_Target(sf::Vector2f _Target);
	void Rotate_Towards(sf::Vector2f _Target);

	void Think(float _Delta_Time);

	void Arrive(sf::Vector2f _Target);
	void Pursue(sf::Vector2f _Target);
	void Seek(sf::Vector2f _Target);
	void Evade(sf::Vector2f _Target);

};

