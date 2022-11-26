//Backjoon Problem No.14731
//https://www.acmicpc.net/problem/14731
//Mist16, 2022-04-04
#include <iostream>
#include <map>
using namespace std;

static unsigned long long preset = 1000000007;

map<int, unsigned long long> powMap;

unsigned long long getPow(int n)
{
	auto iter = powMap.find(n);
	if (iter == powMap.end())
	{
		int m1 = n / 2;
		int m2 = n - m1;
		unsigned long long newValue = getPow(m1) * getPow(m2);
		newValue = newValue % preset;
		powMap.insert(pair<int, unsigned long long>(n, newValue));
		return newValue;
	}
	else
		return iter->second;
}

int main()
{
	int N;
	unsigned long long current = 0;
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	powMap.insert(pair<int, unsigned long long>(0, 1));
	powMap.insert(pair<int, unsigned long long>(1, 2));

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		unsigned long long a, b, resultA, resultB;
		cin >> a >> b;
		if (b == 0)
			continue;
		resultA = a * b;
		b--;
		resultB = getPow(b);
		resultA = resultA % preset;
		resultB = resultB % preset;

		current = current + (resultA * resultB);
		current = current % preset;
	}

	cout << current;

	return 0;
}
