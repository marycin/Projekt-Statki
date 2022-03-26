#include "EndGame.h"

EndGame::EndGame(float width, float height) {
	if (!font.loadFromFile("arial.ttf")) {
		cout << "Nie ma czcionki" << endl;
	}
	this->youWon.setFont(font);										//³aduje czcionke
	this->youWon.setFillColor(Color::White);						//ustawia kolor czcionki na bia³y
	this->youWon.setString("Wygrales!");							//ustawia napis do wyœwietlenia
	this->youWon.setCharacterSize(100);								//ustawia rozmiar czcionki
	this->youWon.setPosition(Vector2f(width / 2, height / 1));		// ustawia pozycje elementu

	this->youLost.setFont(font);
	this->youLost.setFillColor(Color::White);
	this->youLost.setString("Przegrales :(");
	this->youLost.setCharacterSize(100);
	this->youLost.setPosition(Vector2f(width / 2, height / 1));		//konstruktor klasy Endgame, ustawiajaca napisy koñcowe.

}

void EndGame::draw(RenderTarget& target, RenderStates states) const {
	if(winner)
		target.draw(youWon);
	else
		target.draw(youLost);
																			//Ustawia napis do wyœwietlenia
}

void EndGame::PassWinner(bool b) {
	this->winner = b;					//przekazuje zwyciêzce, który potem zostanie wyœwietlony
}