//Backjoon Problem No.18268
//https://www.acmicpc.net/problem/18268
//Mist16, 2025-06-18

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int sessions[20][20];

int k, n;

void Input()
{
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> sessions[i][j];
		}
	}
}

bool IsConsistent(int x, int y)
{
	for (int i = 0; i < k; i++)
	{
		int xPos = -1;
		int yPos = -1;

		for (int j = 0; j < n; j++)
		{
			if (sessions[i][j] == x)
			{
				xPos = j;
			}
			if (sessions[i][j] == y)
			{
				yPos = j;
			}
		}

		if (xPos <= yPos)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int result = 0;
	cin >> k >> n;

	Input();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}

			if (IsConsistent(i+1, j+1))
			{
				result++;
			}
		}
	}

	cout << result;

	return 0;
}