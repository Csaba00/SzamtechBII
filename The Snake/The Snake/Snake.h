#ifndef SNAKE_H
#define SNAKE_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Bodypart {
	int row;
	int col;
	int irany;
	int jelenlegiTores;

}Bodypart;

typedef struct Tores {
	int row, col, irany;
	int hanyErtIde;
	bool valid;
}Tores;

typedef struct Snake {
	Bodypart* adatok;
	int hossz;
	int torespontok; //Torespontok szama
	 //Kigyonak az iranya, ami (8-FEL,2-LE,4-BALRA,6-JOBBRA)
	Tores* tores; //Uj irany, es koordinatak
}Snake;


Snake* CreateSnake();
void Move(Snake* kigyo);
void Up(Snake* kigyo, int i);
void Down(Snake* kigyo, int i);
void Right(Snake* kigyo, int i);
void Left(Snake* kigyo, int i);
void MoveHead(Snake* kigyo, int irany);
void MoveMe(Snake* kigyo, int i);


#endif 