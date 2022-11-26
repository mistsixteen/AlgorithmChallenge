//Backjoon Problem No.1316
//https://www.acmicpc.net/problem/1316
//Mist16, 2022-03-16

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	int testCases;

	cin >> testCases;
	int gStrNum = 0;

	for (int i = 0; i < testCases; i++)
	{
		cin >> input;
		bool isGroupString = true;
		int isUsed[26] = { 0, };
		char lastChar = ' ';

		for (char c : input)
		{
			if (c == lastChar)
				continue;
			else
			{
				if (isUsed[(int)c - (int)'a'] == 0)
				{
					isUsed[(int)c - (int)'a'] = 1;
					lastChar = c;
				}
				else
				{
					isGroupString = false;
					break;
				}
			}
		}

		if (isGroupString == true)
		{
			gStrNum++;
		}	
	}

	cout << gStrNum;

	return 0;
}