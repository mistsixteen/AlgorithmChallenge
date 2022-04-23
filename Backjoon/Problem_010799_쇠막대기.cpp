//Backjoon Problem No.10799
//https://www.acmicpc.net/problem/10799
//Mist16, 2022-04-23

#include <iostream>

using namespace std;

int main()
{
	string str;
	char lastChar = ' ';
	int currentLevel = 0;
	int totalPiece = 0;

	cin >> str;

	for (char c : str)
	{
		if (c == '(')
		{
			currentLevel++;
		}
		else if (c == ')')
		{
			currentLevel--;
			if (lastChar == '(')
			{
				totalPiece += currentLevel;
			}
			else
				totalPiece++;
		}
		lastChar = c;
	}

	cout << totalPiece;

	return 0;
}