//Backjoon Problem No.28075
//https://www.acmicpc.net/problem/28075
//Mist16, 2025-06-07

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static int N = 0;
static int M = 0;

static int Point[2][3];


int run(int t, int lastPoint, int currentScore);

int main()
{
	unsigned long long s, e;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin >> Point[0][0] >> Point[0][1] >> Point[0][2];
	cin >> Point[1][0] >> Point[1][1] >> Point[1][2];

	cout << run(0, -1, 0);

	return 0;
}

int run(int t, int lastPoint, int currentScore)
{
	if (t >= N)
	{
		if (currentScore >= M)
			return 1;
		else
			return 0;
	}

	auto result = 0;

	if (lastPoint == 0)
	{
		result += run(t + 1, 0, currentScore + (Point[0][0] / 2));
		result += run(t + 1, 0, currentScore + (Point[1][0] / 2));
	}
	else
	{
		result += run(t + 1, 0, currentScore + (Point[0][0]));
		result += run(t + 1, 0, currentScore + (Point[1][0]));
	}

	if (lastPoint == 1)
	{
		result += run(t + 1, 1, currentScore + (Point[0][1] / 2));
		result += run(t + 1, 1, currentScore + (Point[1][1] / 2));
	}
	else
	{
		result += run(t + 1, 1, currentScore + (Point[0][1]));
		result += run(t + 1, 1, currentScore + (Point[1][1]));
	}

	if (lastPoint == 2)
	{
		result += run(t + 1, 2, currentScore + (Point[0][2] / 2));
		result += run(t + 1, 2, currentScore + (Point[1][2] / 2));
	}
	else
	{
		result += run(t + 1, 2, currentScore + (Point[0][2]));
		result += run(t + 1, 2, currentScore + (Point[1][2]));
	}

	return result;
}