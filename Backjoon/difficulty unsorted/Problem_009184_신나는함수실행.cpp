//Backjoon Problem No.9184﻿
//https://www.acmicpc.net/problem/9184
//Mist16, 2022-04-15

#include <iostream>

using namespace std;

int memoryArray[51][51][51] = { 0, };


int run(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (memoryArray[a][b][c] != 0)
		return memoryArray[a][b][c];

	if (a > 20 || b > 20 || c > 20)
	{
		memoryArray[a][b][c] = run(20, 20, 20);
	}
	else if (a < b && b < c)
	{
		memoryArray[a][b][c] = run(a, b, c - 1) + run(a, b - 1, c - 1) - run(a, b - 1, c);
	}
	else
	{
		memoryArray[a][b][c] = run(a - 1, b, c) + run(a - 1, b - 1, c) + run(a - 1, b, c - 1) - run(a - 1, b - 1, c - 1);
	}
	return memoryArray[a][b][c];
}

int main()
{
	int a, b, c;

	while (1)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		else
			cout << "w(" << a << ", " << b << ", " << c << ") = " << run(a, b, c) << "\n";
	}
	return 0;
}