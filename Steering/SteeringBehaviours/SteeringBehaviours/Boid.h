#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Timer.h"

class Boid
{

public:


	explicit Boid(const sf::Vector2f &startPosition);

	void update(sf::RenderWindow &window, const float &deltaTime);
	void draw(sf::RenderWindow &window, const float &deltaTime) const;

	enum Behaviour { SEEK, FLEE, ARRIVE, WANDER, WANDER2 };

	void nextBehaviour();
	void previousBehaviour();

	std::string getBehaviourName() const;

private:

	const std::string TEXTURE_PATH = "Boid.png";
	const int BEHAVIOUR_COUNT = 3;
	const float CIRCLE_DISTANCE = 100.0f;
	const float CIRCLE_RADIUS = 50.0f;
	const float MAX_SPEED = 150.0f;
	const float MAX_FORCE = 0.125f;
	const float WANDER_TOLERANCE = 10.0f;
	const sf::Int32 WANDER_TIMER = 1500;

	Behaviour currentBehaviour;

	sf::Texture txtrBoid;
	sf::Sprite sprBoid;

	sf::Vector2f startPosition;

	sf::Vector2f velocity;
	sf::Vector2f acceleration;

	Timer wanderTimer = Timer(WANDER_TIMER);
	sf::Vector2f wanderTarget;

	sf::Vector2f circleCenter;
	
	void rotate(const sf::Vector2f &direction);
	void addForce(const sf::Vector2f &force);
	void seek(const sf::Vector2f &target);
	void flee(const sf::Vector2f &target);
	void arrive(const sf::Vector2f &target);
	void wander(const sf::FloatRect &area);
	void wander2(const sf::FloatRect &area);

	void move(const sf::Vector2f &velocity);

	void setPosition(const sf::Vector2f &position);
	sf::Vector2f getPosition() const;

};

