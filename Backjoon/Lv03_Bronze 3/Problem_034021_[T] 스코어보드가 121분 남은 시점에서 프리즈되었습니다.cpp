//Backjoon Problem No.34021
//https://www.acmicpc.net/problem/34021
//Mist16, 2025-06-15

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

void run()
{
	int N, M, L;

	cin >> N >> M >> L;

	int leftTime = L;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		if (temp != -1 && M - temp > leftTime)
		{
			leftTime = M - temp;
		}
	}

	if (leftTime == 1)
	{
		cout << "The scoreboard has been frozen with 1 minute remaining." << endl;
	}
	else
	{
		cout << "The scoreboard has been frozen with " << leftTime << " minutes remaining." << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		run();
	}

	return 0;
}