//Backjoon Problem No.6064
//https://www.acmicpc.net/problem/6064
//Mist16, 2022-04-25

#include <iostream>
using namespace std;

int run(int m, int n, int x, int y)
{
	int a, b;
	int idx = x;
	int value[40010] = { 0, };
	while (1)
	{
		b = idx % n;
		if (b == 0)
			b = n;
		if (b == y)
			return idx;
		if (value[b] != 0)
			return -1;
		value[b] = idx;
		idx += m;

	}
}

int main()
{
	int testcases;
	int m, n, x, y;
	cin >> testcases;


	for (int i = 0; i < testcases; i++)
	{
		cin >> m >> n >> x >> y;
		cout << run(m, n, x, y) << "\n";
	}

	return 0;
}