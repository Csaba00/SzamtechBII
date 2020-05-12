#ifndef GAME_H
#define GAME_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include "Map.h"
#include "Snake.h"
#include <stdio.h>
#include <stdbool.h>


typedef struct Game {
	Map* palya;
	Snake* kigyo;
}Game;

Game* CreateGame();

void Play(Game* jatek);
bool CollisionTest(Map* palya, int row, int col); //row,col->fej;

#endif 