//Backjoon Problem No.6766
//https://www.acmicpc.net/problem/6766
//Mist16, 2025-06-13

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	string str;

	cin >> k;

	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		int value = (int)str[i];

		int shift = (3 * (i+1)) + k;
		shift %= 26;

		value -= shift;

		if (value < 65)
		{
			value += 26;
		}

		cout << (char)(value);
	}

	return 0;
}