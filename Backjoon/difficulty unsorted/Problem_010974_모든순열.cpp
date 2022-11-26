//Backjoon Problem No.10974
//https://www.acmicpc.net/problem/10974
//Mist16, 2022-05-18

#include <iostream>
#include <vector>

using namespace std;
int n = 0;

void run(unsigned int bitMask, vector<int> currentArray)
{
	if (currentArray.size() == n)
	{
		for (auto i : currentArray)
			cout << i << " ";
		cout << "\n";
	}
	for (int i = 1; i <= n; i++)
	{
		if ((bitMask & (1 << i)) == 0)
		{
			currentArray.push_back(i);
			run(bitMask | (1 << i), currentArray);
			currentArray.pop_back();
		}
	}
}

int main()
{
	vector<int> blankVector;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	run(0, blankVector);


	return 0;
}