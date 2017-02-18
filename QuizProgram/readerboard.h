#pragma once
#include "SFML/Graphics.hpp"
#include <string>

using namespace std;

class readerboard
{
public:
	int compare;
	readerboard(int score, string date);
	string readprint();
	int getdate();
private:
	string date;
	int score;
};