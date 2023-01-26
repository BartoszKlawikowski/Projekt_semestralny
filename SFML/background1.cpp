#include "background1.h"

background1::background1()
{
    back_tekstura_menu.loadFromFile("tlo_menu.png");
    back_tekstura_gra.loadFromFile("tlo_gra.png");
    background_sprite_menu.setTexture(back_tekstura_menu);
    background_sprite_gra.setTexture(back_tekstura_gra);
    background_sprite_gra.setPosition(0, 0);
    background_sprite_menu.setPosition(0, 0);
}

sf::Sprite background1::get_tlo_gra()
{
    return background_sprite_gra;
}

sf::Sprite background1::get_tlo_menu()
{
    return background_sprite_menu;
}
