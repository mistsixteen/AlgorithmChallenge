//Backjoon Problem No.2003
//https://www.acmicpc.net/problem/2003
//Mist16, 2022-05-16

#include <iostream>

using namespace std;

int main()
{
	int arr[10000] = { 0, };
	int n, m;
	int current = 0, count = 0;
	int posA, posB;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	posA = 0;
	posB = 0;
	current = arr[posA];

	while (posB < n)
	{
		if (current == m)
		{
			count++;
			if (posA == posB)
			{
				posA++;
				posB++;
				current = arr[posA];
			}
			else
			{
				current -= arr[posA];
				posA++;
			}
		}
		else if (current > m)
		{
			if (posA == posB)
			{
				posA++;
				posB++;
				current = arr[posA];
			}
			else
			{
				current -= arr[posA];
				posA++;
			}
		}
		else
		{
			posB++;
			current += arr[posB];
		}
	}

	cout << count;

	return 0;
}