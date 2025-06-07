#include <iostream>
#include <map>

using namespace std;

unsigned long long run()
{
	int idx[31] = { 0, };
	unsigned long long array[31] = { 0, };
	int n, k;
	unsigned long long temp;
	unsigned long long answer = 0;
	unsigned long long ulltemp = 1;
	cin >> n >> k;
	for (int i = 0; i < 31; i++)
	{
		array[i] = ulltemp;
		ulltemp *= 2;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		for (int j = 30; j >= 0; j--)
		{
			if (temp >= array[j])
			{
				temp -= array[j];
				idx[j]++;
			}
		}
	}
	for (int i = 30; i >= 0; i--)
	{
		if (k >= (n - idx[i]))
		{
			k -= (n - idx[i]);
			answer += array[i];
		}
	}
	return answer;
}


int main()
{
	int testCases;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> testCases;
	for (int i = 0; i < testCases; i++)
	{
		cout << run() << "\n";
	}
	return 0;
}