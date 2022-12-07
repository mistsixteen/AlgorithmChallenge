//Backjoon Problem No.2630
//https://www.acmicpc.net/problem/2630
//Mist16, 2022-04-07

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int pArray[128][128] = { 0, };
int N;
int blueCount = 0;
int whiteCount = 0;

void run(int xS, int yS, int L)
{
	int startingPos = pArray[yS][xS];
	bool isCorrect = true;

	for (int i = yS; i < yS + L; i++)
	{
		for (int j = xS; j < xS + L; j++)
		{
			if (pArray[i][j] != startingPos)
			{
				isCorrect = false;
				break;
			}
		}
		if (!isCorrect)
			break;
	}

	if (isCorrect)
	{
		if (startingPos == 0)
		{
			whiteCount++;
		}
		else
		{
			blueCount++;
		}
	}
	else
	{
		int nextL = L / 2;
		run(xS, yS, nextL);
		run(xS + nextL, yS, nextL);
		run(xS, yS + nextL, nextL);
		run(xS + nextL, yS + nextL, nextL);
	}

}

int main()
{
	
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> pArray[i][j];

	run(0, 0, N);
	cout << whiteCount << "\n" << blueCount;

	return 0;
}