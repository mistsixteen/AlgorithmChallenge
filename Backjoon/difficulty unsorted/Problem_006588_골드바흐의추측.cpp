//Backjoon Problem No.6588﻿
//https://www.acmicpc.net/problem/6588
//Mist16, 2022-05-02

#include <iostream>

using namespace std;

bool flag[1000001] = { 0, };
int prime[1000001] = { 0, };

int main()
{
	int primeIdx = 0;
	int count = 1;
	int input;
	int answer = 0;

	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	flag[0] = true;
	flag[1] = true;

	for (int i = 2; i < 1000001; i++)
	{
		if (flag[i] == false)
		{
			int idx = i + i;
			prime[primeIdx] = i;
			primeIdx++;
			while (idx < 1000001)
			{
				flag[idx] = true;
				idx += i;
			}
		}
	}


	while(true)
	{
		answer = 0;

		cin >> input;

		if (input == 0)
			break;

		for (int j = 0; j < primeIdx; j++)
		{
			if (prime[j] * 2 > input)
				break;
			if (flag[input - prime[j]] == false)
			{
				answer = prime[j];
				break;
			}
		}
		if (answer != 0)
			cout << input << " = " << answer << " + " << input - answer << "\n";
		else
			cout << "Goldbach's conjecture is wrong.\n";
	}
	return 0;
}