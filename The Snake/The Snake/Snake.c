#include "Snake.h"

Snake* CreateSnake()
{
	Snake* kigyo = (Snake*)calloc(1, sizeof(Snake));
	if (!kigyo) {
		printf("Nem sikerult helyet foglalni");			//Ellenorzes
		return 0;
	}
	
	//KIGYO KEZDETLEGES KOORDINATAI
	kigyo->row = 2;
	kigyo->col = 2;
	kigyo->irany = 6; 
	return kigyo;
}


//KIGYO MOZGTASA - 8 FEL, 2 LE, 4 BALRA, 6 JOBBRA
void MoveHead(Snake* kigyo, int irany)
{
	if (irany != 0) {
		kigyo->irany = irany;
	}
	if (kigyo->irany == 8) {
		kigyo->row--;
	}
	if (kigyo->irany == 2) {
		kigyo->row++;
	}
	if (kigyo->irany == 4) {
		kigyo->col--;
	}
	if (kigyo->irany == 6) {
		kigyo->col++;
	}
}
