

#include <iostream>
#include <map>

using namespace std;

unsigned long long run()
{
	unsigned long long arr[26][26] = { 0, };
	int N = 0;
	unsigned long long result = 0;
	char ca, cb;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> ca >> cb;
		arr[ca - 'a'][cb - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (arr[i][j] != 0)
			{
				//x line
				for (int k = 0; k < 26; k++)
				{
					if (i == k)
						continue;
					if (arr[k][j] != 0)
					{
						result = result + arr[i][j] * arr[k][j];
					}
				}
				// y line
				for (int k = 0; k < 26; k++)
				{
					if (j == k)
						continue;
					if (arr[i][k] != 0)
					{
						result = result + arr[i][j] * arr[i][k];
					}
				}
				//end
				arr[i][j] = 0;
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