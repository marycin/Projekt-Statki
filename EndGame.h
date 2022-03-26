#pragma once
#include"SFML/Graphics.hpp"
#include<iostream>


using namespace std;
using namespace sf;
class EndGame : public sf::Drawable
{
public:
	EndGame(float width, float height);
	EndGame() = delete;
	~EndGame() = default;

	void PassWinner(bool b);

private:
	virtual void draw(RenderTarget& target, RenderStates states) const override;

	Font font;				//zmienna przechowujaca czcionke
	Text youWon;			// zmienna przechowujaca tekst w przypadku gdy gracz wygra
	Text youLost;			// zmienna przechowujaca tekst w przypadku gdy gracz przegra
	bool winner{true};		//zmienna informujaca o zwyciezcy
};