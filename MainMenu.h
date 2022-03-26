#pragma once
#include"SFML/Graphics.hpp"
#include<iostream>

#define MAX_NUMBER_OF_ITEMS 2 //informuje o liczbie elementów w menu

using namespace std;
using namespace sf;
class MainMenu : public sf::Drawable
{
public:
	MainMenu(float width, float height);
	MainMenu() = delete;
	~MainMenu() = default;

	void MoveUp();
	void MoveDown();
	int MainMenuPressed() {
		return selectedItemIndex;
	}
private:
	virtual void draw(RenderTarget& target, RenderStates states) const override;//wirtualna funkcja rysuj¹ca


	int selectedItemIndex=0;			 //zmienna informuje o aktualnie wybranym elemencie w menu
	Font font;							//zmienna z biblioteki SFML przechowuj¹ca czcionke
	Text menu[MAX_NUMBER_OF_ITEMS];		//zmienna przechowuj¹ca tekst elementów w menu
};