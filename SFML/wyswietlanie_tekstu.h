#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class wyswietlanie_tekstu
{
private:
	sf::Font font;
	sf::Vector2f position;
	sf::Text tekst;
public:
	wyswietlanie_tekstu();
	sf::Text getPomoc();
	sf::Text getText();
	void ustaw_tekst(std::string argument);
};

