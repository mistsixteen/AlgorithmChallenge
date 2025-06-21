//Backjoon Problem No.13217
//https://www.acmicpc.net/problem/13217
//Mist16, 2025-06-21

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, k, m;

	long long totalAmount = 0;
	long long maxedPot = 0;

	int* arr = new int[500000] {0, };

	cin >> n >> m >> k;

	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp >= m)
		{
			int potSize = (int)(temp / m);
			int left = temp % m;
			maxedPot += potSize;
			arr[left]++;
		}
		else
		{
			arr[temp]++;
		}
	}

	//Set MaxedPot;
	if (maxedPot >= k)
	{
		totalAmount = m * k;
		cout << totalAmount;
		return 0;
	}
	else
	{
		totalAmount = m * maxedPot;
		k -= maxedPot;
	}

	//check leftOver
	for (int i = m; i > 0; i--)
	{
		if (arr[i] <= 0)
		{
			continue;
		}

		if (arr[i] >= k)
		{
			totalAmount += i * k;
			break;
		}

		totalAmount += arr[i] * i;
		k -= arr[i];
	}

	cout << totalAmount;

	return 0;
}