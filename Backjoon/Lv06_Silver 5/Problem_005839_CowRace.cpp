//Backjoon Problem No.5839
//https://www.acmicpc.net/problem/5839
//Mist16, 2025-06-20

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	int answer = 0;

	int idxA = 0;
	int idxB = 0;

	int aPos = 0;
	int bPos = 0;
	int position = 0;

	int timeA[1001], timeB[1001];
	int speedA[1001], speedB[1001];

	cin >> a >> b;

	for (int i = 0; i < a; i++)
	{
		cin >> speedA[i] >> timeA[i];
	}

	for (int j = 0; j < b; j++)
	{
		cin >> speedB[j] >> timeB[j];
	}

	while (idxA < a && idxB < b)
	{
		int rTime = 0;

		if (timeA[idxA] > timeB[idxB])
		{
			rTime = timeB[idxB];
		}
		else
		{
			rTime = timeA[idxA];
		}

		aPos += rTime * speedA[idxA];
		timeA[idxA] -= rTime;

		if (timeA[idxA] <= 0)
		{
			idxA++;
		}

		bPos += rTime * speedB[idxB];
		timeB[idxB] -= rTime;

		if (timeB[idxB] <= 0)
		{
			idxB++;
		}

		if (aPos > bPos && position != 1)
		{
			if (position != 0)
			{
				answer++;
			}
			
			position = 1;
		}
		else if (aPos < bPos && position != -1)
		{
			if (position != 0)
			{
				answer++;
			}
			position = -1;
		}

	}

	cout << answer;

	return 0;
}