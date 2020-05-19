#ifndef GAME_H
#define GAME_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include "Map.h"
#include "Snake.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


typedef struct Game {
	Map* palya;
	Snake* kigyo;
	int score;
	int speed;
	int timelimit;
}Game;

Game* CreateGame(char* filename, int speed, int timelimit);

void Play(Game* jatek);
void Apple(Game* jatek);

#endif 