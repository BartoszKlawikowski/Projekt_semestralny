#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>


class gracz
{
private:
	sf::Sprite plane;
	sf::Vector2f position;
	sf::Texture plane_look;
	sf::Texture plane_left;
	sf::Texture plane_right;
	int punkty;
	float speed = 10;
public:
	gracz();
	sf::Sprite getShip();
	int return_punkty();
	void add_punkty(int zysk);
	void movement();
	void resetuj_punkty();
};

