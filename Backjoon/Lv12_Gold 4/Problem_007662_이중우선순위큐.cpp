//Backjoon Problem No.7662
//https://www.acmicpc.net/problem/7662
//Mist16, 2022-04-04
#include <iostream>
#include <set>
using namespace std;

int main()
{
	int testCases;
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> testCases;

	for (int currentCase = 0; currentCase < testCases; currentCase++)
	{
		int N, temp;
		char tempC;
		multiset<int> mSet;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> tempC;

			if (tempC == 'I')
			{
				cin >> temp;
				mSet.insert(temp);
			}
			else
			{
				cin >> temp;
				if (mSet.empty())
				{
					continue;
				}
				if (temp == 1)
				{
					auto iter = mSet.end();
					iter--;
					temp = *iter;
					mSet.erase(iter);
				}
				else
				{
					auto iter = mSet.begin();
					temp = *iter;
					mSet.erase(iter);
				}
			}
		}
		if (mSet.empty())
		{
			cout << "EMPTY\n";
		}
		else
		{
			auto iter1 = mSet.end();
			auto iter2 = mSet.begin();
			iter1--;
			cout << *iter1 << " " << *iter2 << "\n";
		}
	}
	return 0;
}