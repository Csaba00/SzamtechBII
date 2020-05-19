#ifndef SNAKE_H
#define SNAKE_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Snake {
	int row, col;
	int irany;
}Snake;

Snake* CreateSnake();

void MoveHead(Snake* kigyo, int irany);



#endif 