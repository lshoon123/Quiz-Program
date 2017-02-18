#include "menu.h"

menu::menu(float windowX, float windowY)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//handle error
	}

	Menu[0].setFont(font);
	Menu[0].setFillColor(sf::Color::Red);
	Menu[0].setString("Play");
	Menu[0].setPosition(sf::Vector2f(windowX / 2, windowY/4));

	Menu[1].setFont(font);
	Menu[1].setFillColor(sf::Color::White);
	Menu[1].setString("High Score");
	Menu[1].setPosition(sf::Vector2f(windowX / 2, (windowY / 4) * 2));

	Menu[2].setFont(font);
	Menu[2].setFillColor(sf::Color::White);
	Menu[2].setString("Exit");
	Menu[2].setPosition(sf::Vector2f(windowX / 2, (windowY / 4) * 3));

	selectedItem = 0;
}

void menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i< MaxNumberItem; i++)
	{
		window.draw(Menu[i]);
	}
}

void menu::moveup()
{
	if (selectedItem -1 >= 0)
	{
		Menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		Menu[selectedItem].setFillColor(sf::Color::Red);
	}
}

void menu::movedown()
{
	if (selectedItem + 1 < MaxNumberItem)
	{
		Menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		Menu[selectedItem].setFillColor(sf::Color::Red);
	}
}