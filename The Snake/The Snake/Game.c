#include "Game.h"

Game* CreateGame()
{
	Game* game = (Game*)calloc(1, sizeof(Game));
	if (!game) {
		printf("Nem sikerult helyet foglalni");			//Ellenorzes
		return 0;
	}
	Map* palya;
	palya = CreateMap("Palya1.txt");

	Snake* kigyo;
	kigyo = CreateSnake();
}

void Play()
{

}
