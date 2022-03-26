#pragma once
#include <SFML/Graphics.hpp>
#include<string>


using namespace sf;
using namespace std;
class Square : public sf::Drawable
{
public:
	Square(float size, float t_x, float t_y, int p_x, int p_y);
	Square() = delete;
	~Square() = default;

	bool getAbleToPlace();
	bool getPlaced();

	Vector2f getPosition();
	int getPosY() const;
	int getPosX() const;

	void changeClickedValue(bool b);
	void changeSelectedValue(bool b);
	void changePlacedValue();
	void setUnableToPlace();
	void setMiss();
	void setHit();
	void setDestroyed();
	
	bool getHit();
	bool getMiss();
	bool getDestroyed();
	void setInvisible();
	bool getInvisible();
	void setBackgroundDestroyed();
	

	string returnPosXPosY();

private:
	bool invisible{ false }; //informuje czy statek umieszczony na kwadracie jest widoczny
	RectangleShape shape; //zmienna z biblioteki sfml, przechowuje takie parametry jak rozmiar, umiejscowienie i kolor kwadratu
	bool clicked{ false };//informuje czy kwadrat zosta³ klikniety przez gracza
	bool selected{ false };//informuje czy kwadrat zosta³ wybrany
	bool placed{ false }; //informuje czy na kwadracie znajduje siê statek
	bool AbleToPlace{ true }; //informuje czy jest mo¿liwoœæ postawienia statku na kwadracie
	bool destroyed{ false }; //informuje czy statek, który jest na kwadracie zostal zniszczony
	int pos_x; //pozycja x
	int pos_y; //pozycja y
	vector<Square> ship;
	bool hit{ false }; //informuje czy statek na kwadracie zosta³ trafiony
	bool miss{ false }; //informuje po trafieniu ze na tym kwadracie nie znajduje sie sta
	virtual void draw(RenderTarget& target, RenderStates states) const override;

};

