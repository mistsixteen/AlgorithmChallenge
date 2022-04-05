//Backjoon Problem No.1697
//https://www.acmicpc.net/problem/1697
//Mist16, 2022-04-05

#include <iostream>
#include <queue>

using namespace std;

int mValue = 999999;

int timeMap[1000001] = { 0, };

int sPos, bPos;

queue<int> visitQueue;

int main()
{
	cin >> sPos >> bPos;

	if (sPos == bPos)
	{
		cout << "0";
		return 0;
	}

	timeMap[sPos] = 1;

	visitQueue.push(sPos);

	while (!visitQueue.empty())
	{
		int current = visitQueue.front();
		visitQueue.pop();
		if (current == bPos)
			break;
		//*2
		if (current * 2 <= 100000 && timeMap[current * 2] == 0)
		{
			timeMap[current * 2] = timeMap[current] + 1;
			visitQueue.push(current * 2);
		}
		//+1
		if (current + 1 <= 100000 && timeMap[current + 1] == 0)
		{
			timeMap[current + 1] = timeMap[current] + 1;
			visitQueue.push(current + 1);
		}
		//-1
		if (current - 1 >= 0 && timeMap[current - 1] == 0)
		{
			timeMap[current - 1] = timeMap[current] + 1;
			visitQueue.push(current - 1);
		}
	}

	cout << timeMap[bPos] - 1;

	return 0;
}