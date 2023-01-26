#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

struct obiekty
{
private:
	sf::Sprite stone;
	sf::Texture stone_look;
	sf::Vector2f position;
	float speed = 8;
public:
	obiekty();
	void movement();
	bool restart_stone();
	void restart_gry();
	sf::Sprite getStone();
};

