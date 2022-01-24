//Backjoon Problem No.16953
//https://www.acmicpc.net/problem/16953
//Mist16, 2022-01-24
#include <iostream>
#include <list>

using namespace std;

unsigned long A, B;
int minTurn = -1;

void check(unsigned long current, int turn)
{
	if (current > B)
		return;
	if (minTurn != -1 && turn > minTurn)
		return;
	if (current == B)
	{
		if (minTurn == -1)
		{
			minTurn = turn;
		}
		else if (minTurn > turn)
			minTurn = turn;
		return;
	}
	check(current * 10 + 1, turn + 1);
	check(current * 2, turn + 1);
}

int main()
{
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list<int> a;

	//input n, pipemap;
	cin >> A >> B;

	check(A, 1);

	cout << minTurn;

	return 0;
}