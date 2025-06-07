#include <iostream>
#include <map>

using namespace std;

char cArray[100010];
int run()
{
	int N = 0;
	int pos = 0;
	char ca, cb;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> cArray[i];
	}
	cArray[N] = 'W';
	N++;

	for (int i = 0; i < N; i++)
	{
		if (cArray[i] == 'W')
		{
			if (i != pos)
			{
				if (pos == i - 1)
					return 1;
				else
				{
					char temp = cArray[pos];
					int ans = 0;
					for (int j = pos; j <= i - 1; j++)
					{
						if (temp != cArray[j])
						{
							ans = 1;
							break;
						}
					}
					if (ans == 0)
						return 1;
				}
			}
			pos = i+1;
		}
	}

	return 0;
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
		if (run() == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}