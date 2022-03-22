//Backjoon Problem No.12100
//https://www.acmicpc.net/problem/12100
//Mist16, 2022-03-22

#include <iostream>

using namespace std;

struct Gameboard
{
	short board[20][20] = { 0, };
};

short gMaxBlock = 0;
int N = 0;

int getBlockRank(int num)
{
	int Rank = 1;

	while (num > 2)
	{
		Rank++;
		num /= 2;
	}
	return Rank;

}

void run(Gameboard& cBoard, int moveLeft)
{
	Gameboard leftBoard, rightBoard, upBoard, downBoard;
	if (moveLeft == 0)
	{
		short maxValue = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (maxValue < cBoard.board[i][j])
					maxValue = cBoard.board[i][j];
			}
		}
		if (gMaxBlock < maxValue)
			gMaxBlock = maxValue;
		return;
	}

	//left
	for (int i = 0; i < N; i++)
	{
		int idx = 0;
		int nextblock = 0;
		for (int j = 0; j < N; j++)
		{
			if (cBoard.board[i][j] != 0)
			{
				if (nextblock == cBoard.board[i][j])
				{
					leftBoard.board[i][idx] = nextblock + 1;
					nextblock = 0;
					idx++;
				}
				else
				{
					if (nextblock == 0)
						nextblock = cBoard.board[i][j];
					else
					{
						leftBoard.board[i][idx] = nextblock;
						nextblock = cBoard.board[i][j];
						idx++;
					}
				}
			}
			leftBoard.board[i][idx] = nextblock;
		}
	}
	run(leftBoard, moveLeft - 1);



	//right

	for (int i = 0; i < N; i++)
	{
		int idx = N - 1;
		int nextblock = 0;
		for (int j = N - 1; j >= 0; j--)
		{
			if (cBoard.board[i][j] != 0)
			{
				if (nextblock == cBoard.board[i][j])
				{
					rightBoard.board[i][idx] = nextblock + 1;
					nextblock = 0;
					idx--;
				}
				else
				{
					if (nextblock == 0)
						nextblock = cBoard.board[i][j];
					else
					{
						rightBoard.board[i][idx] = nextblock;
						nextblock = cBoard.board[i][j];
						idx--;
					}
				}
			}
			rightBoard.board[i][idx] = nextblock;
		}
	}
	run(rightBoard, moveLeft - 1);

	//down
	for (int j = 0; j < N; j++)
	{
		int idx = N - 1;
		int nextblock = 0;
		for (int i = N - 1; i >= 0; i--)
		{
			if (cBoard.board[i][j] != 0)
			{
				if (nextblock == cBoard.board[i][j])
				{
					downBoard.board[idx][j] = nextblock + 1;
					nextblock = 0;
					idx--;
				}
				else
				{
					if (nextblock == 0)
						nextblock = cBoard.board[i][j];
					else
					{
						downBoard.board[idx][j] = nextblock;
						nextblock = cBoard.board[i][j];
						idx--;
					}
				}
			}
			downBoard.board[idx][j] = nextblock;
		}
	}
	run(downBoard, moveLeft - 1);

	//up
	for (int j = 0; j < N; j++)
	{
		int idx = 0;
		int nextblock = 0;
		for (int i = 0; i < N; i++)
		{
			if (cBoard.board[i][j] != 0)
			{
				if (nextblock == cBoard.board[i][j])
				{
					upBoard.board[idx][j] = nextblock + 1;
					nextblock = 0;
					idx++;
				}
				else
				{
					if (nextblock == 0)
						nextblock = cBoard.board[i][j];
					else
					{
						upBoard.board[idx][j] = nextblock;
						nextblock = cBoard.board[i][j];
						idx++;
					}
				}
			}
			upBoard.board[idx][j] = nextblock;
		}
	}
	run(upBoard, moveLeft - 1);
}

int main()
{
	int temp;
	Gameboard firstBoard;
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			if (temp != 0)
			{
				firstBoard.board[i][j] = getBlockRank(temp);
			}
		}
	}

	run(firstBoard, 5);
	if (gMaxBlock != 0)
	{
		int temp = 1;
		for (int i = 0; i < gMaxBlock; i++)
		{
			temp *= 2;
		}
		cout << temp << endl;
	}
	else
		cout << gMaxBlock << endl;
	
	return 0;
}