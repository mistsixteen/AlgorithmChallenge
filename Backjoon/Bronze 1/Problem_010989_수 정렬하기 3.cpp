//Backjoon Problem No.10989
//https://www.acmicpc.net/problem/10989
//Mist16, 2022-03-20

#include <iostream>
using namespace std;


int main()
{
	int N, temp;
	int count[10001] = { 0, };

	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		count[temp]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		while (count[i] > 0)
		{
			count[i]--;
			cout << i << "\n";
		}
	}

	return 0;
}