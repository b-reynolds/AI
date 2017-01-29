#include <cstdio>
#include "Node.h"
#include "Sequence.h"
#include "Selector.h"

struct Vector2
{
	int x;
	int y;

	Vector2() : x(0), y(0) {}
	Vector2(const int &x, const int &y) : x(x), y(y) {}
	void operator+=(const Vector2 &p) { x += p.x; y += p.y; }
	bool operator==(const Vector2 &p) const { return x == p.x && y == p.y; }
	Vector2 operator-(const Vector2 &p) const { return Vector2(x - p.x, y - p.y); }
};

class Player
{
public:
	explicit Player(const Vector2 &position) : position(position), alive(true) {}
	void setPosition(const Vector2 &position) { this->position = position; }
	Vector2 getPosition() const { return position; }
	void move(const Vector2 &velocity) { this->position += velocity; }
	bool isAlive() const { return alive; }
	void die() { alive = false; }
private:
	Vector2 position;
	bool alive;
};

class Assasin : public Player
{
public:
	explicit Assasin(const Vector2 &position, Player* target) : Player(position), target(target) {}
	Player* getTarget() const { return target; }
private:
	Player* target;
};

class TargetIsAlive : public Node
{
public:
	explicit TargetIsAlive(Assasin* assasin) { this->assasin = assasin; }
	bool run() override
	{
		bool result = assasin->getTarget()->isAlive();
		printf("Target is %s\n", result ? "alive" : "dead");
		return result;
	}
private:
	Assasin* assasin;
};

class PursueTarget : public Node
{
public:
	explicit PursueTarget(Assasin* assasin) { this->assasin = assasin; }
	bool run() override
	{
		Vector2 currentPos = assasin->getPosition();
		Vector2 targetPos = assasin->getTarget()->getPosition();
		printf("Pursuing target.. (%d, %d) / (%d, %d)\n", currentPos.x, currentPos.y, targetPos.x, targetPos.y);
		Vector2 velocity = targetPos - currentPos;
		if(velocity.x != 0)	velocity.x = velocity.x >= 1 ? 1 : -1;
		if(velocity.y != 0) velocity.y = velocity.y >= 1 ? 1 : -1;
		assasin->move(velocity);
		return assasin->getPosition() == assasin->getTarget()->getPosition();
	}
private:
	Assasin* assasin;
};

class KillTarget : public Node
{
public:
	explicit KillTarget(Assasin* assasin) { this->assasin = assasin; }
	bool run() override
	{
		assasin->getTarget()->die();
		printf("Target killed!\n");
		return !assasin->getTarget()->isAlive();
	}
private:
	Assasin* assasin;
};

int main()
{
	Player player(Vector2(25, -10));
	Assasin assasin(Vector2(0, 0), &player);

	Sequence rootNode;

	TargetIsAlive targetIsAlive(&assasin);
	KillTarget killTarget(&assasin);
	PursueTarget pursueTarget(&assasin);

	rootNode.addChild(&targetIsAlive);
	rootNode.addChild(&pursueTarget);
	rootNode.addChild(&killTarget);

	while (!rootNode.run()) {}

	printf("Finished.\n");
	getchar();

	return 0;
}