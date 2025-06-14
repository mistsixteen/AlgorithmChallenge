#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int k;
	int answer = 0;
	vector<int> list;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		list.push_back(temp);
	}

	cin >> k;

	for (int i = 0; i < n; i++)
	{
		if (list[i] >= k)
		{
			answer++;
		}
	}

	cout << answer;

	return 0;
}