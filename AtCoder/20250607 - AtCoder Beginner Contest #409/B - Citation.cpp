//AtCoder Beginner Contest 409
//Task. B
//Mist16, 2025-06-07

#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int score[101]{0};


	cin >> n;

	int temp;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		for (int j = 1; j <= 100; j++)
		{
			if (temp >= j)
			{
				score[j]++;
			}
		}
	}

	for (int i = 100; i > 0; i--)
	{
		if (score[i] >= i)
		{
			cout << i;
			return 0;
		}
	}

	cout << 0;
	return 0;
}