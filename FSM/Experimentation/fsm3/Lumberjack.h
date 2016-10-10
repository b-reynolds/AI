#pragma once
#include "State.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "LJHarvest.h"
#include "LJSleep.h"
#include "LJWalk.h"
#include "LJEat.h"

class Lumberjack {

	sf::Sprite Sprite;
	sf::Text Text;

	float Speed;

	State* State_Walk;
	State* State_Harvest;
	State* State_Sleep;
	State* State_Eat;

	State* State;

public:

	enum States { Walk, Harvest, Sleep, Eat };

	int Hunger, Energy, Wood;

	std::vector<sf::Vector2f> Path_Walk;
	std::vector<sf::Vector2f> Path_Sleep;
	std::vector<sf::Vector2f> Path_Harvest;
	std::vector<sf::Vector2f> Path_Eat;

	std::vector<sf::Vector2f>* Path;
	int Target_Node;


	Lumberjack(sf::Texture* _Texture, sf::Font* _Font);

	void Update(sf::Time* _Delta_Time);
	void Draw(sf::RenderWindow *_Window);
	void Move_Towards(sf::Vector2f _Destination, float _Speed, sf::Time* _Delta_Time);
	void Change_State(States _State);

};

