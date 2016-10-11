#include "Agent.h"

Agent::Agent(Vector2f _Location, Vector2f _Size, Colour _Colour) {
	Location = _Location;
	Size = _Size;
	Color = _Colour;
	Max_Force = 5;
	Max_Speed = 5;
}

void Agent::Draw() {
	glBegin(GL_TRIANGLES);
		glVertex2f(Location.X, Location.Y);
		glVertex2f(Location.X + Size.X, Location.Y);
		glVertex2f(Location.X + Size.X, Location.Y + Size.Y);
	glEnd();
}

void Agent::Seek(Vector2f _Target) {
	Vector2f Desired = Vector2f::Subtract(_Target, Location);
	Desired = Vector2f::Normalize(Desired);
	Desired = Vector2f::Multiply(Desired, Max_Speed);
	Vector2f Steering = Vector2f::Subtract(Desired, Velocity);
	GLfloat Magnitude = Vector2f::Magnitude(Steering);

	Add_Force(Steering);
}

void Agent::Update() {
	Velocity = Vector2f::Add(Velocity, Acceleration);
	Velocity = Vector2f::Multiply(Vector2f::Normalize(Velocity), Max_Speed);
	Location = Vector2f::Add(Location, Velocity);
	Acceleration = Vector2f::Zero();
}

void Agent::Add_Force(Vector2f _Force) {
	Acceleration = Vector2f::Add(Acceleration, _Force);
}
