#include "Square.h"
#include<iostream>

using namespace std;

Square::Square(float size, float t_x, float t_y, int p_x, int p_y) { 
	shape.setPosition(t_x, t_y);
	shape.setSize({ size, size });
	shape.setFillColor(Color::Cyan);
	shape.setOrigin(size / 2, size / 2);
	this->pos_x = p_x;
	this->pos_y = p_y;
	//konstruktor klasy Square, ustawia pozycje oraz wielkoœæ obiektu
}

void Square::draw(RenderTarget& target, RenderStates state) const {
	target.draw(this->shape, state);
	//funkcja rysuj¹ca element
}

void Square::changeClickedValue(bool b) {
	this->clicked = b; //funkcja ustawia zmienna, która informuje o kliknieciu kwadratu na true
}


void Square::changeSelectedValue(bool b) {
	if (b) //funkcja ustawia kolor kwadratu w zaleznosci od jego stanu
	{
		if (hit == true && destroyed == false)
			shape.setFillColor(Color::Color(150, 150, 0, 255));
		else if (destroyed == true)
			shape.setFillColor(Color::Color(80, 0, 0, 255));
		else if (miss == true)
			shape.setFillColor(Color::Color(0, 150, 0, 255));
		else if (placed == true && destroyed == false)
			shape.setFillColor(Color::Color(150, 0, 150, 255));
		else
			shape.setFillColor(Color::Green);
		this->selected = true;
	}
	
	else {
		shape.setFillColor(Color::Cyan);
		this->selected = false;
	}
	
}

void Square::changePlacedValue() {
	shape.setFillColor(Color::Magenta);
	this->placed = true;
	//funkcja ustawia zmienna placed na true, która informuje, ¿e na tym kwadracie jest statek
}


Vector2f Square::getPosition() {
	return shape.getPosition();
	//zwraca pozycje kwadratu;
}

int Square::getPosX() const {
	return this->pos_x;
	//zwraca rz¹d kwadratu (wartoœæ x).
}

int Square::getPosY() const {
	return this->pos_y;
	//zwraca kolumne kwadratu (wartoœæ y).
}


void Square::setUnableToPlace() {
	this->AbleToPlace = false;
	//funkcja ustawia zmienna AbleToPlace na false, która uniemo¿liwia ustawienie statku na tym kwadracie.
}

bool Square::getAbleToPlace() {
	return AbleToPlace;
	//zwraca wartoœæ AbleToPlace;
}

bool Square::getPlaced() {
	return this->placed;
	//zwraca wartosæ placed;
}

void Square::setHit() {
	shape.setFillColor(Color::Yellow);
	this->hit = true;
	// funkcja ustawia wartosæ zmiennej hit na true oraz ustawia kolor kwadratu na zó³ty.
}

void Square::setMiss() {
	shape.setFillColor(Color::Black);
	this->miss = true;
	//funkcja ustawia wartoœæ zmiennej miss na true oraz ustawia kolor kwadratu na czarny.
}

bool Square::getHit() {
	return this->hit;
	//zwraca wartoœæ hit.
}

bool Square::getMiss() {
	return this->miss;
	//zwraca wartoœæ miss.
}

void Square::setDestroyed() {
	this->destroyed = true;
	shape.setFillColor(Color::Color(150,0,0,255));
	//funkcja zmienia wartoœæ zmiennej destroyed na true oraz ustawia kolor kwadratu na bordowy.
}

void Square::setBackgroundDestroyed() {
	this->destroyed = true;
	shape.setFillColor(Color::Red);
	//funkcja ustawia wartosc destroyed na true oraz ustawia kwadratu kolor na czerwony.
}



string Square::returnPosXPosY() {
	string x = to_string(this->pos_x);
	string y = to_string(this->pos_y);
	string toReturn = x + y;
	return toReturn;
	//funkcja zwraca pozycje X oraz pozycje Y w postaci stringa.
}

bool Square::getDestroyed() {
	return this->destroyed;
	//funkcja zwraca watoœæ destroyed.
}

bool Square::getInvisible() {
	return this->invisible;
	//funkcja zwraca wartoœæ invisible.
}

void Square::setInvisible() {
	shape.setFillColor(Color::Cyan);
	this->invisible = true;
	//funkcja ustawia wartoœæ invisible na true orz ustawia kolor kwadratu na morski.
}