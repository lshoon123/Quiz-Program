#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <functional>
#include <iterator>
#include <ctime>
#include "menu.h"
#include "quiz.h"
#include "result.h"
#include "readerboard.h"
#pragma warning(disable:4996)


using namespace std;

#define WindowX 800
#define WindowY 600

bool rett(readerboard &lhs, readerboard &rhs)
{
	int a = lhs.getdate();
	int b = rhs.getdate();
	return a > b; 
}



int main()
{
	//check
	int check = 3, questionNumber = 0, score = 0, vectorsize =0;
	//open to read question text and write result
	ifstream file;
	file.open("question.txt");
	fstream fout("readboard.txt", ios::in | ios::out | ios::app);
	


	//create Window
	sf::RenderWindow window(sf::VideoMode(WindowX, WindowY), "Quiz program");

	//create menu
	menu Menu(WindowX, WindowY);
	//create Quiz
	quiz Quiz[10];
	//create result
	result Result(WindowX, WindowY);

	string sentence; // quiz question
	//open readboard
	

	//to make random shuffle
	vector <int> shuffle(10);

	int score1;
	string sco;
	string date;
	sf::Font font;
	sf::Text readboard;
	vector <readerboard> rank;
	

	for (int i = 0; i < 10; i++)
	{
		shuffle[i] = i;
	}
	random_shuffle(shuffle.begin(), shuffle.end());
	
	//setting question from text
	for (int i = 0; i < 10; i++)
	{
		getline(file, sentence);
		Quiz[shuffle[i]].setQuestion(sentence, WindowX, WindowY);
		for (int j = 0; j < 3; j++)
		{
			getline(file, sentence);
			Quiz[shuffle[i]].setExample(j, sentence, WindowX, WindowY);
		}
		getline(file, sentence);
		int a = atoi(sentence.c_str());
		Quiz[shuffle[i]].setAnswer(a);
	}
	
	
	vector <quiz> question;
	for (int i = 0; i < 10; i++)
	{
		question.push_back(Quiz[i]);
	}

	

	while (window.isOpen())
	{
		sf::Event event;
			// clear the screen and draw all the shapes
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					if (check ==3)
					{
						Menu.moveup();
					}
					if (check == 0)
					{
						question[questionNumber].moveup();
					}
					break;
				case sf::Keyboard::Down:
					if (check == 3)
					{
						Menu.movedown();
					}
					if (check == 0)
					{
						question[questionNumber].movedown();
					}
					break;
				case sf::Keyboard::Return:
					if (check == 3)
					{
						switch (Menu.GetPressedItem())
						{
						case 0:
							check = 0;
							break;
						case 1:
							check = 1;
							//create readerboard
							while (!fout.fail())
							{
								getline(fout, sco);
								score1 = atoi(sco.c_str());
								getline(fout, sco);
								cout << score1 << endl;
								cout << sco << endl;
								rank.push_back(readerboard(score1, sco));
							}

							//sort(rank.begin(), rank.end());
							sort(rank.begin(), rank.end(), rett);

							if (!font.loadFromFile("arial.ttf"))
							{
								//handle error
							}
							readboard.setFont(font);
							readboard.setFillColor(sf::Color::White);
							readboard.setPosition(sf::Vector2f(10, 10));
							readboard.setString("");
							for (int i = 0; i < 5; i++)
							{
								if (rank.size() <= i)
								{
									break;
								}
								readboard.setString(readboard.getString() + "\n" + rank[i].readprint());

							}
							break;
						case 2:
							window.close();
							break;
						}
					}
					else if (check ==0)
					{
						//check the Answer
						int a = question[questionNumber].getPressItem();
						if (question[questionNumber].returnAnswer() == a)
						{
							cout<< "collect" <<endl;
							score += 10;
						}
						questionNumber++;
						if (questionNumber >= 10)
						{
							check = 4;
							Result.setting(score, WindowX, WindowY);
						}
						break;
					}
					else if (check == 4)
					{
						time_t ltime;
						struct tm *today;
						time(&ltime);
						today = localtime(&ltime);
						string date = asctime(today);
						fout << score<<endl;
						fout << date;
						switch (Result.getPressItem())
						{
						case 0:
							score = 0;
							check = 0;
							questionNumber = 0;
							random_shuffle(shuffle.begin(), shuffle.end());
							for (int i = 0; i < 10; i++)
							{
								question[i] = Quiz[shuffle[i]];
							}
							break;
						case 1:
							check = 1;
							while (1)
							{

								getline(fout, sco);
								score1 = atoi(sco.c_str());
								getline(fout, sco);
								cout << score1 << endl;
								cout << sco << endl;
								if (fout.fail())
								{
									break;
								}
								rank.push_back(readerboard(score1, sco));
							}

							//sort(rank.begin(), rank.end());



							if (!font.loadFromFile("arial.ttf"))
							{
								//handle error
							}
							readboard.setFont(font);
							readboard.setFillColor(sf::Color::White);
							readboard.setPosition(sf::Vector2f(10, 10));
							readboard.setString("");
							for (int i = 0; i < 5; i++)
							{
								if (rank.size() <= i)
								{
									break;
								}
								readboard.setString(readboard.getString() + "\n" + rank[i].readprint());
							}
							break;
						case 2:
							window.close();
							break;
						}
					}
					break;
				case sf::Keyboard::Left:
					if (check == 4)
					{
						Result.moveleft();
					}
					break;
				case sf::Keyboard::Right:
					if (check == 4)
					{
						Result.moveright();
					}
					break;
				case sf::Keyboard::Num1:
					check = 3;
					questionNumber = 0;
				}
				break;
			
			case sf::Event::Closed:
					window.close();

					break;
			}
		}
			window.clear();
			if (check == 3)
			{
				Menu.draw(window);
			}
			else if (check == 0)
			{
				question[questionNumber].draw(window);
			}
			else if (check == 1)
			{
					window.draw(readboard);
			}
			else if (check == 4)
			{
				Result.draw(window);
			}
			

			window.display();

	}
}
