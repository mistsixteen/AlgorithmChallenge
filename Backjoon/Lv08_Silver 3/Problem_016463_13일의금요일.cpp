//Backjoon Problem No.16463
//https://www.acmicpc.net/problem/16463
//Mist16, 2025-06-15

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

bool IsLeapYear(int year)
{
	if (year % 400 == 0)
	{
		return true;
	}

	if (year % 100 == 0)
	{
		return false;
	}

	if (year % 4 == 0)
	{
		return true;
	}

	return false;
}

int NextDay(int cYear, int cMonth)
{
	const int mDay[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (cMonth == 2)
	{
		if (IsLeapYear(cYear))
		{
			return mDay[1]+1;
		}
		else
		{
			return mDay[1];
		}
	}
	else
	{
		return mDay[cMonth - 1];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	int cDay = 0;

	int answer = 0;

	cin >> N;

	for (int i = 2019; i <= N; i++)
	{
		for (int j = 1; j <= 12; j++)
		{
			if (cDay == 5)
			{
				answer++;
			}

			cDay += NextDay(i, j);
			cDay %= 7;
		}
	}

	cout << answer;

	return 0;
}