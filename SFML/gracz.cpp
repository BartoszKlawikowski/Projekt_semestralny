#include "gracz.h"


gracz::gracz() 
{
	position.x = 450;
	position.y = 650;

	plane_look.loadFromFile("statek_gora.png");
	plane_left.loadFromFile("statek_lewo.png");
	plane_right.loadFromFile("statek_prawo.png");

	plane.setTexture(plane_look);
	plane.setPosition(position);
	punkty = 0;
}

void gracz::movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		plane.setTexture(plane_right);
		if (position.x <= 700)
		{
			position.x += speed;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		plane.setTexture(plane_left);
		if (position.x >= 0)
		{
			position.x -= speed;
		}
	}
	else
		plane.setTexture(plane_look);
	plane.setPosition(position);
}

void gracz::add_punkty(int zysk)
{
	punkty += zysk;
}

int gracz::return_punkty()
{
	return punkty;
}

void gracz::resetuj_punkty()
{
	punkty = 0;
}

sf::Sprite gracz::getShip()
{
	return plane;
}