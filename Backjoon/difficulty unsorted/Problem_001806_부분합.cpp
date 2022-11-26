//Backjoon Problem No.1806
//https://www.acmicpc.net/problem/1806
//Mist16, 2022-04-10

#include <iostream>

using namespace std;

int Arr[100001] = { 0, };
int N = 0;
unsigned long long target = 0;
int idxA, idxB;
int minValue = 100001;

int main()
{
	unsigned long long total = 0;
	int startPos;
	int endPos;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> target;

	for (int i = 0; i < N; i++)
	{
		cin >> Arr[i];
		total += Arr[i];
	}
	if (total < target)
	{
		cout << "0";
		return 0;
	}

	startPos = 0;
	endPos = 0;
	total = Arr[0];

	while (endPos < N)
	{
		if (total >= target)
		{
			if(endPos - startPos + 1 < minValue)
				minValue = endPos - startPos + 1;
			if (minValue == 1)
				break;
			else
			{
				total -= Arr[startPos];
				startPos++;
			}
		}
		else
		{
			endPos++;
			if (endPos >= N)
				break;
			total += Arr[endPos];
			
		}
	}

	cout << minValue;

	return 0;
}