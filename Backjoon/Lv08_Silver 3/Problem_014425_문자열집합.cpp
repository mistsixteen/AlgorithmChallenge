//Backjoon Problem No.14425
//https://www.acmicpc.net/problem/14425
//Mist16, 2022-12-27

#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n, m;
	int answer = 0;
	string str;
	set<string> stringset;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		stringset.insert(str);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> str;
		if (stringset.find(str) != stringset.end())
		{
			answer++;
		}
	}

	cout << answer;

}
