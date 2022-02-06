//Backjoon Problem No.09663
//https://www.acmicpc.net/problem/9663
//Mist16, 2022-02-06
#include <iostream>

using namespace std;

int N;

struct QueenBoard
{
	unsigned int n[15] = { 0, };
};

int queenBoard(int idx, QueenBoard qBoard)
{
	int answer = 0;

	if (idx == N)
		return 1;
	for (int i = 0; i < N; i++)
	{
		if ((qBoard.n[i] & (1 << idx)) == 0)
		{
			QueenBoard tempBoard = qBoard;
			tempBoard.n[i] = tempBoard.n[i] | (1 << idx);
			for (int j = 1; j < N - idx; j++)
			{
				tempBoard.n[i] = tempBoard.n[i] | (1 << (idx+j));
				
				if (i - j >= 0)
				{
					tempBoard.n[i - j] = tempBoard.n[i - j] | (1 << (idx + j));
				}
				if (i + j < N)
				{
					tempBoard.n[i + j] = tempBoard.n[i + j] | (1 << (idx + j));
				}
			}
			answer += queenBoard(idx + 1, tempBoard);
		}
	}
	return answer;
}


int main()
{
	QueenBoard blankboard;
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	cout << queenBoard(0, blankboard);
	
	return 0;
}