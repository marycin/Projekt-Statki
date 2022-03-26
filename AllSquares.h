#pragma once
#include "Square.h"
#include<iostream>

class AllSquares
{
private:
	vector<Square> squares; //wektor przechowujacy wszysktie obiekty klasy Squares
	int squaresX{ 10 };  //ilosc kwadratow w osi X
	int squaresY{ 10 }; //ilosc kwadratow w osi Y
	float squaresSize{ 40.f }; //rozmiar kwadratu
public:
	AllSquares (int space);
	vector<Square>&  returnAll();
	void setDefault();
	bool AbleToPlace(int t_x, int t_y, int x_rotation, int y_rotation);
	bool AbleToSelect(int t_x, int t_y);
	void setInvisible();
	string zwrocKlikniety(Vector2f v);
	bool CzyKwadratKlikniety(Vector2f v);
};



