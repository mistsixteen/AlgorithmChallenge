//Backjoon Problem No.28015
//https://www.acmicpc.net/problem/28015
//Mist16, 2025-06-17

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int arr[100];
int N, M;


int result = 0;

void run()
{
	for (int i = 0; i < M; i++)
	{
		cin >> arr[i];
	}

	for (int sIdx = 0; sIdx < M; sIdx++)
	{
		if (arr[sIdx] != 0)
		{
			result++;
			int tValue = arr[sIdx];
			
			sIdx++;

			for (sIdx; sIdx < M; sIdx++)
			{
				if (arr[sIdx] == 0)
				{
					break;
				}
				else if (arr[sIdx - 1] == tValue && arr[sIdx] != tValue)
				{
					result++;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		run();
	}

	cout << result;
	return 0;
}