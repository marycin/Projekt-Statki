#include "SeaBattle.h"
#include<time.h>
#include <Windows.h>
#include<iostream>
#include<string>
#include<map>

using namespace std;

SeaBattle::SeaBattle(AllShips& myShips, AllShips& enemyShips) {
	this->mShips = myShips;
	this->eShips = enemyShips;
    this->myShips = mShips.returnShips();
    this->enemyShips = eShips.returnShips();
  

}

int SeaBattle::zwrocIdStatku(string pos, map<int,vector<string>> map) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == pos)
                return i;
        }
    }
  
}



void SeaBattle::Celownik(AllSquares& squares1,bool enterPressed,int t_x, int t_y) {
    for (auto& square : squares1.returnAll()) {
        if (enterPressed && square.getPosY() == t_y && square.getPosX() == t_x) {
            if (square.getPlaced() && !square.getDestroyed() && !square.getHit() && !square.getHit()) {
                int idStatkuEnemy = zwrocIdStatku(square.returnPosXPosY(), enemyPozycje);
                if (eShips.CzyStatekJestDoZniszczenia(idStatkuEnemy)) {
                    eShips.statekTrafiony(idStatkuEnemy, squares1);
                    amountEnemyShips--;
                    if (amountEnemyShips == 0)
                        GameOver = true;
                }
                else {
                    square.setHit();
                }
            }
            else {
                square.setMiss();
                switchSide =false;
                cout << "Moj switchside: " << switchSide << endl;
                my_t_x = 0;
                my_t_y = 0;
            }       
        }
        else {
            if (square.getPosY() == t_y && square.getPosX() == t_x) {
                square.changeSelectedValue(true);
            }
        }
    }
   
   
}

void SeaBattle::UstawDomyslnieKierunki() {
    os_x=true;
    os_y=true ;
    zmiana_kierunku=false;
    zmiana_osi=false ;
 
}


void SeaBattle::ZmianaKierunku() {
    if (!zmiana_osi && os_x) {
        os_x = false;
        cout << "zmienia na osx lewo" << endl;
    }
    else if (!zmiana_osi && !os_x) {
        zmiana_osi = true;
        cout << "zmiana osi" << endl;
    }
        
    else {
        if (os_y) {
            os_y = false;
            cout << "idzie w dol" << endl;
        }
    }
}

void SeaBattle::ObierzKierunek(bool trafiony) { 
    if (!zmiana_osi) {
        if (os_x) {
            if (trafiony && computer_t_x<10) {
                computer_t_x++;
                cout << "osx computer x: " << computer_t_x << endl;
            }
               
            else {
                computer_t_x = pocz¹tkowa_pozycja_trafienia_x - 1;
                cout << "zmienia sie osx computer x: " << computer_t_x << endl;
                switchSide = false;
                ZmianaKierunku();
            }
        }
        else {
            if (trafiony && computer_t_x>0) {
                computer_t_x--;
                cout << "nieosx computer x: " << computer_t_x << endl;
            }
            else {
                computer_t_x = pocz¹tkowa_pozycja_trafienia_x;
                cout << "zmienia sie na osycomputer x: " << computer_t_x << endl;
                computer_t_y = pocz¹tkowa_pozycja_trafienia_y - 1;
                switchSide = false;
                ZmianaKierunku();
            }
        }
    }
    else 
    {
        if (os_y) {
            if (trafiony && computer_t_y>0) {
                computer_t_y--;
                cout << "osy computer y: " << computer_t_y << endl;
            }
            else 
            {
                computer_t_y = pocz¹tkowa_pozycja_trafienia_y + 1;
                cout <<"zmienia sie osy osy computer y : " << computer_t_y << endl;
                switchSide = false;
                ZmianaKierunku();
            }
        }
        else {
            if (trafiony && computer_t_y<9) {
                computer_t_y++;
                cout << "nieosy computer y: " << computer_t_y << endl;
            }
                
        }
    }
   
}




void SeaBattle::CelownikDlaKomputera(AllSquares& squares,int t_x, int t_y) {
    for (auto& square : squares.returnAll()) {
        if (square.getPosY() == t_y && square.getPosX() == t_x) {
            if (!square.getDestroyed() && !square.getHit() && !square.getMiss()) {
                cout << "git2" << endl;
                if (square.getPlaced()) {
                    cout << "GET PLACED I GET DESTROYED" << endl;
                    traf = true;
                    idStatkuEnemy = zwrocIdStatku(square.returnPosXPosY(), mojePozycje);
                    cout << square.returnPosXPosY() << endl;
                    if (mShips.CzyStatekJestDoZniszczenia(idStatkuEnemy)) {
                        mShips.statekTrafiony(idStatkuEnemy, squares);
                        amountMyShips--;
                        pierwszyRazTrafiony = true;
                        traf = false;
                        cout << "STATEK DO ZNISZCZENIA" << endl;
                        UstawDomyslnieKierunki();
                        if (amountMyShips == 0)
                            GameOver = true;
                    }
                    else {
                        square.setHit();
                        cout << "KWADRAT DO TRAFIENIA" << endl;
                        if (pierwszyRazTrafiony) {
                            pocz¹tkowa_pozycja_trafienia_x = t_x;
                            pocz¹tkowa_pozycja_trafienia_y = t_y;
                            cout << "Poczatkowa x: " << pocz¹tkowa_pozycja_trafienia_x << "\nPoczatkowa y: " << pocz¹tkowa_pozycja_trafienia_y << endl;
                            pierwszyRazTrafiony = false;
                        }
                    }
                    
                }
                else {
                    square.setMiss();
                    traf = false;
                    switchSide = true;
                }
            }
            else if (square.getDestroyed() || square.getHit() || square.getMiss() || t_x<0 || t_x>9 || t_y<0 || t_y>9){
                cout << "wyjazd" << endl;
                if (!pierwszyRazTrafiony) traf = false; 
                break;
            }
        }
       
        
    }
}

void SeaBattle::NamierzanieCeluPrzezKomputer(AllSquares& squares1) {
    while (!switchSide) {
        if (!pierwszyRazTrafiony) {
            ObierzKierunek(traf);
            cout << "git" << endl;
        }
        else
        {
            computer_t_x = rand() % 10;
            computer_t_y = rand() % 10;
        }
        CelownikDlaKomputera(squares1, computer_t_x, computer_t_y);
    }
}


void SeaBattle::PoruszanieSiePoPlanszy(Event& event, AllSquares& squares) {
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::R)
        {
            myShips[ship_id].changeRotation();
            mShips.ZmienRotacje(ship_id);
            if (my_t_x + myShips[ship_id].getSize() > 10)
                my_t_x = 10 - myShips[ship_id].getSize();
            if (my_t_y + myShips[ship_id].getSize() > 10)
                my_t_y = 10 - myShips[ship_id].getSize();
            squares.setDefault();
            myShips[ship_id].UstawStatkiNaPlanszy(squares, my_t_x, my_t_y, true, false);
        }
        else if (event.key.code == sf::Keyboard::Left && my_t_x > 0)
        {
            squares.setDefault();
            my_t_x--;
            myShips[ship_id].UstawStatkiNaPlanszy(squares, my_t_x, my_t_y, true, false);
        }
        else if (event.key.code == sf::Keyboard::Right && my_t_x < 10 - myShips[ship_id].getRotationX())
        {
            squares.setDefault();
            my_t_x++;
            myShips[ship_id].UstawStatkiNaPlanszy(squares, my_t_x, my_t_y, true, false);
        }
        else if (event.key.code == sf::Keyboard::Up && my_t_y > 0)
        {
            squares.setDefault();
            my_t_y--;
            myShips[ship_id].UstawStatkiNaPlanszy(squares, my_t_x,my_t_y, true, false);
        }
        else if (event.key.code == sf::Keyboard::Down && my_t_y < 10 - myShips[ship_id].getRotationY())
        {
            squares.setDefault();
            my_t_y++;
            myShips[ship_id].UstawStatkiNaPlanszy(squares, my_t_x, my_t_y, true, false);
        }
        else if (event.key.code == sf::Keyboard::U && !AllPlaced)
        {
            while (ship_id<10) {
                my_t_x = rand() % (10 - myShips[ship_id].getRotationX());
                my_t_y = rand() % (10 - myShips[ship_id].getRotationY());
                if (squares.AbleToPlace(my_t_x, my_t_y, myShips[ship_id].getRotationX(), myShips[ship_id].getRotationY())) {
                    myShips[ship_id].UstawStatkiNaPlanszy(squares, my_t_x, my_t_y, false, true);
                    mShips.UstawPozycje(ship_id, my_t_x, my_t_y);
                    mojePozycje.insert(pair<int, vector<string>>(ship_id, myShips[ship_id].zwrocPozycje()));
                    ship_id++;
                    enemyShipsCount--;
                    if (ship_id == 10) {
                        AllPlaced = true;
                        my_t_x = 0;
                        my_t_y = 0;
                        squares.setDefault(); 
                        break;
                    }
                }
                else {
                    enemyShips[enemyShip_id].changeRotation();
                    eShips.ZmienRotacje(enemyShip_id);
                }
            }
        }
        else if (event.key.code == sf::Keyboard::Enter && squares.AbleToPlace(my_t_x, my_t_y, myShips[ship_id].getRotationX(), myShips[ship_id].getRotationY())) {
            myShips[ship_id].UstawStatkiNaPlanszy(squares, my_t_x, my_t_y, false, true);
            if (ship_id == 9) {
                mShips.UstawPozycje(ship_id, my_t_x, my_t_y);
                mojePozycje.insert(pair<int, vector<string>>(ship_id, myShips[ship_id].zwrocPozycje()));
                my_t_x = 0, my_t_y = 0;
                squares.setDefault();
                AllPlaced = true;
                my_t_x = 0, my_t_y = 0;
            }
            else {
                mShips.UstawPozycje(ship_id, my_t_x, my_t_y);
                mojePozycje.insert(pair<int, vector<string>>(ship_id, myShips[ship_id].zwrocPozycje()));
                ship_id++;
                my_t_x = 0, my_t_y = 0;
                squares.setDefault();
                myShips[ship_id].UstawStatkiNaPlanszy(squares, my_t_x, my_t_y, true, false);
                myShips[ship_id].setDefaultRotation();
            }
        }
    }
}

void SeaBattle::NamierzanieCelu(Event& event, AllSquares& squares, Window& window) {
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Enter && squares.AbleToSelect(my_t_x,my_t_y)) {
            Celownik(squares, true, my_t_x, my_t_y);
        }
        else if (event.key.code == sf::Keyboard::Left && my_t_x > 0)
        {
            squares.setDefault();
            my_t_x--;
            Celownik(squares, false, my_t_x, my_t_y);
        }
        else if (event.key.code == sf::Keyboard::Right && my_t_x < 9)
        {
            squares.setDefault();
            my_t_x++;
            Celownik(squares, false, my_t_x, my_t_y);
        }
        else if (event.key.code == sf::Keyboard::Up && my_t_y > 0)
        {
            squares.setDefault();
            my_t_y--;
            Celownik(squares, false, my_t_x, my_t_y);
        }
        else if (event.key.code == sf::Keyboard::Down && my_t_y < 9)
        {
            squares.setDefault();
            my_t_y++;
            Celownik(squares, false, my_t_x, my_t_y);
        }
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left && squares.CzyKwadratKlikniety(Vector2f(sf::Mouse::getPosition(window)))) {
            string pos = squares.zwrocKlikniety(Vector2f(sf::Mouse::getPosition(window)));
            cout <<"pos " << pos << endl;
            cout <<"pos0 " << (int)pos[0]-48 << "\npos 1" << (int)pos[1]-48 << endl;;
            if (squares.AbleToSelect((int)pos[0] - 48, (int)pos[1] - 48)) {
                cout << "lala" << endl;
                Celownik(squares, true, (int)pos[0] - 48, (int)pos[1] - 48);

            }
                
        }
    }
    Celownik(squares, false, my_t_x, my_t_y);
}



void SeaBattle::PlayTheGame(AllSquares& mySquares,AllSquares& enemySquares,Event& event, Window& window) {
    if (!statkiBotaUstawione) {
        enemyShipsCount = eShips.returnAmountToPlace();
        while (enemyShipsCount > 0) {
            enemy_tx = rand() % (10 - enemyShips[enemyShip_id].getRotationX());
            enemy_ty = rand() % (10 - enemyShips[enemyShip_id].getRotationY());
            if (enemySquares.AbleToPlace(enemy_tx, enemy_ty, enemyShips[enemyShip_id].getRotationX(), enemyShips[enemyShip_id].getRotationY())) {
                enemyShips[enemyShip_id].UstawStatkiNaPlanszy(enemySquares, enemy_tx, enemy_ty, false, true);
                eShips.UstawPozycje(enemyShip_id, enemy_tx, enemy_ty);
                enemyPozycje.insert(pair<int, vector<string>>(enemyShip_id, enemyShips[enemyShip_id].zwrocPozycje()));
                enemyShip_id++;
                enemyShipsCount--;
                if (enemyShipsCount == 0) {
                    statkiBotaUstawione = true;
                    enemySquares.setInvisible();
                }
            }
            else {
                enemyShips[enemyShip_id].changeRotation();
                eShips.ZmienRotacje(enemyShip_id);
            }       
        }
    }
    srand(time(NULL));
    if (!AllPlaced)
        PoruszanieSiePoPlanszy(event, mySquares);
    else {
        if (!GameOver) {
            NamierzanieCelu(event, enemySquares,window);
            if (pierwszyRazTrafiony) {
                computer_t_x = rand() % 10;
                computer_t_y = rand() % 10;
            }
            NamierzanieCeluPrzezKomputer(mySquares);
        }
    }
}

bool SeaBattle::KoniecGry() {
    if (amountMyShips == 0 || amountEnemyShips == 0) {
        return true;
    }
    return false;
    
}

bool SeaBattle::ZwrocZwyciezce() {
    if (amountEnemyShips == 0)
        return true;
    if (amountMyShips == 0)
        return false;
   
}