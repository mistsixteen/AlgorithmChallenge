//Backjoon Problem No.4948
//https://www.acmicpc.net/problem/4948
//Mist16, 2022-04-14

#include <iostream>

using namespace std;

int main()
{
	int cnt = 0;
	int input = 0;

	bool Flag[250000] = { 0, };
	int count[250000] = { 0, };

	Flag[0] = true;
	Flag[1] = true;
	cnt = 0;

	for (int i = 2; i < 250000; i++)
	{
		if (Flag[i] == false)
		{
			cnt++;
			int idx = i + i;
			while (idx < 250000)
			{
				Flag[idx] = true;
				idx += i;
			}
		}
		count[i] = cnt;
	}

	while(true)
	{
		cin >> input;
		if (input == 0)
			break;
		cout << count[input*2] - count[input] << endl;
	}

	return 0;
}