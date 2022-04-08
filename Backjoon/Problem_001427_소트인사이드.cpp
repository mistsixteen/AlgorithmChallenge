//Backjoon Problem No.1427
//https://www.acmicpc.net/problem/1427
//Mist16, 2022-04-08

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int arr[10] = { 0, };
	string s;
	cin >> s;

	for (char c : s)
	{
		arr[c - '0']++;
	}

	for (int i = 9; i >= 0; i--)
	{
		for (int j = 0; j < arr[i]; j++)
			cout << i;
	}

	return 0;
}