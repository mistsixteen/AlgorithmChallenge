//Backjoon Problem No.1016
//https://www.acmicpc.net/problem/1016
//Mist16, 2022-04-19

#include <iostream>
#include <math.h>

using namespace std;
int doubleArray[1000001] = { 0, };
int main()
{
	unsigned long long min;
	unsigned long long max;
	unsigned long long idx = 2;
	unsigned long long didx;
	unsigned long long gap = 0;
	int count = 0;
	cin >> min >> max;
	gap = max - min;
	didx = idx * idx;

	while (didx <= max)
	{
		unsigned long long current;

		if (didx >= min)
			current = didx;
		else
		{
			unsigned long long temp = min / (idx * idx);
			current = temp * didx;
		}

		while (current <= max)
		{
			if (current >= min)
				doubleArray[current - min] = 1;
			current += didx;
		}

		idx++;
		didx = idx * idx;
	}

	for (int i = 0; i <= gap; i++)
	{
		if (doubleArray[i] == 0)
		{
			count++;
		}
	}
	cout << count;

	return 0;
}