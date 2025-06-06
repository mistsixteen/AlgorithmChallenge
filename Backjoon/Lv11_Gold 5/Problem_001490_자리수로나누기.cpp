//Backjoon Problem No.1490
//https://www.acmicpc.net/problem/1490
//Mist16, 2022-01-28
//성공!
#include <iostream>


using namespace std;

int findGCD(int a, int b)
{
	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int check(unsigned long long a, unsigned long long b, unsigned long long gcd, unsigned long long level)
{

	unsigned long long target = a * level + b;

	if (target % gcd == 0)
	{
		cout << target;
		return 0;
	}
	return 1;

}

int main()
{
	unsigned long long input, temp, ggcd;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> temp;
	input = temp;
	ggcd = 1;
	while (temp > 1)
	{
		unsigned long long mod = temp % 10;
		if (mod > 1)
		{
			if (ggcd > mod && ggcd % mod == 0)
			{

			}
			else
			{
				int gcd = findGCD(ggcd, mod);
				ggcd = ggcd * mod / gcd;
			}
		}
			
		temp = temp / 10;
	}

	if (input % ggcd == 0)
	{
		cout << input;
		return 0;
	}
	int i = 0;
	int level = 10;

	while (1)
	{
		if (check(input, i, ggcd, level) == 0)
			break;
		i++;
		if (i == level)
		{
			level = level * 10;
			i = 0;
		}
	}

	return 0;

}