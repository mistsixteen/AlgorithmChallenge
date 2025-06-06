//Backjoon Problem No.14888
//https://www.acmicpc.net/problem/14888
//Mist16, 2022-02-28

#include <iostream>

using namespace std;

struct oper
{
	int plus;
	int minus;
	int time;
	int div;
	oper() : plus(0), minus(0), time(0), div(0) {}
};

int inputArr[11];
oper numOper;
int numArr = 0;

int maxValue = -1000000001;
int minValue = 1000000001;

void run(int current, int index, oper opLeft)
{
	if (index == numArr)
	{
		if (current > maxValue)
			maxValue = current;
		if (current < minValue)
			minValue = current;
		return;
	}

	if (opLeft.plus > 0)
	{
		opLeft.plus--;
		run(current + inputArr[index], index + 1, opLeft);
		opLeft.plus++;
	}
	if (opLeft.minus > 0)
	{
		opLeft.minus--;
		run(current - inputArr[index], index + 1, opLeft);
		opLeft.minus++;
	}
	if (opLeft.time > 0)
	{
		opLeft.time--;
		run(current * inputArr[index], index + 1, opLeft);
		opLeft.time++;
	}
	if (opLeft.div > 0)
	{
		opLeft.div--;
		run((int)(current / inputArr[index]), index + 1, opLeft);
		opLeft.div++;
	}
}

int main()
{
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//input n, pipemap;
	cin >> numArr;

	for (int i = 0; i < numArr; i++)
		cin >> inputArr[i];

	cin >> numOper.plus >> numOper.minus >> numOper.time >> numOper.div;

	run(inputArr[0], 1, numOper);

	cout << maxValue << "\n" << minValue;


	return 0;
}