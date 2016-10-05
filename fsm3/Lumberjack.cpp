#include "Lumberjack.h"

Lumberjack::Lumberjack(sf::Texture* _Texture, sf::Font* _Font) {

	State_Harvest = new LJHarvest;
	State_Sleep = new LJSleep;
	State_Walk = new LJWalk;
	State_Eat = new LJEat;

	State = State_Walk;
	
	Sprite.setTexture(*_Texture);

	Text.setFont(*_Font);
	Text.setCharacterSize(12);
	Text.setString("Walking");

	Speed = 100;
	Hunger = 0;
	Wood = 0;
	Energy = 100;

	Path_Walk.push_back(sf::Vector2f(21, 0));
	Path_Walk.push_back(sf::Vector2f(21, 295));
	Path_Walk.push_back(sf::Vector2f(107, 295));
	Path_Walk.push_back(sf::Vector2f(511, 295));

	Path_Walk.push_back(sf::Vector2f(584, 295));
	Path_Walk.push_back(sf::Vector2f(584, 0));
	Path_Walk.push_back(sf::Vector2f(306, 0));

	Path_Sleep.push_back(sf::Vector2f(107, 295));
	Path_Sleep.push_back(sf::Vector2f(107, 260));


	Path_Harvest.push_back(sf::Vector2f(511, 295));
	Path_Harvest.push_back(sf::Vector2f(511, 265));


	Path_Eat.push_back(sf::Vector2f(306, 0));
	Path_Eat.push_back(sf::Vector2f(306, 36));


	Sprite.setPosition(21, 0);
	Path = &Path_Walk;
	Target_Node = 0;
}

void Lumberjack::Update(sf::Time* _Delta_Time) {

	if (Sprite.getPosition() == Path->at(Target_Node)) {
		State->Update(this);
	}
	else {
		Move_Towards(Path->at(Target_Node), Speed, _Delta_Time);
	}

	Text.setPosition(Sprite.getPosition().x, Sprite.getPosition().y + Sprite.getGlobalBounds().height);

}

void Lumberjack::Draw(sf::RenderWindow* _Window) {
	_Window->draw(Sprite);
	_Window->draw(Text);
}

void Lumberjack::Move_Towards(sf::Vector2f _Destination, float _Speed, sf::Time* _Delta_Time) {

	float Speed = _Speed * _Delta_Time->asSeconds();

	if (Sprite.getPosition().y != _Destination.y) {
			if (Sprite.getPosition().y < _Destination.y) {
				float Difference = _Destination.y - Sprite.getPosition().y;
				Sprite.move(0, Difference < Speed ? Difference : Speed);
			} else {
				float Difference = Sprite.getPosition().y - _Destination.y;
				Sprite.move(0, Difference < Speed ? -Difference : -Speed);
			}
		}
	else if(Sprite.getPosition().x != _Destination.x) {
		if(Sprite.getPosition().x < _Destination.x) {
			float Difference = _Destination.x - Sprite.getPosition().x;
			Sprite.move(Difference < Speed ? Difference : Speed, 0);
		}
		else {
			float Difference = Sprite.getPosition().x - _Destination.x;
			Sprite.move(Difference < Speed ? -Difference : -Speed, 0);
		}
	}


}

void Lumberjack::Change_State(States _State) {
	State->Exit(this);
	switch(_State) {
		case Walk:
			State = State_Walk;
			Text.setString("Walking");
			break;
		case Sleep:
			State = State_Sleep;
			Text.setString("Sleeping");
			break;
		case Harvest:
			State = State_Harvest;
			Text.setString("Harvest");
			break;
		case Eat:
			State = State_Eat;
			Text.setString("Eat");
			break;
	}
	State->Enter(this);
}
