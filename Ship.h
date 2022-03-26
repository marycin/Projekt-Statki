#pragma once
#include"AllSquares.h"
#include"Square.h"
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<list>



class Ship
{
private:
	int id; //id statku
	int size; //rozmiar statku
	int pos_x; //pozycja X statku 
	int pos_y; //pozycja Y statku
	int x_rotation; //zmienna pomocnicza dla polozenia statku
	int y_rotation; //zmienna pomocnicza dla polozenia statku
	int hitCount{0}; //licznik trafien w statek
	bool destroyed{false}; //informuje ze statek jest 
	bool rotation{true}; //informuje o rotacji statku, domyslnie statek jest ustawiony horyzontalnie
	vector<Square> ship; // wektor przechowujacy kwadraty na ktorych umiejscowiony jest statek
	vector<string> pozycje; //wektor przechowujacy id kwadratow w postaci string na ktorych znajduje sie statek

public:
	Ship(int t_size,int t_id);
	void UstawStatkiNaPlanszy(AllSquares& squares1, int t_y, int t_x, bool arrowPressed,bool enterPressed);
	int getSize();
	void changeRotation();
	int getRotationX();
	int getRotationY();
	void setDefaultRotation();
	void Hit();
	vector<string> zwrocPozycje();
	bool czyZniszczony();
	void ustawPolaPoZniszczeniu(AllSquares& squares1);
	void setPosXPosY(int t_x, int t_y);
	bool porownajPozycje(string& pos);
	int getID();
	int getPosX();
	int getPosY();
	int getHit();

};

