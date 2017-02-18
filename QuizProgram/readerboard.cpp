#include "readerboard.h"
#include <string>

using namespace std;

readerboard::readerboard(int score1, string date1)
{
	date = date1;
	score = score1;
	compare = score;
}
string readerboard::readprint()
{
	string strscore = to_string(score);
	return (strscore +"   "+ date );
}

int readerboard::getdate()
{
	return score;
}