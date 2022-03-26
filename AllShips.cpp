#include "AllShips.h"
#include<iostream>

using namespace std;

AllShips::AllShips() {
	for (int i = 0; i < amountToPlace; i++)
		this->allShips.emplace_back(theirSize[i],i); //Konstruktor clasy AllShips, która przechowuje statki.
}

vector<Ship> AllShips::returnShips() {
	return this->allShips;//zwraca wektor przechowuj¹cy objekty statków
}
 
int AllShips::returnAmountToPlace() {
	return this->amountToPlace;			//
}


map<Ship, vector<string>> AllShips::zwrocPozycje() {
	return this->wszystkiePozycje;						//
}

void AllShips::statekTrafiony(int id, AllSquares& squares) {
	for (auto& statek : this->allShips) {						//
		if (statek.getID() == id) {
			statek.ustawPolaPoZniszczeniu(squares);				//
		}
	}
}



void AllShips::UstawPozycje(int id, int x, int y) {		//ustawia pozycje
	for (auto& statek : this->allShips) {
		if (statek.getID() == id) {
			statek.setPosXPosY(x, y);					//ustawia pozycje statku
			break;
		}
			
	}
}

void AllShips::ZmienRotacje(int id) {
	for (auto& statek : this->allShips) { 
		if (statek.getID() == id) {			//szuka statku o podanym id
			statek.changeRotation();		 //obraca statek  na planszy 
			break;
		}
			
	}
}

bool AllShips::CzyStatekJestDoZniszczenia(int id) {
	for (auto& statek : this->allShips) {
		if (statek.getID() == id) {					//szuka statku o podanym id
			statek.Hit();
			if (statek.getSize() - statek.getHit() > 0) //sprawdza czy statek ma wszystkie zniszczone pola.
				return false;
			else
				return true;
		}
	}
}
