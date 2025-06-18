//Backjoon Problem No.26307
//https://www.acmicpc.net/problem/26307
//Mist16, 2025-06-18

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int h, m;

	cin >> h >> m;

	int result = (h - 9) * 60 + m;

	cout << result;

	return 0;
}