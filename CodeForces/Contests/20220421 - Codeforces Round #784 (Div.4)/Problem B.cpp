#include <iostream>
#include <map>

using namespace std;

int run()
{
	multimap<int, int> Triple;
	int N, temp;
	int result = -1;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (result == -1)
		{
			auto iter = Triple.find(temp);
			if (iter == Triple.end())
			{
				Triple.insert(pair<int, int>(temp, 1));
			}
			else
			{
				iter->second = iter->second + 1;
				if (iter->second >= 3)
					result = temp;
			}
		}

	}


	return result;
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