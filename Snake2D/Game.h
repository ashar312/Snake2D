#pragma once

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2
#define maxlength 60

void initgrid(int, int);
void drawgrid();
void drawsnake();
void drawsnake2();
void crash();
void drawfood();
void random(int&, int&);