//Backjoon Problem No.10844
//https://www.acmicpc.net/problem/10844
//Mist16, 2022-04-30

#include <iostream>
using namespace std;

unsigned long long arr[100][10] = { 0, };

int main()
{
	int n;
	unsigned long long answer = 0;
	for (int i = 0; i <= 9; i++)
	{
		arr[0][i] = 1;
	}

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		arr[i][0] = arr[i - 1][1];
		arr[i][9] = arr[i - 1][8];
		for(int j = 1; j <= 8; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
			arr[i][j] = arr[i][j] % 1000000000;
		}
	}

	for (int i = 1; i <= 9; i++)
	{
		answer += arr[n - 1][i];
		answer = answer % 1000000000;
	}

	cout << answer;

	return 0;
}