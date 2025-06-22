//Backjoon Problem No.15953
//https://www.acmicpc.net/problem/15953
//Mist16, 2025-06-22

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int Reward2017(int rank)
{
	if (rank == 0)
		return 0;
	else if (rank == 1)
		return 5000000;
	else if (rank <= 3)
		return 3000000;
	else if (rank <= 6)
		return 2000000;
	else if (rank <= 10)
		return 500000;
	else if (rank <= 15)
		return 300000;
	else if (rank <= 21)
		return 100000;
	else
		return 0;
}

int Reward2018(int rank)
{
	if (rank == 0)
		return 0;
	else if (rank == 1)
		return 5120000;
	else if (rank <= 3)
		return 2560000;
	else if (rank <= 7)
		return 1280000;
	else if (rank <= 15)
		return 640000;
	else if (rank <= 31)
		return 320000;
	else
		return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		cout << Reward2017(a) + Reward2018(b) << endl;
	}

	return 0;
}