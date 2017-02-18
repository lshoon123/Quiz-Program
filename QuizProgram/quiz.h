#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>

using namespace std;

class quiz
{
public:
	quiz();
	void setQuestion(string question, float windowX, float windowY);
	void setExample(int i, string question, float windowX, float windowY);
	void setAnswer(int answer);
	void draw(sf::RenderWindow &window);
	void movedown();
	void moveup();	
	int getPressItem() { return selecteditem;  };
	int returnAnswer() { return answer; };


	
private:
	int selecteditem;
	sf::Font font;
	sf::Text question;
	sf::Text example[3];
	int answer;
};