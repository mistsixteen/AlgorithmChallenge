//AtCoder Beginner Contest 409
//Task. C
//Mist16, 2025-06-07

#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int* array = new int[500000] {0};

	int result = 0;

	int n, l;
	cin >> n >> l;

	array[0] = 1;
	int pos = 0;
	int temp;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> temp;

		pos = (pos + temp) % l;
		array[pos]++;
	}

	if (l % 3 != 0)
	{
		cout << 0;
		return 0;
	}

	int shortL = l / 3;

	for (int i = 0; i <= shortL; i++)
	{
		result += array[i] * array[i + shortL] * array[i + shortL + shortL];
	}

	cout << result;

	return 0;
}