#include "Snake.h"

Snake* CreateSnake()
{
	Snake* kigyo = (Snake*)calloc(1, sizeof(Snake));
	if (!kigyo) {
		printf("Nem sikerult helyet foglalni");			//Ellenorzes
		return 0;
	}
	kigyo->adatok = (Bodypart*)calloc(3, sizeof(Bodypart));
	if (!kigyo->adatok) {
		printf("Nem sikerult helyet foglalni");			//Ellenorzes
		return 0;
	}
	kigyo->tores = (Tores*)calloc(0, sizeof(Tores));
	if (!kigyo->tores) {
		printf("Nem sikerult helyet foglalni");			//Ellenorzes
		return 0;
	}
	//fej az elso tores
	kigyo->torespontok = 0;
	/*kigyo->tores[0].row = 1;
	kigyo->tores[0].col = 2;
	kigyo->tores[0].irany = 6; //jobbra megy a kigyo
	kigyo->tores[0].hanyErtIde = 0;
	kigyo->tores[0].valid = true;*/

	kigyo->adatok[0].row = 1; //Kigyo kezdetleges Sor koordinata
	kigyo->adatok[0].col = 1; //Kigyo kezdetleges Oszlop koordinata
	kigyo->adatok[0].jelenlegiTores = 0;

	kigyo->adatok[0].irany = 6; //jobbra megy a kigyo
	kigyo->adatok[1].irany = 6; //jobbra megy a kigyo
	kigyo->adatok[2].irany = 6;
	//fej
	kigyo->adatok[1].row = 1; //Kigyo kezdetleges Sor koordinata
	kigyo->adatok[1].col = 2; //Kigyo kezdetleges Oszlop koordinata

	kigyo->adatok[2].row = 1;
	kigyo->adatok[2].col = 3;
	kigyo->adatok[2].jelenlegiTores = 0;

	kigyo->hossz = 3;
	return kigyo;
}

void Move(Snake* kigyo)
{
	int toresIrany;
	for (int i = 0; i < kigyo->hossz-1; ++i) {

		int jelenlegiTores = kigyo->adatok[i].jelenlegiTores;
		if (jelenlegiTores == kigyo->torespontok
			|| (kigyo->adatok[i].row!=kigyo->tores[jelenlegiTores].row
			|| kigyo->adatok[i].col!=kigyo->tores[jelenlegiTores].col)) {
			MoveMe(kigyo, i);
		}
		else {
			toresIrany = kigyo->tores[jelenlegiTores].irany;

			if (toresIrany == 8) {
				Up(kigyo, i);
			}
			if (toresIrany == 2) {
				Down(kigyo, i);
			}
			if (toresIrany == 4) {
				Left(kigyo, i);
			}
			if (toresIrany == 6) {
				Right(kigyo, i);
			}
			if (jelenlegiTores + 1 == kigyo->torespontok) {
				kigyo->adatok[i].irany = kigyo->adatok[kigyo->hossz - 1].irany;
				kigyo->adatok[i].jelenlegiTores++;
			}
			else {
				kigyo->adatok[i].irany = kigyo->tores[jelenlegiTores + 1].irany;
				//kigyo->adatok[i].jelenlegiTores++;
			}
		}		
	}
}

void Up(Snake* kigyo, int i)
{
	int jelenlegiTores = kigyo->adatok[i].jelenlegiTores;

	if (kigyo->tores[jelenlegiTores].row <= kigyo->adatok[i].row) { //Jobbra halad a kigyobodypartjai torispontig
		kigyo->adatok[i].row--;

	}

	/*if (jelenlegiTores + 1 == kigyo->torespontok) {
		kigyo->adatok[i].irany = kigyo->adatok[kigyo->hossz - 1].irany;
	}
	else {
		kigyo->adatok[i].irany = kigyo->tores[jelenlegiTores + 1].irany;
	}*/
}

void Down(Snake* kigyo, int i)
{
	int jelenlegiTores = kigyo->adatok[i].jelenlegiTores;

		if (kigyo->tores[jelenlegiTores].row >= kigyo->adatok[i].row) { //Jobbra halad a kigyobodypartjai torispontig
			kigyo->adatok[i].row++;

		}
		
		/*	if (jelenlegiTores + 1 == kigyo->torespontok) {
				kigyo->adatok[i].irany = kigyo->adatok[kigyo->hossz - 1].irany;
			}
			else {
				kigyo->adatok[i].irany = kigyo->tores[jelenlegiTores + 1].irany;
			}*/
		
	
}

void Right(Snake* kigyo, int i)
{
	int jelenlegiTores = kigyo->adatok[i].jelenlegiTores;
		if (kigyo->tores[jelenlegiTores].col >= kigyo->adatok[i].col) { //Jobbra halad a kigyobodypartjai torispontig
			kigyo->adatok[i].col++;
		}
		
			
		
	
}

void Left(Snake* kigyo, int i)
{
	int jelenlegiTores = kigyo->adatok[i].jelenlegiTores;

	if (kigyo->tores[jelenlegiTores].col <= kigyo->adatok[i].col) { //Jobbra halad a kigyobodypartjai torispontig
		kigyo->adatok[i].col--;

	}

	/*if (jelenlegiTores + 1 == kigyo->torespontok) {
		kigyo->adatok[i].irany = kigyo->adatok[kigyo->hossz - 1].irany;
	}
	else {
		kigyo->adatok[i].irany = kigyo->tores[jelenlegiTores + 1].irany;
	}*/
}

void MoveHead(Snake* kigyo, int irany)
{
	int poz = kigyo->hossz - 1;
	
		if (irany != kigyo->adatok[poz].irany && irany != 0) {
			kigyo->tores = (Tores*)realloc(kigyo->tores, (kigyo->torespontok + 1) * sizeof(Tores));

			Tores ujTores;
			ujTores.row = kigyo->adatok[poz].row;
			ujTores.col = kigyo->adatok[poz].col;
			ujTores.irany = irany;
			ujTores.valid = true;
			ujTores.hanyErtIde = 0;

			kigyo->tores[kigyo->torespontok] = ujTores;
			kigyo->torespontok++;

			kigyo->adatok[poz].irany = irany;
		}
	if (irany != 0) {
		kigyo->adatok[poz].irany = irany;
	}
	if (kigyo->adatok[poz].irany == 8) {
		kigyo->adatok[poz].row--;
	}
	if (kigyo->adatok[poz].irany == 2) {
		kigyo->adatok[poz].row++;
	}
	if (kigyo->adatok[poz].irany == 4) {
		kigyo->adatok[poz].col--;
	}
	if (kigyo->adatok[poz].irany == 6) {
		kigyo->adatok[poz].col++;
	}
	
}

void MoveMe(Snake* kigyo, int i)
{
	int irany = kigyo->adatok[i].irany;
	if (irany == 8) {
		kigyo->adatok[i].row--;
	}
	if (irany == 2) {
		kigyo->adatok[i].row++;
	}
	if (irany == 4) {
		kigyo->adatok[i].col--;
	}
	if (irany == 6) {
		kigyo->adatok[i].col++;
	}
}
