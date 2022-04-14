//Backjoon Problem No.11653
//https://www.acmicpc.net/problem/11653
//Mist16, 2022-04-14

#include <iostream>

using namespace std;

int main()
{
	int input = 0;
	int idx = 2;
	cin >> input;
	while (input >= idx)
	{
		if (input % idx == 0)
		{
			input = input / idx;
			cout << idx << "\n";
		}
		else
			idx++;
	}
	return 0;
}