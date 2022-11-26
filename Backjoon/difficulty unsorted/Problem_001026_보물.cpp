//Backjoon Problem No.1026
//https://www.acmicpc.net/problem/1026
//Mist16, 2022-04-27

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int N, temp;
	int result = 0;
	vector<int> vectA, vectB;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		vectA.push_back(temp);
	}

	sort(vectA.begin(), vectA.end());

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		vectB.push_back(temp);
	}
	sort(vectB.rbegin(), vectB.rend());

	for (int i = 0; i < N; i++)
	{
		result += vectA.at(i) * vectB.at(i);
	}

	cout << result;

	return 0;
}