//Backjoon Problem No.4673
//https://www.acmicpc.net/problem/4673
//Mist16, 2022-03-09

#include <iostream>
using namespace std;

int isSelfNumber[10001] = { 0, };

void setNextNumber(int n)
{
	int nextNumber = n;
	while (n >= 10)
	{
		nextNumber += (n % 10);
		n = n / 10;
	}
	nextNumber += n;

	if (nextNumber > 10000)
		return;
	else if (isSelfNumber[nextNumber] == 0)
	{
		isSelfNumber[nextNumber] = 1;
		setNextNumber(nextNumber);
	}
}

int main()
{
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i <= 10000; i++)
	{
		if (isSelfNumber[i] == 0)
		{
			cout << i << "\n";
			setNextNumber(i);
		}
	}

	return 0;
}