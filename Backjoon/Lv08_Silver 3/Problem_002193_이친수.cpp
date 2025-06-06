//Backjoon Problem No.2193
//https://www.acmicpc.net/problem/2193
//Mist16, 2022-04-30

#include <iostream>
using namespace std;

unsigned long long arr[90][2] = {0, };
unsigned long long run(int current, int idx)
{
	unsigned long long total = 0;
	if (idx == 0)
		return 1;
	if (arr[idx][current] != 0)
		return arr[idx][current];
	if (current == 0)
		total += run(1, idx - 1);
	total += run(0, idx - 1);
	arr[idx][current] = total;
	return total;
}

int main()
{
	int n;
	arr[0][0] = 1;
	arr[0][1] = 1;
	cin >> n;

	cout << run(1, n - 1);

	return 0;
}