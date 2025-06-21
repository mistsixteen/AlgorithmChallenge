//Backjoon Problem No.3944
//https://www.acmicpc.net/problem/3944
//Mist16, 2025-06-19

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	
	cin >> t; 

	for (int i = 0; i < t; i++)
	{
		int n, total = 0;
		string str;
		cin >> n >> str;

		if (n == 2)
		{
			cout << "0" << endl;
			continue;
		}

		for (int j = 0; j < str.length(); j++)
		{
			total += (int)str[j] - 48;
		}

		cout << total % (n - 1) << endl;

	}

	return 0;
}