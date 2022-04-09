//Backjoon Problem No.2805
//https://www.acmicpc.net/problem/2805
//Mist16, 2022-04-09

#include <iostream>
#include <list>
using namespace std;

list<int> woods;
int N;
unsigned long long M;

int run(int start, int end)
{
	unsigned long long current = 0;
	int middle = (start + end) / 2;
	if (start + 1 == end)
		middle = end;

	if (start == end)
		return start;

	for (int i : woods)
	{
		if (i > middle)
		{
			current += (i - middle);

			if (current >= M)
				break;
		}
	}

	if (start + 1 == end)
	{
		if (M <= current)
		{
			return end;
		}
		else
		{
			return start;
		}
	}
	
	if (M <= current)
		return run(middle, end);
	else
		return run(start, middle);
}

int main()
{
	int temp, max;
	max = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	woods.resize(N);

	for (auto iter = woods.begin(); iter != woods.end(); iter++)
	{
		cin >> *iter;
		if (*iter > max)
			max = *iter;
	}

	cout << run(0, max);
		

	return 0;
}