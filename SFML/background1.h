#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class background1
{
private:
    sf::Sprite background_sprite_menu;
    sf::Sprite background_sprite_gra;
    sf::Texture back_tekstura_menu;
    sf::Texture back_tekstura_gra;
public:
    background1();
    sf::Sprite get_tlo_gra();
    sf::Sprite get_tlo_menu();
};


