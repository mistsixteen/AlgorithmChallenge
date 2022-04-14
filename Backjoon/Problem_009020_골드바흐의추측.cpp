//Backjoon Problem No.9020﻿
//https://www.acmicpc.net/problem/9020
//Mist16, 2022-04-14

#include <iostream>

using namespace std;

int main()
{
	int primeIdx = 0;
	int count = 1;
	int testCases = 0;

	bool flag[10001] = { 0, };
	int prime[10001] = { 0, };

	cin >> testCases;
	flag[0] = true;
	flag[1] = true;

	for (int i = 2; i < 10001; i++)
	{
		if (flag[i] == false)
		{
			int idx = i + i;
			prime[primeIdx] = i;
			primeIdx++;
			while (idx < 10001)
			{
				flag[idx] = true;
				idx += i;
			}
		}
	}

	for (int i = 0; i < testCases; i++)
	{
		int input;
		int minGap, newGap;
		int answer;
		cin >> input;
		minGap = input;
		for (int j = 0; j < primeIdx; j++)
		{
			if (prime[j] * 2 > input)
				break;
			if (flag[input - prime[j]] == true)
				continue;
			newGap = input - (2 * prime[j]);
			if (minGap > newGap)
			{
				minGap = newGap;
				answer = prime[j];
			}
		}
		cout << answer << " " << input - answer << "\n";
	}
	return 0;
}