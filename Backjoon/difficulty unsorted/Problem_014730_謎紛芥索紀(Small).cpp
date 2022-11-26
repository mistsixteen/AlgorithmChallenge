//Backjoon Problem No.14730
//https://www.acmicpc.net/problem/14730
//Mist16, 2022-04-04
#include <iostream>
using namespace std;


int main()
{
	int N;
	int current = 0;
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		if (b == 0)
			continue;
		current = current + (a * b);
	}

	cout << current;

	return 0;
}