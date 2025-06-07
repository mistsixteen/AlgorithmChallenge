#include <iostream>
#include <map>

using namespace std;

int run()
{
	char arr[50][50];
	char temp;

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	//run
	for (int i = n-1; i > 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == '.')
			{
				for (int k = i - 1; k >= 0; k--)
				{
					if (arr[k][j] == '*')
					{
						arr[i][j] = '*';
						arr[k][j] = '.';
						break;
					}
					else if (arr[k][j] == 'o')
						break;
				}
			}
		}
	}

	//output
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
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
		run();
	}
	return 0;
}