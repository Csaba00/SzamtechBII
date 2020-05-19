#include "Game.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>


int main() {
	Game* jatek;
	int option = 0;
	time_t currentTime, startTime;
	startTime = time(NULL);
	currentTime = time(NULL);

	//MENU
	while (option != 99) {
		printf("Udvozlunk a jatekban! \n");
		printf("\n");
		printf("Start - 1. \n");
		printf("Help - 2.\n");
		printf("Exit - 3.\n");

		printf("\nUj opcio: ");
		scanf("%i", &option);
		system("CLS");

		switch (option) {
		case 1:
			printf("Valassz palyat: \n");
			printf("\n");
			printf("Easy - 1.\n");
			printf("Medium - 2.\n");
			printf("Hard - 3.\n");
			printf("\n");
			printf("Back - 4.\n");

			printf("\nUj opcio: ");
			scanf("%i", &option);

			switch (option) {
			case 1:
				jatek = CreateGame("Palya3.txt", 1, 40);
				Play(jatek);
				break;
			case 2:
				jatek = CreateGame("Palya2.txt", 50, 30);
				Play(jatek);
				break;
			case 3:
				jatek = CreateGame("Palya1.txt", 20, 25);
				Play(jatek);
				break;
			case 4:
				system("CLS");
				break;
			default:
				printf("\nHibas parancs!");
				Sleep(1000);
				system("CLS");
				break;
			}

			break;
		case 2:
			printf("MOZGATAS: Nyilak -> FEL, LE, JOBBRA, BALRA\n");
			printf("\n");
			printf("CEL: Minel tobb pontszamot szerezni a megadott idon belul.\n");
			printf("\n");
			printf("1.Map -> 40s\n");
			printf("2.Map -> 30s\n");
			printf("3.Map -> 25s\n");
			printf("\n");
			printf("Nyomj egy gombot a tovabblepeshez.\n");
			getch();
			system("CLS");
			break;
		case 3: 
			exit(0);
		default:
			printf("\nHibas parancs!");
			Sleep(1000);
			system("CLS");
			break;
		}
	}
	scanf("%i", &option);
}


