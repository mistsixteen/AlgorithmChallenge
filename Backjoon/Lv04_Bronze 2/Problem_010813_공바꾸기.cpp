//Backjoon Problem No.10813
//https://www.acmicpc.net/problem/10813
//Mist16, 2025-06-25

#include <iostream>

using namespace std;


int main()
{
	int arr[101];

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;
		if (a == b)
			continue;
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}

	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}