#include <iostream>

using namespace std;

int run()
{
	int arr[51] = { 0, };
	int N, temp;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	//odd
	temp = arr[1] % 2;
	for (int i = 3; i <= N; i += 2)
	{
		if (temp != arr[i] % 2)
			return -1;
	}
	//even
	temp = arr[2] % 2;
	for (int i = 4; i <= N; i += 2)
	{
		if (temp != arr[i] % 2)
			return -1;
	}

	return 1;
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
		if (run() == 1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}