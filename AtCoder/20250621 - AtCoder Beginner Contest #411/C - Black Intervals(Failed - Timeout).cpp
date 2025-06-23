#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


bool arr[500001];
int n, q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int temp;
	cin >> n >> q;

	for (int i = 0; i < q; i++)
	{
		cin >> temp;
		arr[temp] = !arr[temp];

		int score = 0;

		for (int i = 0; i < n; i++)
		{
			if(arr[i] == false && arr[i+1] == true)
			{
				score++;
			}
		}

		cout << score << endl;
	}

	return 0;
}