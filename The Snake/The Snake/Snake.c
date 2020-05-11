#include "Snake.h"

Snake* CreateSnake()
{
	Snake* kigyo = (Snake*)calloc(1, sizeof(Snake));
	if (!kigyo) {
		printf("Nem sikerult helyet foglalni");			//Ellenorzes
		return 0;
	}
	kigyo->adatok = (Coordinate*)calloc(2, sizeof(Coordinate));
	if (!kigyo->adatok) {
		printf("Nem sikerult helyet foglalni");			//Ellenorzes
		return 0;
	}
	kigyo->adatok[0].x = 0;
	kigyo->adatok[0].y = 0;

	kigyo->adatok[1].x = 1;
	kigyo->adatok[1].y = 0;

}
