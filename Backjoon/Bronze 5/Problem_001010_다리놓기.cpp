//Backjoon Problem No.1010
//https://www.acmicpc.net/problem/1010
//Mist16, 2022-05-01

#include <iostream>
using namespace std;

unsigned long long arr[31][31] = { 0, };

unsigned long long run(int a, int b)
{
	unsigned long long answer = 0;
	if (a > b || a < 0 || b < 0)
		return 0;
	else if (arr[a][b] != 0)
		return arr[a][b];
	answer = run(a - 1, b - 1) + run(a, b - 1);
	arr[a][b] = answer;

	return answer;

}

int main()
{
	int testCases;
	int a, b;

	for (int i = 0; i <= 30; i++)
	{
		arr[i][i] = 1;
	}

	cin >> testCases;

	for (int i = 0; i < testCases; i++)
	{
		cin >> a >> b;
		cout << run(a, b) << endl;
	}

	return 0;
}