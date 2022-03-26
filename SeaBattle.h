#pragma once
#include"AllSquares.h"
#include"AllShips.h"
#include"Ship.h"

class SeaBattle
{
private:
	AllShips mShips,eShips; //zmienna przechowuj¹ca obiekty Allships, czyli statki gracza oraz przeciwnika
	int my_t_x = 0; //zmienna slu¿aca do wybierania pola przez gracza
	int my_t_y = 0;//zmienna slu¿aca do wybierania pola przez gracza
	int computer_t_x = 0;//zmienna slu¿aca do wybierania pola przez komputer
	int computer_t_y = 0;//zmienna slu¿aca do wybierania pola przez komputer
	int ship_id = 0; //zmienna przechowuje aktualny id statku
	int amountMyShips = 10;//ilosc statkow gracza
	int amountEnemyShips = 10;//ilosc statkow przeciwnika
	vector<Ship> myShips, enemyShips; //wektor statkow gracza oraz przeciwnika
	bool AllPlaced{ false };//zmienna informujaca czy wszystkie stakti zostaly juz ustawione
	bool GameOver{ false };//zmienna informuj¹ca o koncu gry
	bool switchSide{ true }; //zmienna zmienia ture, w przypadku true -> gracz ma ruch, w przeciwnym przypadku jest ruch komputera
	int enemyShip_id = 0;//zmienna przechowuje aktualny id statku przeciwnika
	int enemyShipsCount;//ilosc statkow gracza przeciwnika
	int enemy_tx, enemy_ty;//zmienne slu¿ace do wybierania pola przez komputer
	int pocz¹tkowa_pozycja_trafienia_x; //w przypadku trafienia w statek przez komputer do tych zmiennych przypisuje sie pozycje
	int pocz¹tkowa_pozycja_trafienia_y;

	bool statkiBotaUstawione{ false };//informuje czy statki przeciwnika zostaly ustawione
	map<int, vector<string>> mojePozycje; //mapa przechowujaca id statku oraz jego pozycje
	map<int, vector<string>> enemyPozycje;//mapa przechowujaca id statku oraz jego pozycje

	bool pierwszyRazTrafiony{ true }; //zmienne pomocnicza dla AI
	bool os_x{ true };
	bool os_y{ true };
	bool zmiana_kierunku{ false };
	bool zmiana_osi{ false };
	bool traf{ false };

	int idStatkuEnemy; //zmienna przechowuj¹ca id trafionego statku enemy


	int zwrocIdStatku(string pos, map<int, vector<string>> map);

	void UstawDomyslnieKierunki();
	void ZmianaKierunku();
	void ObierzKierunek(bool trafia);
	void CelownikDlaKomputera(AllSquares& squares, int t_x, int t_y);


	void PoruszanieSiePoPlanszy(Event& event, AllSquares& squares);
	void NamierzanieCelu(Event& event, AllSquares& squares, Window& window);
	void Celownik(AllSquares& squares, bool enterPressed, int t_x, int t_y);

	void NamierzanieCeluPrzezKomputer(AllSquares& squares);
	

public:
	SeaBattle(AllShips& mShips, AllShips& eShips);
	void PlayTheGame(AllSquares& mySquares, AllSquares& enemySquares, Event& event, Window& window);
	bool KoniecGry();
	bool ZwrocZwyciezce();
	
	
};

