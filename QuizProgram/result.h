#pragma once
#include <string>
#include "SFML/Graphics.hpp"

using namespace std;

class result
{
public:
	result(float windowX, float windowY);
	void draw(sf::RenderWindow &window);
	void setting(int score, float windowX, float windowY);
	void moveleft();
	void moveright();
	int getPressItem() { return selecteditem; };

private:
	int selecteditem;
	sf::Font font;
	sf::Text player[2];
	sf::Text menu[3];
};