//Backjoon Problem No.2559
//https://www.acmicpc.net/problem/2559
//Mist16, 2022-04-17

#include <iostream>

using namespace std;

int main()
{
	int N, M, temp;
	int totalArray[100001] = { 0, };
	int maxValue = -10000001;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		totalArray[i] = totalArray[i - 1] + temp;
	}

	for (int i = M; i <= N; i++)
	{
		temp = totalArray[i] - totalArray[i - M];
		if (temp > maxValue)
			maxValue = temp;
	}

	cout << maxValue;

	return 0;
}