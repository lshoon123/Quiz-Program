#pragma once
#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

vector<string> randomshuffle(10);
{
public:
	randomshuffle()
	for (int i = 0; i<N; ++i)
		vector1[i] = i;

	for (int j = 0; j<3; ++j)
	{
		// vector1에 담긴 정수들을 무작위로 뒤섞는다.
		random_shuffle(vector1.begin(), vector1.end());

		// vector1의 내용을 출력
		copy(vector1.begin(), vector1.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	return 0;
}

[출처] [STL] random_shuffle(랜덤 셔플) | 작성자 hextrial