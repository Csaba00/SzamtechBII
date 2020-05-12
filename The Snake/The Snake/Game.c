#include "Game.h"
#include <Windows.h>
#include <conio.h>

Game* CreateGame()
{
	Game* jatek = (Game*)calloc(1, sizeof(Game));
	if (!jatek) {
		printf("Nem sikerult helyet foglalni");			//Ellenorzes
		return 0;
	}
	jatek->palya = CreateMap("Palya3.txt");
	jatek->kigyo = CreateSnake();
	return jatek;
}

void Play(Game* jatek)
{
	int row=0, col=0;
	int lastRow, lastCol;
	int fejrow, fejcol;
	int fejIrany=0;
	for (int i = 0; i < jatek->kigyo->hossz; ++i) {
		row = jatek->kigyo->adatok[i].row;
		col = jatek->kigyo->adatok[i].col;
		jatek->palya->map[row][col] = 6; //snake koordinates
	}
	Kiir(jatek->palya);

	while (1) {	
		switch (getch()) { 
		case 'w':
			fejIrany = 8;
			break;
		case 'a':
			fejIrany = 4;
			break;
		case 's':
			fejIrany = 2;
			break;
		case 'd':
			fejIrany = 6   ;
			break;
		}
		system("CLS");
		//gombnyomaskor valtozik a fejIrany
		MoveHead(jatek->kigyo, fejIrany);
		fejrow = jatek->kigyo->adatok[jatek->kigyo->hossz - 1].row;
		fejcol = jatek->kigyo->adatok[jatek->kigyo->hossz - 1].col;

		lastRow = jatek->kigyo->adatok[0].row;
		lastCol = jatek->kigyo->adatok[0].col;
		Move(jatek->kigyo);

		ClearLastPosition(jatek->palya, lastRow, lastCol);

		if (CollisionTest(jatek->palya, fejrow, fejcol) == true) {
			for (int i = 0; i < jatek->kigyo->hossz; ++i) {
				row = jatek->kigyo->adatok[i].row;
				col = jatek->kigyo->adatok[i].col;
				jatek->palya->map[row][col] = 6; //snake koordinates
			}
			Kiir(jatek->palya);
			break;
		}



		//berajzolja a kigyot
		for (int i = 0; i < jatek->kigyo->hossz; ++i) {
			row = jatek->kigyo->adatok[i].row;  
			col = jatek->kigyo->adatok[i].col;
			jatek->palya->map[row][col] = 6; //snake koordinates
		}
		//printf("%i ", col); 
		
		
		Kiir(jatek->palya);
		
	}

}

bool CollisionTest(Map* palya, int row, int col)
{
	if (palya->map[row][col] == 1 || palya->map[row][col] == 7 || palya->map[row][col] == 2 || palya->map[row][col] == 3) {
		return true;
	}
	else {
		return false;
	}
}
