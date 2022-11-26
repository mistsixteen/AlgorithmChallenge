/*
* ﻿Backjoon Problem No.1992
* https://www.acmicpc.net/problem/1992
* Mist16, 2022-04-12
*/
#include <iostream>

using namespace std;

int pArray[64][64] = { 0, };
int N;

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
		if (startingPos == 0)
		{
			cout << "0";
		}
		else
		{
			cout << "1";
		}
	}
	else
	{
		int nextL = L / 2;
		cout << "(";
		run(xS, yS, nextL);
		run(xS + nextL, yS, nextL);
		run(xS, yS + nextL, nextL);
		run(xS + nextL, yS + nextL, nextL);
		cout << ")";
	}

}

int main()
{
	char temp;

	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			if (temp == '1')
				pArray[i][j] = 1;
			else
				pArray[i][j] = 0;
		}
	}
		
	run(0, 0, N);
	return 0;
}