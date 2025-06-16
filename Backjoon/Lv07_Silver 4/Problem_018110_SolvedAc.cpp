//Backjoon Problem No.18110
//https://www.acmicpc.net/problem/18110
//Mist16, 2025-06-16

#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	int scores[31] = { 0, };


	cin >> N;

	if (N == 0)
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		scores[temp]++;
	}

	float del = (float)N * 15 / 100;
	int deli = roundf(del);

	int tempDel = deli;

	for (int i = 0; i <= 30; i++)
	{
		if (scores[i] == 0)
		{
			continue;
		}

		if (scores[i] >= tempDel)
		{
			scores[i] = scores[i] - tempDel;
			break;
		}

		tempDel = tempDel - scores[i];
		scores[i] = 0;
	}

	tempDel = deli;

	for (int i = 30; i > 0; i--)
	{
		if (scores[i] == 0)
		{
			continue;
		}

		if (scores[i] >= tempDel)
		{
			scores[i] = scores[i] - tempDel;
			break;
		}

		tempDel = tempDel - scores[i];
		scores[i] = 0;
	}

	int total = 0;

	for (int i = 0; i <= 30; i++)
	{
		total = total + (scores[i] * i);
	}

	N = N - deli - deli;

	double dTotal = (double)total / N;

	cout << round(dTotal);

	return 0;
}