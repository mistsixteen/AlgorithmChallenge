//Backjoon Problem No.1065
//https://www.acmicpc.net/problem/1065
//Mist16, 2022-03-09

#include <iostream>

using namespace std;


bool IsHansu(int num)
{
	int digit[3];
	if (num < 100)
		return true;
	if (num == 1000)
		return false;
	digit[0] = num % 10;
	digit[1] = (num / 10) % 10;
	digit[2] = num / 100;

	if (digit[2] - digit[1] == digit[1] - digit[0])
	{
		return true;
	}
	return false;

}

int main()
{
	int N = 0;
	int hansuNum = 0;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		if (IsHansu(i))
			hansuNum++;
	}
	cout << hansuNum;
	return 0;
}