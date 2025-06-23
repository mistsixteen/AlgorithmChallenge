#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int d[51];
	string str;

	cin >> n;

	for (int i = 0; i < n-1; i++)
	{
		cin >> d[i];
	}

	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i + 1; j < n; j++)
		{
			sum = sum + d[j - 1];
			cout << sum << " ";
		}

		cout << endl;
	}
	
	return 0;
}