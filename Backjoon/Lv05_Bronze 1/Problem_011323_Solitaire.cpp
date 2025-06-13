//Backjoon Problem No.11323
//https://www.acmicpc.net/problem/11323
//Mist16, 2025-06-14

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int run();

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << run() << endl;
	}

	return 0;
}

int run()
{
	int point = 0;
	
	int dice[6];
	int diceIdx = 0;

	int targetPos = 0;
	int currentPos = 0;
	
	cin >> targetPos;

	for (int i = 0; i < 6; i++)
	{
		cin >> dice[i];
	}

	while (targetPos != currentPos)
	{
		int move = dice[diceIdx];

		diceIdx = (diceIdx + 1) % 6;

		if (currentPos + move > targetPos)
		{
			continue;
		}

		currentPos += move;
		point += currentPos;
	}

	return point;
}