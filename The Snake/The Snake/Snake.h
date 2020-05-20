#ifndef SNAKE_H
#define SNAKE_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Snake {
	int row, col; //Kigyo koordinata
	int irany;	  //Kigyo iranya
}Snake;

//KIGYO LETREHOZASA
Snake* CreateSnake();

//KIGYO MOZGATASA
void MoveHead(Snake* kigyo, int irany);



#endif 