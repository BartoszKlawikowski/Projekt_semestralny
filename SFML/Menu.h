#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class Menu
{
private:
	int item_index;
	sf::Font font;
	sf::Text menu[5];
public:
	Menu(float width, float height);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void zmien_tekst(std::string nowy_tekst, int index);
	int pressed_item();
	std::string zwroc_tekst(int index);

};

