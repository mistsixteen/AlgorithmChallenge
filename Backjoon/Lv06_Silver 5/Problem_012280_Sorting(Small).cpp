//Backjoon Problem No.12280
//https://www.acmicpc.net/problem/12280
//Mist16, 2025-06-14

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void run(int caseNumber);

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		run(i+1);
	}

	return 0;
}

void run(int caseNumber)
{
	int n;
	cin >> n;

	vector<int> odd, even;
	vector<bool> isOdd;
	
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (temp % 2 == 0)
		{
			isOdd.push_back(false);
			even.push_back(temp);
		}
		else
		{
			isOdd.push_back(true);
			odd.push_back(temp);
		}
	}

	sort(odd.begin(), odd.end());
	sort(even.begin(), even.end());
	
	int oddIndex = 0;
	int evenIndex = even.size() - 1;
	
	cout << "Case #" << caseNumber << ": ";

	for (int i = 0; i < n; i++)
	{
		if (isOdd[i] == true)
		{
			cout << odd[oddIndex++] << " ";
		}
		else
		{
			cout << even[evenIndex--] << " ";
		}
	}
	cout << endl;
}