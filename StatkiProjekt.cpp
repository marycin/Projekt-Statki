=#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include "AllSquares.h"
#include "Square.h"
#include "Ship.h"
#include"AllShips.h"
#include<string>
#include<cstdlib>
#include<time.h>
#include"SeaBattle.h"
#include"MainMenu.h"
#include"EndGame.h"



using namespace sf;
using namespace std;

int main()
{
    //zmienne sluzace do rozpoczecia gry
    RenderWindow window(VideoMode(1200, 700), "Statki");
    AllSquares squares1(1), squares2(17);
    AllShips mShips,eShips;
    SeaBattle seaBattle(mShips, eShips);
    MainMenu mainMenu(window.getSize().x, window.getSize().y);
    EndGame endGame(window.getSize().x, window.getSize().y);
    Font font;
    font.loadFromFile("arial.ttf"); //zaladowanie czcionki
    Text description("R - Obracanie statkow\nU - Ustawienie wszystkich statkow",font,20);
    description.setPosition(10, 600); //ustawienie opisu o funkcji klawiszy
    description.setFillColor(Color::White);
    //zmienne pomocnicze, okreslajace poczatek, koniec gry i zwyciezce
    bool StartGame = false;
    bool End= false;
    bool YouWon = false;

    srand(time(NULL));

    vector<Ship> myShips = mShips.returnShips();
    vector<Ship> enemyShips = eShips.returnShips();
    
    myShips[0].UstawStatkiNaPlanszy(squares1, 0, 0, true, false);

    window.setKeyRepeatEnabled(false);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (StartGame) {
                seaBattle.PlayTheGame(squares1, squares2, event, window);//wywolanie funkcji rozpoczynajacej gre
                if (seaBattle.KoniecGry()) { 
                    StartGame = false;
                    YouWon = seaBattle.ZwrocZwyciezce();
                    endGame.PassWinner(YouWon);//przekazywanie zwyciezcy
                    End = true;
                }
            } 
            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::Up && !StartGame) {//wybieranie elementu w menu
                    mainMenu.MoveUp();
                    break;
                }
                if (event.key.code == Keyboard::Down && !StartGame) {
                    mainMenu.MoveDown();
                    break;
                }
                if (event.key.code == Keyboard::Return && !StartGame) {
                    int x = mainMenu.MainMenuPressed();
                    if (x == 0) {
                        StartGame = true;//rozpoczecie gry
                        break;
                    }
                    if (x == 1) {
                        window.close();
                        break;
                    }
                }
                if (event.key.code == Keyboard::Return && End && !StartGame)
                    window.close();
            }
        } 
        window.clear(Color::Black);
        if (!StartGame && !End)
            window.draw(mainMenu); //rysowanie elementów menu
        if(!End && StartGame) {
            for (auto& square : squares1.returnAll()) {
                window.draw(square);//rysowanie kwadratow gracza
            }
            for (auto& square : squares2.returnAll()) {
                window.draw(square);//rysowanie kwadratow przeciwnika
            }
            window.draw(description);//rysowanie opisu
        }
        if (End) {
            window.draw(endGame);
        }
        
        window.display();
    }
    return 0;
}

