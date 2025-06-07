#include <iostream>

using namespace std;

int main()
{
	int N, temp;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (temp >= 1900)
			cout << "Division 1\n";
		else if (temp >= 1600)
			cout << "Division 2\n";
		else if (temp >= 1400)
			cout << "Division 3\n";
		else
			cout << "Division 4\n";
	}

	return 0;
}