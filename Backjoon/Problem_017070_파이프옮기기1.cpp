//Backjoon Problem No.17070
//Mist16, 2022-01-22

#include <iostream>

using namespace std;

enum pipeCond
{
	None = 0,
	Left = 1,
	LDown = 2,
	Down = 4,
	ConditionChecked = 8
};

int pipeMap[16][16] = { 0, };
int checkMap[16][16] = { 0, };
int N = 0;



//현재 위치에서 파이프 타설이 가능한지 체크
void checkConstructProb(int y, int x)
{
	int cond = pipeCond::ConditionChecked;
	//1. Left
	if (x + 1 < N)
	{
		if (pipeMap[y][x + 1] == 0)
			cond = cond | pipeCond::Left;
	}
	//2. Down
	if (y + 1 < N)
	{
		if (pipeMap[y + 1][x] == 0)
			cond = cond | pipeCond::Down;
	}
	//3. Left-Down
	if ((cond & pipeCond::Left) == (int)pipeCond::Left &&
		(cond & pipeCond::Down) == (int)pipeCond::Down)
	{
		if (pipeMap[y + 1][x + 1] == 0)
		{
			cond = cond | (int)pipeCond::LDown;
		}
	}
	checkMap[y][x] = cond;
}

//파이프 설치
int installPipe(int y, int x, int cond)
{
	int AllCases = 0;

	if (x == N-1 && y == N-1)
		return 1;

	if ((checkMap[y][x] & pipeCond::ConditionChecked) != pipeCond::ConditionChecked ) //unchecked, check
	{
		checkConstructProb(y, x);
	}
	//1. Left/LDown -> Left
	if (cond == pipeCond::Left || cond == pipeCond::LDown)
	{
		if((checkMap[y][x] & pipeCond::Left) == pipeCond::Left)
		{
			AllCases += installPipe(y, x + 1, pipeCond::Left);
		}
		
	}
	//2. Down/LDown -> Down
	if (cond == pipeCond::Down || cond == pipeCond::LDown)
	{
		if ((checkMap[y][x] & pipeCond::Down) == pipeCond::Down)
		{
			AllCases += installPipe(y + 1, x, pipeCond::Down);
		}
	}
	//3. All Cond -> LDown
	if ((checkMap[y][x] & pipeCond::LDown) == pipeCond::LDown)
	{
		AllCases += installPipe(y + 1, x + 1, pipeCond::LDown);
	}

	return AllCases;
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
	cout << installPipe(0, 1, pipeCond::Left);

	return 0;
}