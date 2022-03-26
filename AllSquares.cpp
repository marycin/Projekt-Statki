#include "AllSquares.h"



AllSquares::AllSquares(int space) { //konstruktor klasy AllSquares
	for (int i = 0; i < squaresY; i++) {
		for (int j = 0; j < squaresX; j++) {
			this->squares.emplace_back(squaresSize, (i + space) * (squaresSize + 5), (j + 1) * (squaresSize + 5), i, j);
		}
	}
}

vector<Square>& AllSquares::returnAll() {
	return this->squares; //zwraca wektor squares
}

void AllSquares::setDefault() { //s³u¿y do ustawienia kolorów kwadrató w zale¿noœci od ich pól
	for (auto& square : this->squares) {
		if (!square.getPlaced() && !square.getMiss() && !square.getHit() && !square.getDestroyed() ) {
			square.changeClickedValue(false);
			square.changeSelectedValue(false);
		}
		else if (square.getPlaced() && !square.getHit() && !square.getDestroyed() && !square.getInvisible())
			square.changePlacedValue();
		else if (square.getMiss() && !square.getDestroyed())
			square.setMiss();
		else if (square.getHit() && !square.getDestroyed())
			square.setHit();
		else if (square.getDestroyed() && square.getPlaced()) {
			square.setDestroyed();
		}
		else if (square.getDestroyed() && !square.getAbleToPlace() && !square.getPlaced()) {
			square.setBackgroundDestroyed();
		}
		else if (square.getInvisible() && !square.getDestroyed() && !square.getHit() && !square.getMiss()) {
			square.setInvisible();
		}

	}
}

bool AllSquares::AbleToPlace(int t_x, int t_y, int x_rotation, int y_rotation) { // funkcja s³u¿¹ca do sprawdzenia czy mo¿na postawiæ statek na danych kwadratach
	for (auto& square : this->squares) {
		if (square.getPosX() <= t_x + (x_rotation - 1) && square.getPosX() >= t_x && square.getPosY() <= t_y + (y_rotation - 1) && square.getPosY() >= t_y) {
			if (!square.getAbleToPlace()) //warunek sprawdza czy kwadraty na których statek gracz chce postawiæ statek nie s¹ zajête
				return false;		
		}
	}
	return true;
}


void AllSquares::setInvisible() {
	for (auto& square : this->squares) { //ustawia statki na niewidoczne
		square.setInvisible();
	}

}

string AllSquares::zwrocKlikniety(Vector2f v) //funkcja zwraca pozycje kliknietego kwadratu w postaci stringa
{
	for (auto& square : this->squares) {
		if (abs(square.getPosition().x - v.x) <20.f && abs(square.getPosition().y - v.y) < 20.f) {
			string x = to_string(square.getPosX());
			string y = to_string(square.getPosY()); 
			return x+y;
		}
	}
	
}

bool AllSquares::CzyKwadratKlikniety(Vector2f v) 
{
	for (auto& square : this->squares) {
		if (abs(square.getPosition().x - v.x) < 20.f && abs(square.getPosition().y - v.y) < 20.f) {
			return true;
		}
	}
	return false;
}

bool AllSquares::AbleToSelect(int t_x, int t_y) { //funkcja sprawdza czy kwadrat ktory chce wybrac gracz nie zostal przedtem wybrany
	for (auto& square : this->squares) {
		if (square.getPosX() == t_x  && square.getPosY() == t_y ) {
			if (!square.getDestroyed() && !square.getHit() && !square.getMiss())
				return true;
			else
				return false;
		}
	}

}
