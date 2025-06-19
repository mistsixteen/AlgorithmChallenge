//Backjoon Problem No.6005
//https://www.acmicpc.net/problem/6005
//Mist16, 2025-06-19

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[25][25];
	int N, temp;;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			cin >> temp;
			arr[i][j] = temp;
		}
	}

	for (int i = N-1; i > 0; i--)
	{
		for (int j = 0; j < i+1; j++)
		{
			if (arr[i][j] > arr[i][j + 1])
			{
				arr[i - 1][j] += arr[i][j];
			}
			else
			{
				arr[i - 1][j] += arr[i][j + 1];
			}
		}
	}

	cout << arr[0][0];

	return 0;
}