#pragma once
#include "SFML/Graphics.hpp"

#define MaxNumberItem 3

class menu
{
public:
	menu(float windowX, float windowY);

	void draw(sf::RenderWindow &window);
	void moveup();
	void movedown();
	int GetPressedItem() { return selectedItem; }

private:
	int selectedItem;
	sf::Font font;
	sf::Text Menu[MaxNumberItem];
};