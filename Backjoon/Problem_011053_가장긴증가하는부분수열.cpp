//Backjoon Problem No.11053
//https://www.acmicpc.net/problem/11053
//Mist16, 2022-03-01

#include <iostream>

using namespace std;

int A[1000]= { 0, };
int visitLength[1000] = { 0, };
int N = 0;

int maxLength = 0;

void run(int idx, int current, int length)
{
	for (int i = idx; i < N; i++)
	{
		if (current < A[i] && visitLength[i] < length+1)
		{
			visitLength[i] = length + 1;
			run(i, A[i], length + 1);
		}
	}
	if (maxLength < length)
	{
		maxLength = length;
	}

}

int main()
{
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	run(0, 0, 0);
	cout << maxLength;

	return 0;
}