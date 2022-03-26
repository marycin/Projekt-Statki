#include "MainMenu.h"

MainMenu::MainMenu(float width, float height) { // Konstruktor klasy MainMenu
	if (!font.loadFromFile("arial.ttf")) { //laduje czcionke
		cout << "Nie ma czcionki" << endl;
	}
	this->menu[0].setFont(font); //ustawia czcionke
	this->menu[0].setFillColor(Color::White); //ustawia kolor czcionki na bialy
	this->menu[0].setString("Graj"); //ustawia tekst elementu
	this->menu[0].setCharacterSize(50); //rozmiar czcionki
	this->menu[0].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1)); //pozycja elementu

	this->menu[1].setFont(font);
	this->menu[1].setFillColor(Color::White);
	this->menu[1].setString("Wyjdz");
	this->menu[1].setCharacterSize(50);
	this->menu[1].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	menu[selectedItemIndex].setFillColor(Color::Cyan);
}

void MainMenu::draw(RenderTarget& target, RenderStates states) const { //funkcja rysuj¹ca elementy
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
		target.draw(menu[i]);
}

void MainMenu::MoveUp() {										//funkcja która zmienia element, który zosta³ wybrany w menu
	if (selectedItemIndex - 1 >=0) {
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		if (selectedItemIndex == -1)
			selectedItemIndex = 1;
		menu[selectedItemIndex].setFillColor(Color::Cyan);
	}
}

void MainMenu::MoveDown() {										//funkcja która zmienia element, który zosta³ wybrany w menu
	if (selectedItemIndex + 1 <= MAX_NUMBER_OF_ITEMS) {
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		if (selectedItemIndex == 2)
			selectedItemIndex =0;
		menu[selectedItemIndex].setFillColor(Color::Cyan);
	}
}