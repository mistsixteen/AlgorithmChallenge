//Backjoon Problem No.2342
//https://www.acmicpc.net/problem/2342
//Mist16, 2022-01-28
//풀이 실패, 추후 재도전

#include <iostream>

using namespace std;


int rgbLength[100001][5][5] = { 0, };
int moveMentPower[5][5] = { {1, 2, 2, 2, 2}, {2, 1, 3, 4, 3}, {2, 3, 1, 3, 4}, {2, 4, 3, 1, 3}, {2, 3, 4, 3, 1} };
int orderSet[100001] = { 0, };
int N = 0;

int main()
{
	int temp;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 100000; i++)
	{
		orderSet[i] = 0;
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				rgbLength[i][j][k] = 0;
			}
		}
	}

	N = 0;
	while (1)
	{
		cin >> orderSet[N];
		if (orderSet[N] == 0)
			break;
		N++;
	}

	if (N == 0)
	{
		cout << 0;
		return 0;
	}

	rgbLength[0][0][orderSet[0]] = 2;

	for (int turn = 0; turn < N - 1; turn++)
	{
		int order = orderSet[turn + 1];
		if (order == 0)
			break;
		for (int i = 0; i < 4; i++)
		{
			for (int j = i+1; j < 5; j++)
			{
				if (rgbLength[turn][i][j] != 0)
				{
					if (order == i || order == j)
					{
						rgbLength[turn + 1][i][j] = rgbLength[turn][i][j] + 1;
					}
					else
					{
						//left
						if (order < j)
						{
							temp = rgbLength[turn][i][j] + moveMentPower[order][i];
							if (rgbLength[turn + 1][order][j] == 0 || rgbLength[turn + 1][order][j] > temp)
								rgbLength[turn + 1][order][j] = temp;
						}
						else
						{
							temp = rgbLength[turn][i][j] + moveMentPower[order][i];
							if (rgbLength[turn + 1][j][order] == 0 || rgbLength[turn + 1][j][order] > temp)
								rgbLength[turn + 1][j][order] = temp;
						}

						//right
						if (order < i)
						{
							temp = rgbLength[turn][i][j] + moveMentPower[order][j];
							if (rgbLength[turn + 1][order][i] == 0 || rgbLength[turn + 1][order][i] > temp)
								rgbLength[turn + 1][order][i] = temp;
						}
						else
						{
							temp = rgbLength[turn][i][j] + moveMentPower[order][j];
							if (rgbLength[turn + 1][i][order] == 0 || rgbLength[turn + 1][i][order] > temp)
								rgbLength[turn + 1][i][order] = temp;
						}
					}

				}
			}
		}
	}

	int min = 9000000;

	for (int i = 0; i < 4; i++)
	{
		for (int j = i+1; j < 5; j++)
		{
			temp = rgbLength[N - 1][i][j];
			if (temp != 0 && min > temp)
				min = temp;
		}
	}

	cout << min;

	return 0;

}