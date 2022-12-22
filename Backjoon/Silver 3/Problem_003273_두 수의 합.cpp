//Backjoon Problem No.3273
//https://www.acmicpc.net/problem/3273
//Mist16, 2022-12-22

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> array;
	int n, x;

	cin >> n;
	array.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		array.push_back(temp);
	}
	cin >> x;

	sort(array.begin(), array.end());

	if (n == 1)
	{
		cout << "0";
		return 0;
	}

	int posa = 0;
	int posb = n - 1;
	int answer = 0;

	while (posa < posb)
	{
		int temp = array[posa] + array[posb];
		if (temp == x)
		{
			answer++;
			posb--;
		}
		else if (temp > x)
			posb--;
		else
			posa++;
	}

	cout << answer << endl;

	return 0;
}
