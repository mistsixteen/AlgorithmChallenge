//Backjoon Problem No.20365
//https://www.acmicpc.net/problem/20365
//Mist16, 2025-06-10

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int answer = 1;
	char first;
	char last;

	cin >> n;

	cin >> first;

	last = first;

	for (int i = 1; i < n; i++)
	{
		char temp;
		cin >> temp;

		if (last == first && temp != first)
		{
			answer++;
		}

		last = temp;	
	}

	cout << answer;

	return 0;
}