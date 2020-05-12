#include "Game.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>


int main() {
	Game* jatek;
	jatek = CreateGame();
	Play(jatek);
  
	
}