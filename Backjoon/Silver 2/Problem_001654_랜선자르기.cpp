//Backjoon Problem No.1654
//https://www.acmicpc.net/problem/1654
//Mist16, 2022-04-09

#include <iostream>
#include <list>

using namespace std;

list<unsigned long> lines;
int N, K;

int run(unsigned long start, unsigned long end)
{
	unsigned long current = 0;
	unsigned long middle = (start + end) / 2;

	if (start + 1 == end)
		middle = end;
	if (start == end)
		return start;

	for (unsigned long i : lines)
	{
		if (i >= middle)
		{
			current += (i / middle);

			if (current >= N)
				break;
		}
	}

	if (start + 1 == end)
	{
		if (N <= current)
		{
			return end;
		}
		else
		{
			return start;
		}
	}
	
	if (N <= current)
		return run(middle, end);
	else
		return run(start, middle);
}

int main()
{
	unsigned long max = 0;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> N;
	lines.resize(K);

	for (auto iter = lines.begin(); iter != lines.end(); iter++)
	{
		cin >> *iter;
		if (*iter >= N)
			max += (*iter / N) + 1;
		else
			max += 1;
	}
	if (max == 0)
		max = K;
	cout << run(1, max);

	return 0;
}