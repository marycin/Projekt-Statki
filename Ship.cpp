#include "Ship.h"

using namespace std;

Ship::Ship(int t_size,int t_id) {
	this->size = t_size;
	this->x_rotation = t_size;
	this->y_rotation = 1;
	this -> id = t_id;
	//konstruktor klasy Ship, ustawiajacy pozycje statku, jego wielko�� oraz jego identyfikator.
}


void Ship::UstawStatkiNaPlanszy(AllSquares& squares1, int t_x, int t_y, bool arrowPressed, bool enterPressed) {
	if (arrowPressed) {//sprawdza czy strzalki zostaly klikniete
		for (auto& square : squares1.returnAll()) {
			if (square.getPosY() <= t_y + (y_rotation - 1) && square.getPosY() >= t_y && square.getPosX() <= t_x + (x_rotation - 1) && square.getPosX() >= t_x) {
				square.changeSelectedValue(arrowPressed);
			}
		}//przesuwa statek o pozycj� przes�an� przez parametr t_x oraz t_y
	}
	if (enterPressed && squares1.AbleToPlace(t_x, t_y, x_rotation, y_rotation)) { 
		this->pos_x = t_x;
		this->pos_y = t_y;
		for (auto& square : squares1.returnAll()) { 
			if (square.getPosY() <= t_y + (y_rotation - 1) && square.getPosY() >= t_y && square.getPosX() <= t_x + (x_rotation - 1) && square.getPosX() >= t_x && square.getAbleToPlace()) {
				this->ship.emplace_back(40, 10, 10, square.getPosX(), square.getPosY()); 
				pozycje.push_back(square.returnPosXPosY());
				square.changePlacedValue(); //zmienia warto�� placed kwadratu na true
				
			}
			if (square.getPosY() >= t_y - 1 && square.getPosY() <= t_y + y_rotation && square.getPosX() >= t_x - 1 && square.getPosX() <= t_x + x_rotation)
			{
				square.setUnableToPlace();//ustawia kwadraty dookola statku na setUnableToPlace()
			}
		}
	}
} 



int Ship::getSize() {
	return size;//funkcja zwraca warto�� size, kt�ra informuje  o wielko��i statku.
}

int Ship::getHit() {
	return this->hitCount; //funkcja zwrata warto�� hitCount, kt�ra informuje o ilo�ci trafien w statek
}

void Ship::changeRotation() {
	this->rotation = !rotation;
	if (rotation) {
		x_rotation = this->size;
		y_rotation = 1;
	}
	else {
		y_rotation = this->size;
		x_rotation = 1;
	}//funkcja obraca statek na planszy
}


int Ship::getID() {
	return this->id; //zwraca id statku
}

int Ship::getPosX() {
	return this->pos_x; //zwraca pozycje X statku
}

int Ship::getPosY() {
	return this->pos_y;//zwraaca pozycje Y statku
}

int Ship::getRotationX() {
	return this->x_rotation; //zwraca warto�� x_rotation, kt�ra s�u�y do obracania statku na planszy
}

int Ship::getRotationY() {
	return this->y_rotation; //zwraca warto�� x_rotation, kt�ra s�u�y do obracania statku na planszy
}

void Ship::setDefaultRotation() {
	this->x_rotation = this->size;
	this->y_rotation = 1; //obraca statek w spos�b standardowy, czyli horyzontalnie
}

void Ship::Hit() {
	this->hitCount++; //zwieksza warto�� hitCount statku, kt�ra informuje o ilo�ci trafie� w statek
}

vector<string> Ship::zwrocPozycje() {
	return pozycje; //zwraca wektor, kt�ry informuje o pozycjach kwadrat�w, na kt�rych umieszczony jest statek
}

bool Ship::czyZniszczony() {
	if (this->hitCount < this->size) { // jezeli ilo�� trafien jest mniejsza rozmiarowi statku 
		return false; //zwraca false
	}
	destroyed = true; // w przeciwnym wypadku ustawia statek na zniszczony i funkcja zwraca warto�� true
	return true;
}

void Ship::setPosXPosY(int x,int y) {
	this->pos_x = x;
	this->pos_y = y;
	//ustawia warto�� pozycji statku za pomoc� zmiennych przekazanych w parametrze funkcji
}

void Ship::ustawPolaPoZniszczeniu(AllSquares& squares1) {
	for (auto& square : squares1.returnAll()) {
		if (square.getPosY() >= this->pos_y - 1 && square.getPosY() <= this->pos_y + y_rotation && square.getPosX() >= this->pos_x - 1 && square.getPosX() <= this->pos_x + x_rotation)
		{
			if (square.getPlaced()) {
				square.setDestroyed();//ustawia pola na kt�rych by� statek jako zniszczone
			}
			else
				square.setBackgroundDestroyed();//ustawia pola otaczaj�ce statek jako niedost�pne
			
		}
	}
}

bool Ship::porownajPozycje(string& pos) {
	for (auto& p : this->pozycje) {
		if (p == pos) {
			return true;
		}	//funkcja por�wnuje wektor pozycji statku z pozycj� przekazan� przez parametr
	}
	return false;
}
