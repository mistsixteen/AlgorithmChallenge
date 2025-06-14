#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int q;
	int arr[101] = { 0 };
	int inject[101] = { 0, };

	cin >> n >> q;

	for (int i = 0; i < q; i++)
	{
		int input;
		cin >> input;

		if (input == 0)
		{
			int min = 999;
			int minPos = 0;
			for (int i = 1; i <= n; i++)
			{
				if (min > arr[i])
				{
					min = arr[i];
					minPos = i;
				}
			}
			arr[minPos]++;
			inject[i] = minPos;
		}
		else
		{
			arr[input]++;
			inject[i] = input;
		}
	}

	for (int i = 0; i < q; i++)
	{
		cout << inject[i] << " ";
	}

	return 0;
}