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
		// vector1�� ��� �������� �������� �ڼ��´�.
		random_shuffle(vector1.begin(), vector1.end());

		// vector1�� ������ ���
		copy(vector1.begin(), vector1.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	return 0;
}

[��ó] [STL] random_shuffle(���� ����) | �ۼ��� hextrial