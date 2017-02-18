#include "quiz.h"

quiz::quiz() // setting the color
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//handle error
	}
	question.setFont(font);
	question.setFillColor(sf::Color::White);
	for (int i = 0; i < 3; i++)
	{
		example[i].setFont(font);
		if (i != 0)
		{
			example[i].setFillColor(sf::Color::White);
		}
		else
		{
			example[i].setFillColor(sf::Color::Red);
		}
		
	}
	selecteditem = 0;
}

void quiz::setQuestion(string Question, float windowX, float windowY)
{
	question.setString(Question);
	question.setCharacterSize(18);
	question.setPosition(sf::Vector2f(10, windowY/10));
}

void quiz::setExample(int i, string Example, float windowX, float windowY)
{
	example[i].setString(Example);
	example[i].setPosition(sf::Vector2f(windowX/8, (windowY/5)*(i+1)));
}

void quiz::setAnswer(int a)
{
	answer = a;
}

void quiz::draw(sf::RenderWindow &window)
{
	window.draw(question);
	for (int i = 0; i < 3; i++)
	{
		window.draw(example[i]);
	}
}

void quiz::moveup()
{
	if (selecteditem -1 >=0)
	{
		example[selecteditem].setFillColor(sf::Color::White);
		selecteditem--;
		example[selecteditem].setFillColor(sf::Color::Red);
	}
}

void quiz::movedown()
{
	if (selecteditem + 1 < 3)
	{
		example[selecteditem].setFillColor(sf::Color::White);
		selecteditem++;
		example[selecteditem].setFillColor(sf::Color::Red);
	}
}