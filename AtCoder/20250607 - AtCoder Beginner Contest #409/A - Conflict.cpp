//AtCoder Beginner Contest 409
//Task. A
//Mist16, 2025-06-07

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
	char a[101], b[101];


	cin >> n >> a >> b;

	for (int i = 0; i < n; i++)
	{
		if (a[i] == 'o' && b[i] == 'o')
		{
			cout << "Yes";
			return 0;
		}
	}


	cout << "No";

	return 0;
}