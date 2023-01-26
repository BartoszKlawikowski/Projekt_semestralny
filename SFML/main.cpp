#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <time.h>
#include <random>//
#include "gracz.h"
#include "background1.h"
#include "obiekty.h"
#include "wyswietlanie_tekstu.h"
#include "Menu.h"
#include "dane.h"
#include "zapis.h"

int main() 
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(800, 800), "Aviation_Game");
    window.setFramerateLimit(60);

    sf::Music music;
    music.openFromFile("theme.wav"); 
    music.setLoop(true);
    music.setVolume(4);
    music.play();

    gracz gracz;
    background1 tlo;
    obiekty tab_stone[5];
    wyswietlanie_tekstu punkty;
    wyswietlanie_tekstu game_over;
    wyswietlanie_tekstu pomoc;
    Menu menu(window.getSize().x, window.getSize().y);
    dane dane_gracza;
    zapis zapisanie_danych;

    enum stany{gra=0, pauza=1, spis=2};
    enum trudnosci{latwy=1, trudny=0};

    std::string poziom;
    int stan_gry = 1;
    int liczba_enemy = 4;
    bool koniec_gry = false;
    bool gra_zaczeta = false;
    bool stan_przed = false;
    bool poziom_trudnosci = latwy;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape && stan_gry == gra)
                {
                    stan_gry = pauza;
                }
                else if (event.key.code == sf::Keyboard::Escape && stan_gry == pauza && gra_zaczeta == true)
                {
                    stan_gry = gra;
                }
                else if (event.key.code == sf::Keyboard::F1 && stan_gry == spis && stan_przed == false)
                {
                    stan_gry = pauza;
                }
                else if (event.key.code == sf::Keyboard::F1 && stan_gry == spis && stan_przed == true)
                {
                    stan_gry = gra;
                }
                else if (event.key.code == sf::Keyboard::F1)
                {
                    stan_gry = spis;
                }
                else if (event.key.code == sf::Keyboard::W && stan_gry == pauza)
                {
                    menu.MoveUp();
                }
                else if (event.key.code == sf::Keyboard::S && stan_gry == pauza)
                {
                    menu.MoveDown();
                }
                else if (event.key.code == sf::Keyboard::E && stan_gry == pauza)
                {
                    if (menu.pressed_item() == 0)
                    {
                        gra_zaczeta = true;
                        koniec_gry = false;

                        if (poziom_trudnosci == trudny)
                        {
                            liczba_enemy = 5;
                            poziom = "\nHARD";
                        }
                        else
                        {
                            liczba_enemy = 4;
                            poziom = "\nEASY";
                        }
                        for (int i = 0; i < liczba_enemy; i++)
                        {
                            tab_stone[i].restart_gry();
                        }
                        gracz.resetuj_punkty();
                        stan_gry = gra;
                        punkty.ustaw_tekst("SCORE: " + std::to_string(0) + poziom);
                    }

                    else if (menu.pressed_item() == 1)
                    {
                        if (poziom_trudnosci == trudny)
                        {
                            poziom_trudnosci = latwy;
                        }
                        else
                        {
                            poziom_trudnosci = trudny;
                        }
                    }
                    else if (menu.pressed_item() == 2)
                    {
                        poziom_trudnosci = zapisanie_danych.odczytaj().poziom_trudnosci;
                        gracz.resetuj_punkty();
                        gracz.add_punkty(zapisanie_danych.odczytaj().punkty);

                        gra_zaczeta = true;
                        koniec_gry = false;

                        if (poziom_trudnosci == trudny)
                        {
                            liczba_enemy = 5;
                            poziom = "\nHARD";
                        }
                        else
                        {
                            liczba_enemy = 4;
                            poziom = "\nEASY";
                        }
                        for (int i = 0; i < liczba_enemy; i++)
                        {
                            tab_stone[i].restart_gry();
                        }
                        stan_gry = gra;
                        punkty.ustaw_tekst("SCORE: " + std::to_string(gracz.return_punkty()) + poziom);
                    }
                    else if (menu.pressed_item() == 3)
                    {
                        dane_gracza.poziom_trudnosci = poziom_trudnosci;
                        dane_gracza.punkty = gracz.return_punkty();

                        zapisanie_danych.zapisz(dane_gracza);
                        
                        window.close();
                    }
                    else if (menu.pressed_item() == 4)
                    {
                        window.close();
                    }
                }
            }

        }

        switch (stan_gry)
        {
        case gra:
            window.clear();
            window.draw(tlo.get_tlo_gra());
            window.draw(gracz.getShip());
            gracz.movement();
            stan_przed = true; 

            for (int i = 0; i < liczba_enemy; i++)
            {
                window.draw(tab_stone[i].getStone());
                tab_stone[i].movement();
                if (tab_stone[i].restart_stone())
                {
                    gracz.add_punkty(1);
                    punkty.ustaw_tekst("SCORE: " + std::to_string(gracz.return_punkty()) + poziom);
                }

                if (gracz.getShip().getGlobalBounds().intersects(tab_stone[i].getStone().getGlobalBounds()))
                {
                    for (int i = 0; i < 4; i++)
                    {
                        tab_stone[i].restart_gry();
                    }
                    gra_zaczeta = false;
                    koniec_gry = true;
                    stan_gry = pauza;
                    game_over.ustaw_tekst("GAME OVER \nFINAL SCORE: " + std::to_string(gracz.return_punkty()) + poziom);

                    gracz.resetuj_punkty();
                }
            }
            window.draw(punkty.getText());

            window.display();
            break;
        case pauza:
            window.clear(sf::Color::Blue);
            window.draw(tlo.get_tlo_menu());

            stan_przed = false; 
            if (koniec_gry)
            {
                window.draw(game_over.getText());
            }

            if (poziom_trudnosci == trudny)
            {
                menu.zmien_tekst("DIFFICULTY: HARD", 1);
            }
            else
            {
                menu.zmien_tekst("DIFFICULTY: EASY", 1);
            }
            menu.draw(window);
            window.display();
            break;
        case spis:
            window.clear(sf::Color::Blue);
            window.draw(tlo.get_tlo_menu());
            window.draw(pomoc.getPomoc());
            window.display();
            break;
        }

    }
}


