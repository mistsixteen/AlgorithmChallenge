//Backjoon Problem No.2468
//https://www.acmicpc.net/problem/2468
//Mist16, 2022-12-29

#include <iostream>

using namespace std;

int n;
int arr[100][100];
int island[100][100];
int hasThisLevel[101] = { 0, };

void checkIsland(int y, int x)
{
	if (y < 0 || y >= n || x < 0 || x >= n)
		return;
	if (arr[y][x] == 0)
		return;
	arr[y][x] = 0;

	checkIsland(y - 1, x);
	checkIsland(y + 1, x);
	checkIsland(y, x - 1);
	checkIsland(y, x + 1);
}

int run(int level)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (island[i][j] <= level)
				arr[i][j] = 0;
			else
				arr[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1) {
				count++;
				checkIsland(i, j);
			}
		}
	}
	return count;
}

int main()
{
	cin >> n;

	int maxLevel = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> island[i][j];
			hasThisLevel[island[i][j]] = 1;
		}
	}

	for (int i = 1; i < 101; i++)
	{
		if (hasThisLevel[i] == 1) {
			int result = run(i);
			if (result > maxLevel)
				maxLevel = result;
		}
	}

	cout << maxLevel;

	return 0;
}
