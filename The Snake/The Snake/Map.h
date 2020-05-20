#ifndef MAP_H
#define MAP_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>

typedef struct Map {
	int row; 
	int col; 
	int** map; //palyakat tartalmaz
}Map;

//PALYA LETREHOZASA
Map* CreateMap(char *filename);
//PALYA KIIRATASA
void Kiir(Map* palya);

#endif 