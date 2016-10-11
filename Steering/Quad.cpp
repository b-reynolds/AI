#include "Quad.h"

void Quad::Draw() {

	glColor3f(Color.R, Color.G, Color.B);
	glBegin(GL_QUADS);
		glVertex2i(Position.X, Position.X + Size.Y);
		glVertex2i(Position.X, Position.Y);
		glVertex2i(Position.X + Size.X, Position.Y);
		glVertex2i(Position.X + Size.X, Position.Y + Size.Y);
	glEnd();

}
