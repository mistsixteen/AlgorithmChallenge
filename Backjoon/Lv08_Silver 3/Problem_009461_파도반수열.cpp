//Backjoon Problem No.9461
//https://www.acmicpc.net/problem/9461
//Mist16, 2022-04-30

#include <iostream>
using namespace std;

unsigned long long arr[101] = { 0, };

int main()
{
	int testCases, input;

	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;

	for (int i = 4; i <= 100; i++)
		arr[i] = arr[i - 2] + arr[i - 3];
	
	cin >> testCases;

	for (int i = 0; i < testCases; i++)
	{
		cin >> input;
		cout << arr[input] << "\n";
	}

	return 0;
}