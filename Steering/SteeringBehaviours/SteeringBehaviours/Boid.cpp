#pragma once
#define _USE_MATH_DEFINES
#include "Boid.h"
#include "Vector2D.h"
#include "DebugUtil.h"
#include <math.h>
#include <SFML/Window/Mouse.hpp>
#include "RandomUtil.h"
#include "WindowUtil.h"


Boid::Boid(const sf::Vector2f& startPosition)
{
	if (!txtrBoid.loadFromFile(TEXTURE_PATH))
	{
		printf("Error: failed to load \"%s\"\n", TEXTURE_PATH.c_str());
	}
	sprBoid.setTexture(txtrBoid);
	sf::FloatRect rectBounds = sprBoid.getGlobalBounds();
	sprBoid.setOrigin(rectBounds.width / 2, rectBounds.height / 2);
	setPosition(startPosition);
	this->startPosition = startPosition;
	currentBehaviour = SEEK;
}

void Boid::update(sf::RenderWindow& window, const float& deltaTime)
{
	if(!intersects(sf::FloatRect(0, BORDER_Y, WIN_X, WIN_Y - BORDER_Y)))
	{
		setPosition(startPosition);
	}
	sf::FloatRect area;

	switch(currentBehaviour)
	{
		case SEEK:
			seek((sf::Vector2f)sf::Mouse::getPosition(window));
			break;
		case FLEE:
			flee((sf::Vector2f)sf::Mouse::getPosition(window));
			break;
		case ARRIVE:
			arrive((sf::Vector2f)sf::Mouse::getPosition(window));
			break;	
		case WANDER:
			wander(sf::FloatRect(0, BORDER_Y + sprBoid.getLocalBounds().height / 2, (float)WIN_X, WIN_Y - BORDER_Y * 2.0f - sprBoid.getLocalBounds().height));
			break;
		case WANDER2:
			wander2(sf::FloatRect(0, BORDER_Y + sprBoid.getLocalBounds().height / 2, (float)WIN_X, WIN_Y - BORDER_Y * 2.0f - sprBoid.getLocalBounds().height));
			break;
		default:
			break;
	}

	acceleration = Vector2D::limit(acceleration, MAX_FORCE);
	velocity += acceleration;
	Vector2D::limit(velocity, MAX_SPEED);
	move(velocity * deltaTime);
	rotate(velocity);
	acceleration = sf::Vector2f(0, 0);
}

void Boid::draw(sf::RenderWindow& window, const float& deltaTime) const
{
	switch (currentBehaviour)
	{
	case SEEK:
		DebugUtil::drawLine(window, getPosition(), (sf::Vector2f)sf::Mouse::getPosition(window), sf::Color(255, 255, 255, 75));
		break;
	case FLEE:
		DebugUtil::drawLine(window, getPosition(), (sf::Vector2f)sf::Mouse::getPosition(window), sf::Color(255, 255, 255, 75));
		break;
	case ARRIVE:
		DebugUtil::drawLine(window, getPosition(), (sf::Vector2f)sf::Mouse::getPosition(window), sf::Color(255, 255, 255, 75));
		break;
	case WANDER:
		DebugUtil::drawLine(window, getPosition(), wanderTarget, sf::Color(255, 255, 255, 75));
		break;
	case WANDER2:
		DebugUtil::drawLine(window, getPosition(), circleCenter, sf::Color(255, 255, 255, 75));
		DebugUtil::drawLine(window, getPosition(), wanderTarget, sf::Color(255, 0, 0, 125));
		DebugUtil::drawCircle(window, circleCenter, CIRCLE_RADIUS, sf::Color(0, 255, 255, 75));
		break;
	default:
		break;
	}
	window.draw(sprBoid);
} 

void Boid::nextBehaviour()
{
	if(currentBehaviour == SEEK)
	{
		currentBehaviour = FLEE;
	}
	else if(currentBehaviour == FLEE)
	{
		currentBehaviour = ARRIVE;
	}
	else if(currentBehaviour == ARRIVE)
	{
		currentBehaviour = WANDER;
	}
	else if(currentBehaviour == WANDER)
	{
		currentBehaviour = WANDER2;
	}
	else
	{
		currentBehaviour = SEEK;
	}
}

void Boid::previousBehaviour()
{
	if(currentBehaviour == WANDER2)
	{
		currentBehaviour = WANDER;
	}
	else if(currentBehaviour == WANDER)
	{
		currentBehaviour = ARRIVE;
	}
	else if (currentBehaviour == ARRIVE)
	{
		currentBehaviour = FLEE;
	}
	else if (currentBehaviour == FLEE)
	{
		currentBehaviour = SEEK;
	}
	else
	{
		currentBehaviour = ARRIVE;
	}
}

std::string Boid::getBehaviourName() const
{
	switch (currentBehaviour)
	{
		case SEEK:
			return "Seek";
		case FLEE:
			return "Flee";
		case ARRIVE:
			return "Arrive";
		case WANDER:
			return "Wander";
		case WANDER2:
			return "Wander #2";
		default:
			return "N/A";
	}
}

bool Boid::intersects(const sf::FloatRect& rect) const
{
	sf::FloatRect rectBoid = sprBoid.getGlobalBounds();
	return (rectBoid.left < rect.left + rect.width && rectBoid.left + rectBoid.width > rect.left &&
		rectBoid.top < rect.top + rect.height && rectBoid.top + rectBoid.height > rect.top);
}

void Boid::rotate(const sf::Vector2f& direction)
{;
	sprBoid.setRotation(atan2(direction.y, direction.x) * 180 / (float)M_PI + 90);
}

void Boid::addForce(const sf::Vector2f& force)
{
	acceleration += force;
}

void Boid::seek(const sf::Vector2f& target)
{
	sf::Vector2f desiredVelocity = Vector2D::normalize(target - getPosition()) * MAX_SPEED;
	sf::Vector2f steering = desiredVelocity - velocity;
	Vector2D::limit(steering, MAX_FORCE);
	addForce(steering);
}

void Boid::flee(const sf::Vector2f& target)
{
	sf::Vector2f desiredVelocity = Vector2D::normalize(getPosition() - target) * MAX_SPEED;
	sf::Vector2f steering = desiredVelocity - velocity;
	Vector2D::limit(steering, MAX_FORCE);
	addForce(steering);
}

void Boid::arrive(const sf::Vector2f& target)
{
	sf::Vector2f desiredVelocity = target - getPosition();
	float distance = Vector2D::magnitude(desiredVelocity);
	desiredVelocity = Vector2D::normalize(desiredVelocity);
	if(distance < 100)
	{
		float m = Vector2D::map(distance, 0, 100, 0, MAX_SPEED);
		desiredVelocity *= m;
	}
	else
	{
		desiredVelocity *= MAX_SPEED;
	}
	sf::Vector2f steering = desiredVelocity - velocity;
	Vector2D::limit(steering, MAX_FORCE);
	addForce(steering);
}

void Boid::wander(const sf::FloatRect& area)
{
	float distance = Vector2D::distance(getPosition(), wanderTarget);
	if (wanderTimer.hasElapsed() || distance < WANDER_TOLERANCE)
	{
		float targetX = (float)RandomUtil::getRandomInt((int)area.left, (int)(area.left + area.width));
		float targetY = (float)RandomUtil::getRandomInt((int)area.top, (int)(area.top + area.height));
		wanderTarget = sf::Vector2f(targetX, targetY);
		wanderTimer.reset();
	}
	seek(wanderTarget);
}

void Boid::wander2(const sf::FloatRect& area)
{
	circleCenter = getPosition() + Vector2D::normalize(velocity) * CIRCLE_DISTANCE;
	wanderTarget = circleCenter + sf::Vector2f(CIRCLE_RADIUS, CIRCLE_RADIUS);
	//wanderTarget = Vector2D::rotate(wanderTarget, (float)RandomUtil::getRandomInt(0, 360));

	float angle = RandomUtil::nextDouble() * (float)(M_PI * 2.0);
	float radius = sqrt(RandomUtil::nextDouble()) * CIRCLE_RADIUS;
	float x = circleCenter.x + radius * cos(angle);
	float y = circleCenter.y + radius * sin(angle);

	wanderTarget = sf::Vector2f(x, y);

	seek(wanderTarget);
}

void Boid::move(const sf::Vector2f &velocity)
{
	setPosition(getPosition() + velocity);
}

void Boid::setPosition(const sf::Vector2f& position)
{
	sprBoid.setPosition(position);
}

sf::Vector2f Boid::getPosition() const
{
	return sprBoid.getPosition();
}
