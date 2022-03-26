#pragma once
#include "Ship.h"

class AllShips
{
private:
	vector<Ship> allShips; //wektor przechowujacy obiekty klasy Ship
	int amountToPlace{ 10 }; //ilosc statkow do postawienia
	int theirSize[10]{ 4,3,3,2,2,2,1,1,1,1 }; //rozmiary poszczeg�lnych statk�w
	int destroyedShips = 0; //ilo�� zniszczonych statk�w
	map<Ship, vector<string>> wszystkiePozycje; //wektor zwracaj�cy pozycje wszystkich statk�w
public:
	AllShips();
	vector<Ship> returnShips();
	int returnAmountToPlace();
	map<Ship, vector<string>> zwrocPozycje();
	void statekTrafiony(int id, AllSquares& squares);
	void UstawPozycje(int id, int x, int y);
	void ZmienRotacje(int id);
	bool CzyStatekJestDoZniszczenia(int id);
};

