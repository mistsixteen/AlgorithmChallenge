/*
* ﻿Backjoon Problem No.1780
* https://www.acmicpc.net/problem/1780
* Mist16, 2022-04-11
*/
#include <iostream>

using namespace std;

int pArray[2200][2200] = { 0, };
int N;
int iCount[3] = { 0, };

void run(int xS, int yS, int L)
{
	int startingPos = pArray[yS][xS];
	bool isCorrect = true;

	for (int i = yS; i < yS + L; i++)
	{
		for (int j = xS; j < xS + L; j++)
		{
			if (pArray[i][j] != startingPos)
			{
				isCorrect = false;
				break;
			}
		}
		if (!isCorrect)
			break;
	}

	if (isCorrect)
	{
		iCount[startingPos + 1]++;
	}
	else
	{
		int nextL = L / 3;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				run(xS + (i * nextL), yS + (j * nextL), nextL);
			}
		}
	}
}

int main()
{
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> pArray[i][j];

	run(0, 0, N);

	for (int i = 0; i < 3; i++)
		cout << iCount[i] << "\n";

	return 0;
}