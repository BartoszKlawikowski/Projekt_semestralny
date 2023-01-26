#include "wyswietlanie_tekstu.h"

wyswietlanie_tekstu::wyswietlanie_tekstu()
{
	font.loadFromFile("minecraft_font.ttf");
	tekst.setFont(font);
	tekst.setCharacterSize(30);
	tekst.setFillColor(sf::Color::Black);
	position.x = 0;
	position.y = 0;
	tekst.setPosition(position);
}

void wyswietlanie_tekstu::ustaw_tekst(std::string argument)
{
	tekst.setString(argument);
}

sf::Text wyswietlanie_tekstu::getText()
{
	return tekst;
}

sf::Text wyswietlanie_tekstu::getPomoc()
{
	tekst.setCharacterSize(30);
	tekst.setFillColor(sf::Color::Red);
	position.x = 60;
	position.y = 60;
	tekst.setPosition(position);
	tekst.setString("               OPIS\n\n Manewruj samolotem, unikaj kolizji\n Ominita przeszkoda = 1 pkt\n\n            STEROWANIE\n\n         Menu:\n            W - gora\n            S - dol\n            E - wybierz\n         Gra:\n            A - lewo\n            D - prawo");
	return tekst;
}

