#include <iostream>
#include <map>

using namespace std;

int run()
{
	int answer = 0;
	int cArr[200010] = { 0, };
	int bPos, aPos;
	int bTotal = 0, aTotal = 0;
	int gap;
	int CandyEat = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> cArr[i];
	}
	bPos = n; aPos = 1;
	

	while (bPos >= aPos)
	{

		if (bTotal == aTotal)
		{
			answer = CandyEat;
			aTotal += cArr[aPos];
			aPos++;
		}
		else if (aTotal > bTotal)
		{
			bTotal += cArr[bPos];
			bPos--;
		}
		else
		{
			aTotal += cArr[aPos];
			aPos++;
		}
		CandyEat++;
	}
	//answer on last
	if (bTotal == aTotal)
	{
		answer = CandyEat;
	}
	return answer;
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
		cout << run() << "\n";
	}
	return 0;
}