//Backjoon Problem No.2581
//https://www.acmicpc.net/problem/2581
//Mist16, 2022-04-14

#include <iostream>

using namespace std;

int main()
{
	int M, N;
	unsigned int total = 0;
	int min = 0;
	cin >> M >> N;

	bool Flag[10001] = { 0, };

	Flag[0] = true;
	Flag[1] = true;

	for (int i = 2; i < N; i++)
	{
		if (Flag[i] == false)
		{
			int idx = i + i;
			while (idx <= N)
			{
				Flag[idx] = true;
				idx += i;
			}
		}
	}

	for (int i = M; i <= N; i++)
	{
		if (Flag[i] == false)
		{
			if (min == 0)
				min = i;
			total += i;
		}
	}
	if (min == 0)
		cout << -1;
	else
		cout << total << endl << min;


	return 0;
}