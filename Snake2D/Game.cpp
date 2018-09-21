#include <GL\glut.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <Windows.h>
#include "Game.h"
void unit(int, int);
int gridx, gridy;
extern int score;
extern int score2;
int snakelength = 5;
int snakelength2 = 5;
int posx[60] = { 20,20,20,20,20,}, posy[60] = { 20,19,18,17,16 };
int pos2x[60] = { 10,10,10,10,10 }, pos2y[60] = { 20,19,18,17,16 };
bool gameover = false;
bool food = true;
int foodx, foody;
short sdirection = RIGHT;
short s2direction = LEFT;
void initgrid(int x, int y) {
	gridx = x;
	gridy = y;

}

void drawgrid() {
	for (int i = 0; i < gridx; i++)
	{
		for (int j = 0; j < gridy; j++)
		{
			unit(i, j);
		}
	}

}


void unit(int x, int y) {
	if (x == 0 || y == 0 || x == gridx-1 || y == gridy-1) {
		glLineWidth(3.0);
		glColor3f(1.0, 0.0, 0.0);
	}
	else {
		glLineWidth(1.0);
		glColor3f(1.0, 1.0, 1.0);
	}
	
	
	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x+1, y);
	glVertex2f(x+1, y+1);
	glVertex2i(x, y+1);
	glEnd();
}

void drawfood() {
	if (food) {
		random(foodx, foody);
		food = false;
	} 
	glColor3f(1.0, 0.0, 0.0);
	glRectd(foodx, foody, foodx + 1, foody + 1);


}

void drawsnake2() {

	for (int i = snakelength2 - 1; i > 0; i--)
	{
		pos2x[i] = pos2x[i - 1];
		pos2y[i] = pos2y[i - 1];
	}

	if (s2direction == UP)
		pos2y[0]++;
	else if (s2direction == DOWN)
		pos2y[0]--;
	else if (s2direction == RIGHT)
		pos2x[0]++;
	else if (s2direction == LEFT)
		pos2x[0]--;


	for (int i = 0; i < snakelength2; i++)
	{
		if (i == 0)
			glColor3f(0.0, 1.0, 0.0);
		else
			glColor3f(1.0, 0.65, 0.0);
		glRectd(pos2x[i], pos2y[i], pos2x[i] + 1, pos2y[i] + 1);
	}

	if (pos2x[0] == 0 || pos2y[0] == 0 || pos2x[0] == gridx - 1 || pos2y[0] == gridy - 1)
		gameover = true;
	if (pos2x[0] == foodx && pos2y[0] == foody)
	{
		score2++;
		snakelength2++;
		if (snakelength2 > 60) {
			snakelength2 = maxlength;
		}
		food = true;
	}
	for (int i = 1; i < snakelength2; i++)
	{
		if (pos2x[0] == pos2x[i] && pos2y[0] == pos2y[i])
		{
			gameover = true;
		}
	}
}

void crash() {

	for (int i = 0; i < snakelength; i++)
	{
		for (int j = 0; j < snakelength2; j++)
		{
			if (posx[i] == pos2x[j] && posy[i] == pos2y[j])
				gameover = true;
		}
	}
	/*for (int i = 0; i < snakelength2; i++)
	{
		if (posx[i] == pos2x[i] && pos2y[i] == posy[i])
			gameover = true;
	}*/

}


void drawsnake() {

	for (int i = snakelength - 1; i > 0; i--)
	{
		posx[i] = posx[i - 1];
		posy[i] = posy[i - 1];
	}
	if (sdirection == UP)
		posy[0]++;
	else if (sdirection == DOWN)
		posy[0]--;
	else if (sdirection == RIGHT)
		posx[0]++;
	else if (sdirection == LEFT)
		posx[0]--;
	for (int i = 0; i < snakelength; i++)
	{
		if (i == 0)
			glColor3f(0.0, 1.0, 0.0);
		else
			glColor3f(0.0, 0.0, 1.0);
		glRectd(posx[i], posy[i], posx[i] + 1, posy[i] + 1);
	}




	if (posx[0] == 0 || posy[0] == 0 || posx[0] == gridx - 1 || posy[0] == gridy - 1)
		gameover = true;

	if (posx[0] == foodx && posy[0] == foody)
	{
		score++;
		snakelength++;
		if (snakelength > 60) {
			snakelength = maxlength;
		}
		food = true;
	}

	for (int i = 1; i < snakelength; i++)
	{
		if (posx[0] == posx[i] && posy[0] == posy[i])
		{
			gameover = true;
		}
	}
}


void random(int &x,int &y) {
	
	int maxX = gridx - 2;
	int maxY = gridy - 2;
	int min = 1;
	srand(time(NULL));
	x = min + rand() %(maxX - min);
	y = min + rand() % (maxY - min);
}



