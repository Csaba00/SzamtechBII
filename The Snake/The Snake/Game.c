#include "Game.h"
#include <Windows.h>
#include <conio.h>
 

Game* CreateGame(char* filename, int speed, int timelimit)
{
	Game* jatek = (Game*)calloc(1, sizeof(Game));
	if (!jatek) {
		printf("Nem sikerult helyet foglalni");			//Ellenorzes
		return 0;
	}
	jatek->timelimit = timelimit;
	jatek->speed = speed;
	jatek->score = 0;
	jatek->palya = CreateMap(filename);
	jatek->kigyo = CreateSnake();
	return jatek;
}

void Play(Game* jatek)
{
	//INICIALIZALAS
	int row=0, col=0;
	int lastrow=0, lastcol=0;
	int timer = 0;

	//KIGYO BERAJZOLASA A JELENLGEI MAP-RA
	row = jatek->kigyo->row;
	col = jatek->kigyo->col;
	jatek->palya->map[row][col] = 6; 

	//RANDOM LEGELSO ALMA GENERALASA
	srand(time(0));

	while (jatek->palya->map[row][col] != 0) {
		row = rand() % 10;
		col = rand() % 20;
	}
	jatek->palya->map[row][col] = 5;

	Kiir(jatek->palya);
	//KIGYO MOZGATASA
	printf("Pontszam: %i\n", jatek->score);
	srand(time(NULL));
	time_t currentTime, startTime;
	startTime = time(NULL);
	while (1) {	
		if (GetAsyncKeyState(VK_RIGHT))
			jatek->kigyo->irany = 6;
		else if (GetAsyncKeyState(VK_UP))
			jatek->kigyo->irany = 8;
		else if (GetAsyncKeyState(VK_LEFT))
			jatek->kigyo->irany = 4;
		else if (GetAsyncKeyState(VK_DOWN))
			jatek->kigyo->irany = 2;
		Sleep(jatek->speed);
			
		system("CLS");


		lastrow = jatek->kigyo->row;
		lastcol = jatek->kigyo->col;

		//KIGYO MOZGTASA
		MoveHead(jatek->kigyo, jatek->kigyo->irany);
		

		//LEGUTOLSO POZICIO TORLESE
		jatek->palya->map[lastrow][lastcol] = 0;

		//UJ KIGYO KOORDINATAI
		row = jatek->kigyo->row;
		col = jatek->kigyo->col;

		//UTKOZES TESZT
		if (jatek->palya->map[row][col] == 1 || jatek->palya->map[row][col] == 7 || jatek->palya->map[row][col] == 2 || jatek->palya->map[row][col] == 3) {
			jatek->palya->map[row][col] = 6;
			Kiir(jatek->palya);
			Sleep(1000);
			break;
		}

		//KIGYO BERAJZOLASA A JELENLGEI MAP-RA
		Apple(jatek);
		jatek->palya->map[row][col] = 6; 
		currentTime = time(NULL);
		timer = currentTime - startTime;
		printf("Pontszam: %i  Ido: %i mp\n", jatek->score, timer);
		Kiir(jatek->palya);
		//TIMELIMIT KEZELES
		if (timer >= jatek->timelimit) {
			system("CLS");
			printf("Pontszamod: %i\n", jatek->score);
			printf("\n");
			printf("Lejart az ido!\n");
			Sleep(3000);
			system("CLS");
			break;
		}
	}
		//GAME OVER KEZELES
		if (timer < jatek->timelimit) {
			system("CLS");
			printf("Pontszamod: %i\n", jatek->score);
			printf(" \nGAME OVER\n ");
			Sleep(3000);
			system("CLS");
		}

}

//ALMA RANDOM GENERALASA
void Apple(Game* jatek)
{
		srand(time(0));
		int row, col;
		row = jatek->kigyo->row;
		col = jatek->kigyo->col;
		if (jatek->palya->map[row][col] == 5){
		while (jatek->palya->map[row][col] != 0) {
			row = rand() % jatek->palya->row;
			col = rand() % jatek->palya->col;
		}
		jatek->palya->map[row][col] = 5;
		jatek->score++;
	}
}

