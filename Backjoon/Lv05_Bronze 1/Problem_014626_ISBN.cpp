//Backjoon Problem No.14626
//https://www.acmicpc.net/problem/14626
//Mist16, 2025-06-08

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static int ISBN[13];
static int tPos = 0;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char* input = new char[14];

	cin >> input;

	for (int i = 0; i < 13; i++)
	{
		if (input[i] == '*')
		{
			tPos = i;
			ISBN[i] = 0;
		}
		else
		{
			ISBN[i] = (int)input[i] - 48;
		}
	}

	for (int i = 0; i <= 9; i++)
	{
		ISBN[tPos] = i;
		auto checkSum = 0;

		for (int i = 0; i < 13; i++)
		{
			if (i % 2 == 0)
			{
				checkSum += ISBN[i];
			}
			else
			{
				checkSum += (ISBN[i] * 3);
			}
		}

		if (checkSum % 10 == 0)
		{
			cout << i;
			break;
		}
	}

	return 0;
}