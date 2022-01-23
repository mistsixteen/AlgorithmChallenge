//Backjoon Problem No.17069
//Mist16, 2022-01-23
//https://www.acmicpc.net/problem/17069
#include <iostream>
#include <queue>
using namespace std;

enum pipeCond
{
	None = 0,
	Right = 1,
	RDown = 2,
	Down = 4,
	ConditionChecked = 8
};

struct pipeCases
{
	unsigned long long Right;
	unsigned long long Down;
	unsigned long long RDown;

	pipeCases()
	{
		Right = 0;
		Down = 0;
		RDown = 0;
	}
};

int checkMap[23][23] = { 0, };
int pipeMap[23][23] = { 0, };
pipeCases pipeCount[23][23];

int N = 0;



//현재 위치에서 파이프 타설이 가능한지 체크
void checkConstructProb(int y, int x)
{
	int cond = pipeCond::ConditionChecked;
	//1. Right
	if (x + 1 < N)
	{
		if (pipeMap[y][x + 1] == 0)
			cond = cond | pipeCond::Right;
	}
	//2. Down
	if (y + 1 < N)
	{
		if (pipeMap[y + 1][x] == 0)
			cond = cond | pipeCond::Down;
	}
	//3. Right-Down
	if ((cond & pipeCond::Right) == (int)pipeCond::Right &&
		(cond & pipeCond::Down) == (int)pipeCond::Down)
	{
		if (pipeMap[y + 1][x + 1] == 0)
		{
			cond = cond | (int)pipeCond::RDown;
		}
	}
	checkMap[y][x] = cond;
}

void spreadPipe(int y, int x)
{
	checkConstructProb(y, x);
	//1.Right
	if (x + 1 < N)
	{
		if ((checkMap[y][x] & pipeCond::Right) == pipeCond::Right)
		{
			pipeCount[y][x + 1].Right += pipeCount[y][x].RDown + pipeCount[y][x].Right;
		}
	}
	//2.Down
	if (y + 1 < N)
	{
		if ((checkMap[y][x] & pipeCond::Down) == pipeCond::Down)
		{
			pipeCount[y + 1][x].Down += pipeCount[y][x].RDown + pipeCount[y][x].Down;
		}
	}
	//3.RDown
	if (x + 1 < N && y + 1 < N)
	{
		if ((checkMap[y][x] & pipeCond::RDown) == pipeCond::RDown)
		{
			pipeCount[y + 1][x + 1].RDown += pipeCount[y][x].RDown + pipeCount[y][x].Right + pipeCount[y][x].Down;
		}
	}
}

unsigned long long getPipeMap()
{
	//0~N-2
	unsigned long long Sum = 0;
	pipeCount[0][1].Right = 1;
	spreadPipe(0, 1);
	for (int i = 1; i <= N - 2; i++)
	{
		//1. Right
		for (int j = 1; j <= i; j++)
		{
			spreadPipe(i, j);
		}
		//2. Down
		for (int j = 0; j < i; j++)
		{
			spreadPipe(j, i+1); 
		}
		//3. Overlap
		spreadPipe(i, i + 1);
	}

	//last Line : Right Only
	for (int j = 0; j <= N - 1; j++)
	{
		spreadPipe(N - 1, j);
	}
	
	//N-1
	Sum = pipeCount[N - 1][N - 1].Down + pipeCount[N - 1][N - 1].Right + pipeCount[N - 1][N - 1].RDown;
	return Sum;
}

int main()
{
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//input n, pipemap;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> pipeMap[i][j];
		}
	}
	cout << getPipeMap();

	return 0;
}