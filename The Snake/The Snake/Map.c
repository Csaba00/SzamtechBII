#include "Map.h"
#include <stdio.h>
#include <stdlib.h>

Map* CreateMap(char* filename)
{
	Map* palya = (Map*)calloc(1, sizeof(Map));		 //Struct helyfoglalas
	if (!palya) {
		printf("Nem sikerult helyet foglalni");			//Ellenorzes
		return 0;
	}
	FILE* f;								//Palya meretenek beolvasasa
	f = fopen(filename, "rt");
	if (!f) {
		printf("Sikertelen fajl megnyitas");			//Ellenorzes
		return 0;
	}
	fscanf(f, "%i%i\n", &palya->row, &palya->col);

	palya->map = (int**)(calloc(palya->row, sizeof(int*)));		//Palya helyfoglalasa
	for (int i = 0; i < palya->row; ++i) {
		palya->map[i] = (int*)(calloc(palya->col, sizeof(int)));
	}
	if (!palya->map) {
		printf("Nem sikerult helyet fogalalni");			//Ellenorzes
		return 0;
	}
	for (int i = 0; i < palya->row; ++i) {					//Palya feltoltese
		for (int j = 0; j < palya->col; ++j) {
 			fscanf(f, "%i", &palya->map[i][j]);
		}
	}

	return palya;
}

void Kiir(Map* palya) {							 //Palya kiiratasa
	for (int i = 0; i < palya->row; ++i) {
		for (int j = 0; j < palya->col; ++j) {
			if (palya->map[i][j] == 1) {
				printf("|");
			}
			else if (palya->map[i][j] == 2) {
				printf("_");
			}
			if (palya->map[i][j] == 0) {
				printf(" ");
			}
			if (palya->map[i][j] == 7) {
				printf("X");
			}
			if (palya->map[i][j] == 6) {
				printf("*");
			}
			if (palya->map[i][j] == 3) {
				printf("'");
			}
			if (palya->map[i][j] == 5) {
				printf("@");
			}
		}
		printf("\n");
	}
}




