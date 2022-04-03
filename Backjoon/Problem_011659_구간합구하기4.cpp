//Backjoon Problem No.11659
//https://www.acmicpc.net/problem/11659
//Mist16, 2022-04-03

#include <iostream>

using namespace std;

int main()
{
	int N, M;
	int a, b;

	unsigned long totalValue[100001] = { 0, };
	unsigned long temp = 0;

	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		totalValue[i] = totalValue[i - 1] + temp;
	}
	for (int i = 1; i <= M; i++)
	{
		cin >> a >> b;
		cout << totalValue[b] - totalValue[a - 1] << "\n";
	}
	
	return 0;
}