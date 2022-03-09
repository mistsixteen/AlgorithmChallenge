﻿//Backjoon Problem No.2467
//https://www.acmicpc.net/problem/2467
//Mist16, 2022-03-09

#include <iostream>

using namespace std;

int main()
{
	int N;
	int liquids[100000] = { 0, };
	int idxA, idxB;
	int minValue = 2000000001;
	int answerA, answerB;
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> liquids[i];

	idxA = 0;
	idxB = N - 1;

	while (idxA != idxB)
	{
		int temp;
		temp = liquids[idxA] + liquids[idxB];
		if (temp > 0)
		{
			if (temp < minValue)
			{
				minValue = temp;
				answerA = liquids[idxA];
				answerB = liquids[idxB];
			}
			idxB--;
		}
		else if (temp < 0)
		{
			temp = temp * -1;
			if (temp < minValue)
			{
				minValue = temp;
				answerA = liquids[idxA];
				answerB = liquids[idxB];
			}
			idxA++;
		}
		else
		{
			minValue = 0;
			answerA = liquids[idxA];
			answerB = liquids[idxB];
			break;
		}
	}

	cout << answerA << " " << answerB;

	return 0;
}