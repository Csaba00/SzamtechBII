#ifndef SNAKE_H
#define SNAKE_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include <stdio.h>

typedef struct Coordinate {
	int x, y;
}Coordinate;

typedef struct Snake {
	Coordinate* adatok;
}Snake;

Snake* CreateSnake();

#endif 