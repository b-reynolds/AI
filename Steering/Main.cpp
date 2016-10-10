#include <glut.h>
#include "Vector2f.h"
#include <iostream>

const GLint RES_X = GetSystemMetrics(SM_CXSCREEN);
const GLint RES_Y = GetSystemMetrics(SM_CYSCREEN);

const GLint WIN_X = 800;
const GLint WIN_Y = 600;

const GLint FRAME_RATE = 1000 / 60;

void Start(void) {

}

void Update(int _Data) {

	glutTimerFunc(FRAME_RATE, Update, -1);

	glutPostRedisplay();

}

void Handle_Input(unsigned char Key, int _X, int _Y) {

	switch (Key) {
		default: break;
	}

}

void Draw(void) {

	glClear(GL_COLOR_BUFFER_BIT);

	glFlush();

}


int main(int Arg_C, char* Arg_V[]) {

	glutInit(&Arg_C, Arg_V);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIN_X, WIN_Y);
	glutInitWindowPosition((RES_X - WIN_X) / 2, (RES_Y - WIN_Y) / 2);

	char Window_Title[] = "Steering Behaviours";
	glutCreateWindow(Window_Title);

	Start();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, WIN_X, 0.0, WIN_Y);

	glutDisplayFunc(Draw);
	glutKeyboardFunc(Handle_Input);
	glutTimerFunc(FRAME_RATE, Update, -1);
	glutMainLoop();

	return 0;

}
