#ifndef MAP_H
#define MAP_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>

typedef struct Map {
	int row; //sor - y
	int col; //oszlop - x
	int** map;
}Map;
Map* CreateMap(char *filename);
void Kiir(Map* palya);
void ClearLastPosition(Map* palya, int row, int col);

#endif 