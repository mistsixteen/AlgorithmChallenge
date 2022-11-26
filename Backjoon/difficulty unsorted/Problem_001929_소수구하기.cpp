//Backjoon Problem No.1929
//https://www.acmicpc.net/problem/1929
//Mist16, 2022-04-01

#include <iostream>

using namespace std;


int main()
{
	int M, N;

	cin >> M >> N;

	bool Flag[1000001] = { 0, };

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
			cout << i << "\n";
		}
	}

	return 0;
}