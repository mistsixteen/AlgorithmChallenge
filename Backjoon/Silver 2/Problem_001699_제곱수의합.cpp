//Backjoon Problem No.1699
//https://www.acmicpc.net/problem/1699
//Mist16, 2022-04-23


#include <iostream>

using namespace std;

static const int MAX_IDX = 320;
int arr[321] = { 0, };

int min_count = 9999999;

void run(int cIdx, int cCount, int Left)
{
	if (cCount >= min_count || cIdx <= 0)
		return;
	if (Left == arr[cIdx])
	{
		if (min_count > cCount + 1)
			min_count = cCount + 1;
		return;
	}
	else if (Left > arr[cIdx])
	{
		run(cIdx, cCount + 1, Left - arr[cIdx]);
	}
	run(cIdx - 1, cCount, Left);
}

int main()
{
	int N = 0, idx = 0;
	cin >> N;

	for (int i = 0; i < 321; i++)
	{
		arr[i] = i * i;
	}
	run(MAX_IDX, 0, N);

	cout << min_count;

	return 0;
}