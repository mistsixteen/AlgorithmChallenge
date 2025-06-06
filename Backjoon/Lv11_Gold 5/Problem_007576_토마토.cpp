//Backjoon Problem No.7576
//https://www.acmicpc.net/problem/7576
//Mist16, 2022-03-12

#include <iostream>
#include <queue>

using namespace std;

int boards[1000][1000] = { 0, }; //xpos, ypos

int M, N;
int tomatoCount = 0;
int maxTurn = 0;

queue<pair<int, int>> tomatoQueue;

int main()
{
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> boards[j][i];
			if (boards[j][i] == 1)
			{
				tomatoQueue.push(pair<int, int>(j, i));
			}
			else if(boards[j][i] == 0)
				tomatoCount++;
				
		}
	}

	if (tomatoCount == 0)
	{
		cout << 0;
		return 0;
	}

	while (!tomatoQueue.empty() && tomatoCount != 0)
	{
		pair<int, int> current = tomatoQueue.front();
		tomatoQueue.pop();

		//up
		if (current.second - 1 >= 0 && boards[current.first][current.second - 1] == 0)
		{
			boards[current.first][current.second - 1] = boards[current.first][current.second] + 1;
			if (boards[current.first][current.second - 1] > maxTurn)
				maxTurn = boards[current.first][current.second - 1];
			tomatoQueue.push(pair<int, int>(current.first, current.second - 1));
			tomatoCount--;
		}
		//down
		if (current.second + 1 < N && boards[current.first][current.second + 1] == 0)
		{
			boards[current.first][current.second + 1] = boards[current.first][current.second] + 1;
			tomatoQueue.push(pair<int, int>(current.first, current.second + 1));
			if (boards[current.first][current.second + 1] > maxTurn)
				maxTurn = boards[current.first][current.second + 1];
			tomatoCount--;
		}
		//left
		if (current.first - 1 >= 0 && boards[current.first - 1][current.second] == 0)
		{
			boards[current.first - 1][current.second] = boards[current.first][current.second] + 1;
			if (boards[current.first - 1][current.second] > maxTurn)
				maxTurn = boards[current.first - 1][current.second];
			tomatoQueue.push(pair<int, int>(current.first - 1, current.second));
			tomatoCount--;
		}

		//right
		if (current.first + 1 < M && boards[current.first + 1][current.second] == 0)
		{
			boards[current.first + 1][current.second] = boards[current.first][current.second] + 1;
			if (boards[current.first + 1][current.second] > maxTurn)
				maxTurn = boards[current.first + 1][current.second];
			tomatoQueue.push(pair<int, int>(current.first + 1, current.second));
			tomatoCount--;
		}


	}

	if (tomatoCount != 0)
		cout << -1;
	else
		cout << maxTurn - 1;

	return 0;
}