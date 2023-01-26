#include "obiekty.h"

obiekty::obiekty()
{
	position.x = rand()%700;
	position.y = -100 - rand()%600;
	stone_look.loadFromFile("gora.png");
	stone.setTexture(stone_look);
	stone.setPosition(position);
}

void obiekty::movement()
{
	position.y += speed;
	stone.setPosition(position);
}

bool obiekty::restart_stone()
{
	if (position.y > 900)
	{
		position.x = rand() % 700;
		position.y = -100 - rand() % 200;
		stone.setPosition(position);
		return true;
	}
	return false;
}

void obiekty::restart_gry()
{
	position.x = rand() % 700;
	position.y = -100 - rand() % 600;
	stone.setPosition(position);
}

sf::Sprite obiekty::getStone()
{
	return stone;
}