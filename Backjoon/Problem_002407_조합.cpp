//Backjoon Problem No.2407
//https://www.acmicpc.net/problem/2407
//Mist16, 2022-01-30
#include <iostream>
#include <list>

using namespace std;

list<unsigned int> bigNumber;

int multiArray[101] = { 0, };

int N, M;

void mul(int n)
{
	unsigned int temp = 0;
	unsigned int nextnumber = 0;

	for (auto iter2 = bigNumber.begin(); iter2 != bigNumber.end(); iter2++)
	{
		*iter2 = *iter2 * n;
	}
	auto iter = bigNumber.end();
	for (int i = 0; i < bigNumber.size(); i++)
	{
		iter--;
		temp = *iter;

		temp = temp + nextnumber;

		nextnumber = temp / 10000;
		temp = temp % 10000;

		*iter = temp;
	}

	if (nextnumber != 0)
		bigNumber.push_front(nextnumber);
}

void div(int n)
{
	unsigned int temp = 0;
	unsigned int nextnumber = 0;
	
	for (auto iter = bigNumber.begin(); iter != bigNumber.end(); iter++)
	{
		temp = *iter;
		temp = temp + nextnumber * 10000;

		nextnumber = temp % n;
		temp = temp / n;
		*iter = temp;
	}

	while (1)
	{
		if (bigNumber.size() <= 1)
			return;
		if (bigNumber.front() == 0)
		{
			bigNumber.pop_front();
		}
		else
			return;
	}

}

void print()
{
	for (auto iter = bigNumber.begin(); iter != bigNumber.end(); iter++)
	{
		if (iter == bigNumber.begin())
		{
			cout << *iter;
		}
		else
		{
			cout.width(4);
			cout.fill('0');
			cout << *iter;
		}
	}
}

int main()
{
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	bigNumber.push_back(1);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		multiArray[N - i]++;
		multiArray[i + 1]--;
	}

	for (int i = 2; i <= 100; i++)
	{
		if (multiArray[i] == 1)
		{
			mul(i);
		}
		
	}

	for (int i = 2; i <= 100; i++)
	{
		if (multiArray[i] == -1)
			div(i);
	}

	print();

	return 0;
}