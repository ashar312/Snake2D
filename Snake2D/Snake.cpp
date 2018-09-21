#include <GL\glut.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "Game.h"

#define COLUMNS 40
#define ROWS 40
#define FPS 15

void display_callback();
void reshape(int, int);
void timer(int);
void keyboard(int, int, int);

//int index = 0;
extern short s2direction;
extern short sdirection;
extern bool gameover;
int score = 0;
int score2 = 0;
void display_callback() {

	glClear(GL_COLOR_BUFFER_BIT);
	drawgrid();
	drawsnake();
	drawsnake2();
	crash();
	drawfood();
	/*glRectd(index, 20, index + 2, 22);
	index++;
	if (index > 40)
	{
		index = 0;
	}*/
	glutSwapBuffers();
	if (gameover) {

		char scoreboard[10];
		char scoreboard2[10];
		_itoa_s(score, scoreboard, 10);
		char text[50] = "player 1 : ";
		strcat_s(text, scoreboard);
		_itoa_s(score2, scoreboard2, 10);
		char text2[50] = " player 2 : ";
		strcat_s(text2, scoreboard2);
		strcat_s(text, text2);
		MessageBox(NULL,text,"Game Over",0);
		exit(0);
	}
}

void init() {
	glClearColor(0.0,0.0,0.0,1.0);
	initgrid(COLUMNS, ROWS);

}


void keyboard(int key, int, int) {

	switch (key)
	{
	case GLUT_KEY_LEFT: 
		if (sdirection != RIGHT)
			sdirection = LEFT;
		break;

	case GLUT_KEY_RIGHT:
		if (sdirection != LEFT)
			sdirection = RIGHT;
		break;
		
	case GLUT_KEY_UP:
		if (sdirection != DOWN)
			sdirection = UP;
		break;

	case GLUT_KEY_DOWN:
		if (sdirection != UP)
			sdirection = DOWN;
		break;
	}

}

void keyboard2(unsigned char key,int,int)
{
	switch (key) {
	case 'w':
		if (s2direction != DOWN)
			s2direction = UP;
		break;
	case 's':
		if (s2direction != UP)
			s2direction = DOWN;
		break;
	case 'a':
		if (s2direction != RIGHT)
			s2direction = LEFT;
		break;
	case 'd':
		if (s2direction != LEFT)
			s2direction = RIGHT;
		break;

	}
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Snake Game");
	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshape);
	glutTimerFunc(0,timer,0);
	glutSpecialFunc(keyboard);
	glutKeyboardFunc(keyboard2);
	init();
	glutMainLoop();
	return 0;
}

void timer(int) {

	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer, 0);
}



void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COLUMNS, 0.0, ROWS,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
}
