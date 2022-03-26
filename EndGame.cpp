#include "EndGame.h"

EndGame::EndGame(float width, float height) {
	if (!font.loadFromFile("arial.ttf")) {
		cout << "Nie ma czcionki" << endl;
	}
	this->youWon.setFont(font);										//�aduje czcionke
	this->youWon.setFillColor(Color::White);						//ustawia kolor czcionki na bia�y
	this->youWon.setString("Wygrales!");							//ustawia napis do wy�wietlenia
	this->youWon.setCharacterSize(100);								//ustawia rozmiar czcionki
	this->youWon.setPosition(Vector2f(width / 2, height / 1));		// ustawia pozycje elementu

	this->youLost.setFont(font);
	this->youLost.setFillColor(Color::White);
	this->youLost.setString("Przegrales :(");
	this->youLost.setCharacterSize(100);
	this->youLost.setPosition(Vector2f(width / 2, height / 1));		//konstruktor klasy Endgame, ustawiajaca napisy ko�cowe.

}

void EndGame::draw(RenderTarget& target, RenderStates states) const {
	if(winner)
		target.draw(youWon);
	else
		target.draw(youLost);
																			//Ustawia napis do wy�wietlenia
}

void EndGame::PassWinner(bool b) {
	this->winner = b;					//przekazuje zwyci�zce, kt�ry potem zostanie wy�wietlony
}