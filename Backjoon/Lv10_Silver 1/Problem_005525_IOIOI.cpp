//Backjoon Problem No.5525
//https://www.acmicpc.net/problem/5525
//Mist16, 2022-04-05

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, M;
	int count = 0;
	string input;
	int currentCount = 0;
	cin >> N >> M >> input;

	N = (2 * N) + 1;

	if (input[0] == 'I')
		currentCount = 1;
	for (int i = 1; i < M; i++)
	{
		if (input[i] == 'I')
		{
			if (input[i - 1] == 'O')
			{
				currentCount++;
				if (currentCount >= N)
					count++;
			}
			else
			{
				currentCount = 1;
			}
		}
		else if (input[i] == 'O')
		{
			if (input[i - 1] == 'I')
			{
				currentCount++;
			}
			else
			{
				currentCount = 0;
			}
		}
	}
	cout << count;

	return 0;
}