//Backjoon Problem No.6603
//https://www.acmicpc.net/problem/6603
//Mist16, 2022-05-01

#include <iostream>
#include <vector>
using namespace std;

int k;
int arr[30] = { 0, };

void run(vector<int> fool, int idx, int left)
{
	if (idx >= k)
		return;
	if (k - idx == left)
	{
		for(int i = idx; i< k; i++)
		{
			fool.push_back(arr[i]);
			left--;
		}
	}
	if(left == 0)
	{
		for (int i : fool)
		{
			cout << i <<" ";
		}
		cout << "\n";
		return;
	}

	fool.push_back(arr[idx]);
	run(fool, idx + 1, left - 1);
	fool.pop_back();
	run(fool, idx + 1, left);
}

int main()
{
	vector<int> blank;
	while (true)
	{
		cin >> k;
		if (k == 0)
			break;
		for (int i = 0; i < k; i++)
			cin >> arr[i];
		run(blank, 0, 6);
		cout << "\n";
	}

	return 0;
}