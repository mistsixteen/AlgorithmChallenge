//Backjoon Problem No.1015
//https://www.acmicpc.net/problem/1015
//Mist16, 2025-06-23

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<int> sorted;


int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		arr.push_back(temp);
		sorted.push_back(temp);
	}

	sort(sorted.begin(), sorted.end());

	for (int i = 0; i < n; i++)
	{
		int target = arr[i];

		for (int j = 0; j < n; j++)
		{
			if (arr[i] == sorted[j])
			{
				cout << j << " ";
				sorted[j] = -1;
				break;
			}
		}
	}

	return 0;
}