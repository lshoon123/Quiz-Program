#include "result.h"

result::result(float windowX, float windowY)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//handle error
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play Again");
	menu[0].setPosition(sf::Vector2f(10, 2*windowY/3));
	
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("High Score");
	menu[1].setPosition(sf::Vector2f(windowX/3, 2 * windowY / 3));
	
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(2*windowX/3, 2 * windowY / 3));

	for (int i = 0; i < 2; i++)
	{
		player[i].setFont(font);
		player[i].setFillColor(sf::Color::White);
	}

	selecteditem = 0;
}

void result::setting(int score, float WindowX, float WindowY)
{
		player[0].setString("your score is ");
		player[0].setPosition(sf::Vector2f(WindowX / 8, WindowY / 8));
		string str = to_string(score);
		player[1].setString(str);
		player[1].setPosition(sf::Vector2f(5 * WindowX / 8, WindowY / 8));

}


void result::draw(sf::RenderWindow &window)
{
	
	for (int i = 0; i < 3; i++)
	{
		window.draw(player[i]);
		window.draw(menu[i]);
	}
}

void result::moveleft()
{
	if (selecteditem - 1 >= 0)
	{
		menu[selecteditem].setFillColor(sf::Color::White);
		selecteditem--;
		menu[selecteditem].setFillColor(sf::Color::Red);
	}
}

void result::moveright()
{
	if (selecteditem + 1 < 3)
	{
		menu[selecteditem].setFillColor(sf::Color::White);
		selecteditem++;
		menu[selecteditem].setFillColor(sf::Color::Red);
	}
}