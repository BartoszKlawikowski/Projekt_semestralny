#include "Menu.h"

Menu::Menu(float width, float height)
{
	font.loadFromFile("minecraft_font.ttf");

	for (int i = 0; i < 5; i++)
	{
		menu[i].setFont(font);
		menu[i].setFillColor(sf::Color::Black);
		menu[i].setPosition(sf::Vector2f(30, 500 + (42 * i)));
	}

	menu[0].setFillColor(sf::Color::Magenta);
	menu[0].setString("PLAY");

	menu[1].setString("DIFFICULTY: ");

	menu[2].setString("LOAD");

	menu[3].setString("SAVE AND EXIT?");

	menu[4].setString("EXIT?");

	item_index = 0;
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 5; i++)
	{
		//std::cout << "test" << std::endl;
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (item_index - 1 >= 0)
	{
		menu[item_index].setFillColor(sf::Color::Black);
		item_index = item_index - 1;
		menu[item_index].setFillColor(sf::Color::Magenta);
	}
}

void Menu::MoveDown()
{
	if (item_index + 1 < 5)
	{
		menu[item_index].setFillColor(sf::Color::Black);
		item_index = item_index + 1;
		menu[item_index].setFillColor(sf::Color::Magenta);
	}
}

int Menu::pressed_item()
{
	return item_index;
}

void Menu::zmien_tekst(std::string nowy_tekst, int index)
{
	menu[index].setString(nowy_tekst);
}

std::string Menu::zwroc_tekst(int index)
{
	return menu[index].getString().toAnsiString();     //sfml string -> cpp string
}