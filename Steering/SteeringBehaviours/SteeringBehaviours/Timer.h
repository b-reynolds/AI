#pragma once
#include <SFML/System/Clock.hpp>

class Timer
{

public:

	Timer();
	explicit Timer(const sf::Int32 &interval);

	bool hasElapsed() const;

	void setInterval(const sf::Int32 &interval);
	void reset();

private:

	sf::Clock clock;
	sf::Int32 time;
	sf::Int32 interval;

};

